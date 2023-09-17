clc, clear
% 랜덤 5x5 행렬을 만듭니다.
A = rand(5);

% 반복 횟수는 100번 tolerance = 0.0001 로 둡니다.
iteration = 100;
tol = 0.0001;

% 행렬에 실수의 고유값이 존재하는지 확인합니다.
% 만약 존재하지 않는다면 임의의 행렬 A를 조건을 만족할 때까지 불러옵니다.
while ~isreal(eig(A)) || length(unique(eig(A))) ~= 5
    A = rand(5);
end

% 벡터 x는 다음과 같이 정의한 후 normalizing 합니다..
x = [1 1 1 1 1]';
x = x / norm(x);

% 각각의 method에 사용할 벡터 x를 저장합니다.
x_basic = x;
x_inverse = x;
x_shifted = x;
% 3개의 고유벡터를 저장할 리스트를 초기화.
shifted = 1:3;
          
% basic method
for i = 1: iteration
    % 허용 오차 값을 비교하기 위해서 따로 저장합니다.
    x_basic_old = x_basic;
    %임의의 행렬 A에 벡터 x_basic를 곱해 5x1 벡터로 바꿉니다.
    x_basic = A*x_basic;
    % 3x1 형태의 벡터중 가장 크기가 큰 값을 저장합니다. 
    eig_basic = max(abs(x_basic));  
    % x_basic 벡터를 자신의 성분 중 크기가 가장 큰 값으로 나눈다.
    x_basic = x_basic/eig_basic;
    
    % x_basic 벡터를 이용해 고유값에 가장 근사한 값을 구한다.                                                                                                  
    EV_basic = ((A*x_basic)'*x_basic)/(x_basic'*x_basic);
    
    % 연속적인 고유 벡터 차이의 성분 중 크기가 가장 큰 값이 tolerance 미만이면 종료합니다.
    if max(abs(x_basic - x_basic_old)) < tol
        break
    end
end

%고유값을 소수점 아래 4값으로 고정합니다.
EV_basic = round(EV_basic,4);
% 고유 벡터 normalizing
eigenvector_basic = x_basic ./ norm(x_basic);

% inverse method
for i = 1:iteration
    % 허용 오차 값을 비교하기 위해서 따로 저장합니다.
    x_inverse_old = x_inverse;
    % x_inverse 벡터를 normalizing 해줍니다.
    x_inverse = x_inverse ./ norm(x_inverse);
    %임의의 행렬 A의 역벡터에 x_inverse를 곱해 5x1 벡터로 바꿉니다.
    x_inverse = inv(A)*x_inverse;
    % x_inverse 벡터를 자신의 성분 중 가장 큰 값으로 나눕니다. 
    x_inverse = x_inverse/max(abs(x_inverse));
    
    % x_inverse 벡터를 이용해 고유값에 가장 근사한 값을 구합니다.
    EV_inverse = ((A*x_inverse)'*x_inverse)/(x_inverse'*x_inverse);
    
    x_inverse = x_inverse ./ norm(x_inverse);
    % 연속적인 고유 벡터 차이의 성분 중 크기가 가장 큰 값이 tolerance 미만이면 종료합니다.
    if max(abs(x_inverse - x_inverse_old)) < tol
        break
    end
end

% 고유 값을 소수점 아래 4 까지 저장합니다.
EV_inverse = round(EV_inverse,4);
% 고유벡터를 normalizing 합니다.
eigenvector_inverse = x_inverse ./ norm(x_inverse);

% the shifted power method 과정 중 범위 지정에 사용할 고유값 2개를
% a, b 에 저장합니다.
if (EV_basic > 0)
    a = -EV_basic; b = EV_basic;
else
    a = EV_basic; b= EV_basic;
end
    


cnt=1; % 3개의 고유 값과 고유벡터를 구하기 위한 cnt 입니다.
% 범위는 (+, -)EV_basic 값들의 사이다. EV_basic 이 가장 크기가 큰 값이기
% 때문에 고유 값들도 그 범위 안에 있기 때문에 설정합니다.
for j = a+0.0001: 0.15 : b-0.0001
    % A를 j 만큼 shift한 행렬 B 입니다.
    if (abs(EV_inverse) >= abs(j)) && (0 <= abs(j)) 
        j = abs(EV_inverse)+0.1;
    end
    B = A - j*eye(5);
    
    % shifted method
    for i = 1:iteration
        x_shifted_old = x_shifted;
        % x_shifted 벡터에 inv(B)를 곱한 5x1 벡터입니다.
        x_shifted = inv(B)*x_shifted;
        % x_shifted 벡터를 자신의 성분 중 가장 큰 값으로 나눕니다.
        x_shifted = x_shifted/max(abs(x_shifted));
        x_shifted = x_shifted ./ norm(x_shifted);
        
        % 고유값에 가장 근사한 값을 구합니다.
        EV_shifted = ((A*x_shifted)'*x_shifted)/(x_shifted'*x_shifted);
        
        % 연속적인 고유 벡터 차이의 성분 중 크기가 가장 큰 값이 tolerance 미만이면 종료합니다.
        if max(abs(x_shifted - x_shifted_old)) < tol
            break
        end
    end
    
    % EV_shifted 값을 소수점 아래 4자리로 저장합니다.
    EV_shifted = round(EV_shifted,4);
    
    % 아래 조건문은 EV_basic과 EV_inverse 값이 각각 고유값의 절댓값중 가장 큰 값과 가장 작은 값이기 때문에 나머지 고유 값들은 그 사이의
    % 값으로 나타나기에 다음과 같이 작성했습니다.
    % 조건문을 만족하여 shifted power method로 만든 첫번째 고유값이 정해진다면, 두번째 고유값은 첫번째 고유값보다 큰 값이 나타나야 합니다.
    % 따라서, 이를 조건문에 넣어주는 방식으로 제작했습니다.
    % 단 크기가 같은 고유값이 나오거나 고유값 간의 차이가 매우 작은 범위가 나온다는 것을 가정하여 +-0.002 차이를 두어
    % 비교했습니다.
    if cnt == 1
        if ((abs(EV_shifted)) > (abs(EV_inverse)+0.002)) && (abs(EV_shifted) < (abs(EV_basic)-0.002))
            shifted(cnt) = EV_shifted;
            cnt = cnt+1;
            eigenvector_shifted_1 = x_shifted ./ norm(x_shifted);
        end
    elseif cnt == 2
        if ((abs(EV_shifted)) > (abs(EV_inverse)+0.002)) && (abs(EV_shifted) < (abs(EV_basic)-0.002)) && (EV_shifted > (shifted(1)+0.002))
            shifted(cnt) = EV_shifted;
            cnt=cnt+1;
            eigenvector_shifted_2 = x_shifted ./ norm(x_shifted);
        end
    else 
        if ((abs(EV_shifted)) > (abs(EV_inverse)+0.002)) && (abs(EV_shifted) < (abs(EV_basic)-0.002)) && (EV_shifted > (shifted(2)+0.002))
            shifted(cnt) = EV_shifted;
            eigenvector_shifted_3 = x_shifted ./ norm(x_shifted);
            break;
        end
    end
end

% 구한 eigenvalues 와 eigenbector 를 [inverse shifted(3개) basic] 으로 저장하고 출력합니다.
Y = [EV_inverse shifted EV_basic];
B = [eigenvector_inverse eigenvector_shifted_1 eigenvector_shifted_2 eigenvector_shifted_3 eigenvector_basic];
fprintf('matrix A :\n');
disp(A);
fprintf('eigenvalue =')
for i = 1:5
    fprintf(' %.4f', Y(i));
end
fprintf('\n');
fprintf('eigenvector :\n');
disp(B);