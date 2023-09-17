clc,clear
% the Solovay-Strassen test 반복 횟수
k = 100;
cnt = 1;


% 100개의 소수를 찾기 위해 반복시킨다.
while(cnt ~= 100)
    % 랜덤 숫자의 범위는 10,000,000 to 99,999,999
    n = randi([1000000000,9999999999]);
    
    % 숫자 n이 짝수가 나오면 안되기 때문에 반복시킨다.
    while mod(n,2) == 0
        n = randi([1000000000,9999999999]);
    end
    a = randi([1, n-1]); % Generate a random witness 'a'
    
    %gcd(a,n)이 1이 나와야 하기 때문에 반복시킨다.
    while gcd(a,n) ~= 1
        a = randi([1, n-1]);
    end

    % a, n에 대한 jacobiSymbol 계산한다.
    j = jacobiSymbol(a, n);

    % : 모듈식 지수 계산 : a^((n-1)/2) mod n
    e = modPower(a, (n-1)/2, n);
    
    % the Solovay-Strassen test를 k번 작동시킨다.
    if e == j
        for l = 1:k
            a = randi([1,n-1]);

            if modPower(a, (n-1)/2, n) ~= jacobiSymbol(a, n)
                break;
            end
        end
        fprintf('%d 은 소수이다.\n', n);
        cnt = cnt+1;
    end

end

fprintf('100번 반복하여 얻어낸 숫자이기에 Prime number가 아닐 가능성은 6.90 X 10e-29  입니다.');


% 'a'와 'n'의 Jacobi symbol를 계산한다.
function j = jacobiSymbol(a, n)
    j = 1;

    if a == 2
        j = j*two(n);
        return
    end
    
    while(1)
        if mod(a,2) == 0
            while(1)
                j = j*jacobiSymbol(2,n);
                a = a/2;
                if a == 1
                    return;
                end
                if mod(a, 2) ~= 0
                    break;
                end
                if a == 0
                    a = 2;
                end
            end
        end
        
        if (mod(a,2) == 1) && (mod(n,2) == 1) && (a ~= 0) && (n ~= 0)
            if a < n
                temp = a; a = n; n = temp;
                j = j*four(a,n);
            elseif a > n
                a = mod(a,n);
            end
        end
        if (a == 1) || (a == n)
            break
        end
    end
    return;
end

% jacobi symbol의 4번째 성질
function fo = four(a, n)
    if (mod(a, 4) + mod(n, 4)) == 6
        fo = -1;
        return;
    else
        fo = 1;
        return;
    end
end

% jacobi symbol의 2번째 성질
function to = two(n)
    if (mod(n,8) == 1) || (mod(n, 8) == 7)
        to = 1;
        return;
    elseif (mod(n,8) == 3) || (mod(n,8) == 5)
        to = -1;
        return;
    end
end

% 모듈러 지수를 메모리 낭비 없이 효율적으로 계산하는 함수이다.
% 모듈러 산술 연산이 분배 법칙이 성립한다는 것을 이용해
% 제곱형태를 쪼개어 계산한다.
function res = modPower(base, exponent, modulus)
    if exponent == 0
        res = 1;
        return;
    elseif mod(exponent, 2) == 0
        res = mod(modPower(base,exponent/2,modulus)^2, modulus);
        return;
    else
        res = mod(modPower(base,exponent-1,modulus),modulus);
        return
    end


end