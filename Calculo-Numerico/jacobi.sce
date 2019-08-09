clear;
clc;

A=[3, 0, 1; 1, -1, 0; 3, 1, 8];
b=[1;2;3];
x0=[1;1;1];
N = 10000;
TOL = 0.0000000001;


nlin= size(x0,1);
I= eye(A);
k = 1;
while(k <= N)
    x = -(A-I)*x0+b;
    if (norm(x-x0,'inf') < TOL) then
           break;
    end
    x0=x;
    k=k+1;
end

for i=1:nlin
    for j=1:1
        printf("%g\n", x(i,j));
    end
end
printf("K: %g", k);
