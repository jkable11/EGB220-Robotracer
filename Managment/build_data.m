function data = build_data(start, current, sprints)
    m=(current-start)/(sprints-1);
    c = start-(m);    
    %i=1;
    projected = -c/m;
    x=1:projected;
    y=(m.*x)+c;
    data=[x;y];
    xlswrite('Burndown.xlsx',data',2);
end