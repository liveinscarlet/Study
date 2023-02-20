%% logial AND
clear; clc
P = [0 0 1 1; 0 1 0 1];
T = [0 0 0 1];
ANDNet = [0 1; 0 1], 1;
Y0 = sim(ANDNet,P);
ANDNet.trainParam.epochs = 200;
net = train(ANDNet,P,T);
Y = sim(net,P)
%% logical OR
clear; clc
P = [0 0 1 1, 0 1 0 1];
T = [0 1 1 1];
ORNet = [0 1; 1 1], 1;
Y = sim(ORNet, P);
net.trainParam.epochs = 200;
net = train(ORNet,P,T);
Y = sim(ORNet,P)
%% logical XOR
clear; clc
P = [0 0 1 1; 0 1 0 1];
T = [0 1 1 0];
Y = net(P)
net.trainParam.epochs = 200;
net = train(net,P,T);
Y = net(P)