clear;
clc;

//A=[3, 0, 1; 1, -1, 0; 3, 1, 8];
//b=[1;2;3];
//x0=[1;1;1];

A= [4,1,-1,0,0,0,0,0;1,6,-2,1,-1,0,0,0;0,1,5,0,-1,0,0,0;0,2,0,5,-1,1,-1,-1;0,0,-1,-1,6,0,0,-1;0,0,-1,0,-1,-1,0,0;0,0,0,-1,0,5,4,-1;0,0,0,-1,-1,0,-1,5]
//b = [-6;-5;0;1;2;-12;-2;8]
b = [0;0;0;0;0;0;0;1]

x0=[1;1;1;1;1;1;1;1];

N = 10000;
TOL = 0.0000000001;

nlin=size(A,1);
U = zeros(nlin, nlin);
D = zeros(nlin, nlin);
L = zeros(nlin, nlin);

for i=1:nlin
    for j=1:nlin
        if(j==i) then
            D(i,j)=A(i,j);
        elseif (i>j) then
            L(i,j)=A(i,j);
        else
            U(i,j)=A(i,j);
        end
    end
end

k = 1;
while(k <= N)
    x = inv(L+D)*(b-(U*x0));
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
