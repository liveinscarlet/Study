%% logial AND
clear
P = [0 0 1 1; 0 1 0 1];
T = [0 0 0 1];
ANDNet = newp([0 1; 0 1], 1);
Y0 = sim(ANDNet,P);
ANDNet.trainParam.epochs = 200;
net = train(ANDNet,P,T);
Y = sim(net,P)
%% logical OR
P = [0 0 1 1; 0 1 0 1];
T = [0 1 1 1];
Y = net(P)
net.trainParam.epochs = 20;
net = train(net,P,T);
Y = net(P)
%% logical XOR
P = [0 0 1 1; 0 1 0 1];
T = [0 1 1 0];
Y = net(P)
net.trainParam.epochs = 200;
net = train(net,P,T);
Y = net(P)