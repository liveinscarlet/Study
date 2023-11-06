    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 5;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (rtP)
        ;%
            section.nData     = 39;
            section.data(39)  = dumData; %prealloc

                    ;% rtP.AWGNChannel_SNR
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.AWGNChannel_SignalPower
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.VariableTransportDelay1_MaxDelay
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.VariableTransportDelay1_InitOutput
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.Buffer1_ic
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.AnalogFilterDesign_A_pr
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.AnalogFilterDesign_B_pr
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 60;

                    ;% rtP.AnalogFilterDesign_C_pr
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 65;

                    ;% rtP.AnalogFilterDesign_D_pr
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 75;

                    ;% rtP.AnalogFilterDesign_InitialCondition
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 76;

                    ;% rtP.Buffer3_ic
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 77;

                    ;% rtP.Constant4_Value
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 78;

                    ;% rtP.Gain_Gain
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 79;

                    ;% rtP.VariableTransportDelay_MaxDelay
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 80;

                    ;% rtP.VariableTransportDelay_InitOutput
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 81;

                    ;% rtP.PulseGenerator1_Amp
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 82;

                    ;% rtP.PulseGenerator1_Period
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 83;

                    ;% rtP.PulseGenerator1_Duty
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 84;

                    ;% rtP.PulseGenerator1_PhaseDelay
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 85;

                    ;% rtP.DiscreteTimeIntegrator1_gainval
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 86;

                    ;% rtP.DiscreteTimeIntegrator1_IC
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 87;

                    ;% rtP.DiscreteTimeIntegrator2_gainval
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 88;

                    ;% rtP.DiscreteTimeIntegrator2_IC
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 89;

                    ;% rtP.DiscreteTimeIntegrator5_gainval
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 90;

                    ;% rtP.DiscreteTimeIntegrator5_IC
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 91;

                    ;% rtP.DiscreteTimeIntegrator6_gainval
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 92;

                    ;% rtP.DiscreteTimeIntegrator6_IC
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 93;

                    ;% rtP.Constant3_Value
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 94;

                    ;% rtP.DiscreteTimeIntegrator3_gainval
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 95;

                    ;% rtP.DiscreteTimeIntegrator3_IC
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 96;

                    ;% rtP.DiscreteTimeIntegrator4_gainval
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 97;

                    ;% rtP.DiscreteTimeIntegrator4_IC
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 98;

                    ;% rtP.DiscreteTimeIntegrator_gainval
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 99;

                    ;% rtP.Constant3_Value_naltalopjl
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 100;

                    ;% rtP.Gain_Gain_donlcyw5bh
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 101;

                    ;% rtP.Gain1_Gain
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 102;

                    ;% rtP.Constant1_Value
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 103;

                    ;% rtP.Constant_Value
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 104;

                    ;% rtP.Constant2_Value
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 105;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% rtP.Gain_Gain_c0wzfxwapi
                    section.data(1).logicalSrcIdx = 39;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.Bias_Bias
                    section.data(2).logicalSrcIdx = 40;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.Gain1_Gain_jhwyhxq2zq
                    section.data(3).logicalSrcIdx = 41;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.Gain_Gain_hnwxniojmd
                    section.data(4).logicalSrcIdx = 42;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.Bias_Bias_fafg04n1yq
                    section.data(5).logicalSrcIdx = 43;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.Gain1_Gain_lhfiaw3lod
                    section.data(6).logicalSrcIdx = 44;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% rtP.AnalogFilterDesign_A_ir
                    section.data(1).logicalSrcIdx = 45;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.AnalogFilterDesign_A_jc
                    section.data(2).logicalSrcIdx = 46;
                    section.data(2).dtTransOffset = 55;

                    ;% rtP.AnalogFilterDesign_B_ir
                    section.data(3).logicalSrcIdx = 47;
                    section.data(3).dtTransOffset = 76;

                    ;% rtP.AnalogFilterDesign_B_jc
                    section.data(4).logicalSrcIdx = 48;
                    section.data(4).dtTransOffset = 81;

                    ;% rtP.AnalogFilterDesign_C_ir
                    section.data(5).logicalSrcIdx = 49;
                    section.data(5).dtTransOffset = 83;

                    ;% rtP.AnalogFilterDesign_C_jc
                    section.data(6).logicalSrcIdx = 50;
                    section.data(6).dtTransOffset = 93;

                    ;% rtP.AnalogFilterDesign_D_ir
                    section.data(7).logicalSrcIdx = 51;
                    section.data(7).dtTransOffset = 114;

                    ;% rtP.AnalogFilterDesign_D_jc
                    section.data(8).logicalSrcIdx = 52;
                    section.data(8).dtTransOffset = 115;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.CombinatorialLogic_table
                    section.data(1).logicalSrcIdx = 53;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.DiscreteTimeIntegrator_IC
                    section.data(1).logicalSrcIdx = 54;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 3;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (rtB)
        ;%
            section.nData     = 33;
            section.data(33)  = dumData; %prealloc

                    ;% rtB.oiagjxsfua
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.ptxjsacnuh
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.aeq5ruscfh
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.pnfujicrav
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtB.fo3o0qx3rk
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtB.h00tanbm5k
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtB.abu2iacvsb
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtB.hcqcgye2fg
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% rtB.jx13nwj10i
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% rtB.i50ghe5lm1
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% rtB.nym1g1yulh
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% rtB.eue4pzm2um
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% rtB.nxismlfsz2
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% rtB.nbzdbx43y2
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% rtB.cskkp1pbit
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

                    ;% rtB.ekkv4odda4
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 15;

                    ;% rtB.he1lzb12tu
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 16;

                    ;% rtB.bunz1k115f
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 17;

                    ;% rtB.i5jmft20v3
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 18;

                    ;% rtB.c1hzatsvvq
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 19;

                    ;% rtB.ahaloitnql
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 20;

                    ;% rtB.cqncnt5j3w
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 21;

                    ;% rtB.et3ss0ypwk
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 22;

                    ;% rtB.p3kz0eppb3
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 23;

                    ;% rtB.eatzl3wsw1
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 24;

                    ;% rtB.lydxvhyrns
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 25;

                    ;% rtB.f2shyu0rcb
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 26;

                    ;% rtB.lrjqprgrv3
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 27;

                    ;% rtB.ka0zgragyp
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 28;

                    ;% rtB.k42ztcl2nd
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 29;

                    ;% rtB.gzm3dlplwu
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 30;

                    ;% rtB.mh3qnuillk
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 31;

                    ;% rtB.cns4fjew02
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 32;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.iaqfq2eapm
                    section.data(1).logicalSrcIdx = 33;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.aes5bhgd15
                    section.data(1).logicalSrcIdx = 34;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 12;
        sectIdxOffset = 3;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (rtDW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.b2pi4gudhv
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 14;
            section.data(14)  = dumData; %prealloc

                    ;% rtDW.khu2zdxbs4
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.degrhjleyo
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 5110;

                    ;% rtDW.iifnymjse2
                    section.data(3).logicalSrcIdx = 3;
                    section.data(3).dtTransOffset = 10220;

                    ;% rtDW.ecfe4qopis
                    section.data(4).logicalSrcIdx = 4;
                    section.data(4).dtTransOffset = 10221;

                    ;% rtDW.hqdcazynvm
                    section.data(5).logicalSrcIdx = 5;
                    section.data(5).dtTransOffset = 10222;

                    ;% rtDW.n4yx1rctfr
                    section.data(6).logicalSrcIdx = 6;
                    section.data(6).dtTransOffset = 10223;

                    ;% rtDW.petkjqwhb5
                    section.data(7).logicalSrcIdx = 7;
                    section.data(7).dtTransOffset = 10224;

                    ;% rtDW.icjheye5eq
                    section.data(8).logicalSrcIdx = 8;
                    section.data(8).dtTransOffset = 10225;

                    ;% rtDW.ow0o42gfhu
                    section.data(9).logicalSrcIdx = 9;
                    section.data(9).dtTransOffset = 10226;

                    ;% rtDW.i1izcj3aqn
                    section.data(10).logicalSrcIdx = 10;
                    section.data(10).dtTransOffset = 10227;

                    ;% rtDW.crayuk1lir
                    section.data(11).logicalSrcIdx = 11;
                    section.data(11).dtTransOffset = 10228;

                    ;% rtDW.ltl5bvjttg
                    section.data(12).logicalSrcIdx = 12;
                    section.data(12).dtTransOffset = 10229;

                    ;% rtDW.dyxjcdc4bi
                    section.data(13).logicalSrcIdx = 13;
                    section.data(13).dtTransOffset = 10230;

                    ;% rtDW.bobq1qesgz
                    section.data(14).logicalSrcIdx = 14;
                    section.data(14).dtTransOffset = 10231;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.om2ho3dulj
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtDW.mvgx1jbk50.modelTStart
                    section.data(1).logicalSrcIdx = 16;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.mskfm2nwhx.modelTStart
                    section.data(2).logicalSrcIdx = 17;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtDW.bo3muh5enu.TUbufferPtrs
                    section.data(1).logicalSrcIdx = 18;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.mrxxjsj4ey.TUbufferPtrs
                    section.data(2).logicalSrcIdx = 19;
                    section.data(2).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% rtDW.ezlg5otozk
                    section.data(1).logicalSrcIdx = 20;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.heqq1kpetm
                    section.data(2).logicalSrcIdx = 21;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.ee5qp1cpiz
                    section.data(3).logicalSrcIdx = 22;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.mjvxwfupof
                    section.data(4).logicalSrcIdx = 23;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.brknn13uxf
                    section.data(5).logicalSrcIdx = 24;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.g5lav3j02c
                    section.data(6).logicalSrcIdx = 25;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.cgru1gwg0r
                    section.data(7).logicalSrcIdx = 26;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.hrj4u4frdf
                    section.data(8).logicalSrcIdx = 27;
                    section.data(8).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% rtDW.iqp54sidls
                    section.data(1).logicalSrcIdx = 28;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.g0ulyhynln
                    section.data(2).logicalSrcIdx = 29;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.jken4w0gjf
                    section.data(3).logicalSrcIdx = 30;
                    section.data(3).dtTransOffset = 626;

                    ;% rtDW.jx3alr4qwb
                    section.data(4).logicalSrcIdx = 31;
                    section.data(4).dtTransOffset = 628;

                    ;% rtDW.m14sbehec2
                    section.data(5).logicalSrcIdx = 32;
                    section.data(5).dtTransOffset = 629;

                    ;% rtDW.f2oac5wnal
                    section.data(6).logicalSrcIdx = 33;
                    section.data(6).dtTransOffset = 630;

                    ;% rtDW.jdgjatsyrt
                    section.data(7).logicalSrcIdx = 34;
                    section.data(7).dtTransOffset = 631;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtDW.gttvq41aan.Tail
                    section.data(1).logicalSrcIdx = 35;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.cazujz0icx.Tail
                    section.data(2).logicalSrcIdx = 36;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% rtDW.nxrgsy2c2w
                    section.data(1).logicalSrcIdx = 37;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.opvzyiyp3j
                    section.data(2).logicalSrcIdx = 38;
                    section.data(2).dtTransOffset = 9;

                    ;% rtDW.adldhalszk
                    section.data(3).logicalSrcIdx = 39;
                    section.data(3).dtTransOffset = 18;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% rtDW.ngrrkreo2f
                    section.data(1).logicalSrcIdx = 40;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.enivbnqm2z
                    section.data(2).logicalSrcIdx = 41;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.bu5tr1pdox
                    section.data(3).logicalSrcIdx = 42;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.ma50gapxoa
                    section.data(4).logicalSrcIdx = 43;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.ornpy4cdl1
                    section.data(5).logicalSrcIdx = 44;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.c0rsnhvxge
                    section.data(6).logicalSrcIdx = 45;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.imgxzfpyet
                    section.data(7).logicalSrcIdx = 46;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.hlh4o42oo3
                    section.data(8).logicalSrcIdx = 47;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.hr04pilmac
                    section.data(9).logicalSrcIdx = 48;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.ficexzqbh2
                    section.data(10).logicalSrcIdx = 49;
                    section.data(10).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% rtDW.agygzdruc0
                    section.data(1).logicalSrcIdx = 50;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.co4yicnm0d
                    section.data(2).logicalSrcIdx = 51;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.m1ai31i3so
                    section.data(3).logicalSrcIdx = 52;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.psbicvw1tn
                    section.data(4).logicalSrcIdx = 53;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.kko144v51w
                    section.data(5).logicalSrcIdx = 54;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.grbbrolnqo
                    section.data(6).logicalSrcIdx = 55;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            dworkMap.sections(11) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% rtDW.pemmcx3bjg
                    section.data(1).logicalSrcIdx = 56;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.acu0fobbd3
                    section.data(2).logicalSrcIdx = 57;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.kzklpmmpnf
                    section.data(3).logicalSrcIdx = 58;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.hdirjwpdhq
                    section.data(4).logicalSrcIdx = 59;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.dypy444pvq
                    section.data(5).logicalSrcIdx = 60;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.hp4k1chfue
                    section.data(6).logicalSrcIdx = 61;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.dc1nkzv5gn
                    section.data(7).logicalSrcIdx = 62;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.eshgyurwuf
                    section.data(8).logicalSrcIdx = 63;
                    section.data(8).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            dworkMap.sections(12) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 2059667716;
    targMap.checksum1 = 822817126;
    targMap.checksum2 = 3881375;
    targMap.checksum3 = 2437997414;

