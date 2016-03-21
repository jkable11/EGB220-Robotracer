function data = build_data()
    sprints = 4; %number of sprints
    start = xlsread('Burndown.xlsx', 1, 'B2');%Total time
    current = xlsread('Burndown.xlsx', 1, 'B4');%Time left
    m=(current-start)/(sprints-1);%gradient
    c = start-(m);%intercept
    projected = -c/m;%number of projected sprints
    x=1:projected;
    y=(m.*x)+c;
    data=[x;y];
    xlswrite('Burndown.xlsx',data',2);%write series to excel
end