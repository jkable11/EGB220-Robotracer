function data = build_data_test()
    sprints = 4; %number of sprints
    start = xlsread('Burndown.xlsx', 1, 'B2');
    current = xlsread('Burndown.xlsx', 1, 'B4');
    m=(current-start)/(sprints-1);
    c = start-(m);
    projected = -c/m;
    x=1:projected;
    y=(m.*x)+c;
    data=[x;y];
    xlswrite('Burndown.xlsx',data',2);
end