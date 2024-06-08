    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
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
            section.nData     = 60;
            section.data(60)  = dumData; %prealloc

                    ;% rtP.I
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.K
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.L
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.R
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.Res
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.dl
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.m
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.t
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% rtP.WrapToZero_Threshold
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 29;

                    ;% rtP.WrapToZero_Threshold_hg0h5yir2s
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 30;

                    ;% rtP.WrapToZero_Threshold_cssuvfekcn
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 31;

                    ;% rtP.WrapToZero1_Threshold
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 32;

                    ;% rtP.OutputSamplePoints_Value
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 33;

                    ;% rtP.Integrator1_IC
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 235;

                    ;% rtP.Integrator2_IC
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 236;

                    ;% rtP.Integrator1_IC_exjymra1sd
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 237;

                    ;% rtP.Integrator_IC
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 238;

                    ;% rtP.PIdir2_A
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 239;

                    ;% rtP.PIdir2_C
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 240;

                    ;% rtP.PIdir1_A
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 241;

                    ;% rtP.PIdir1_C
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 242;

                    ;% rtP.PIdir_A
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 243;

                    ;% rtP.PIdir_C
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 244;

                    ;% rtP.PIdir_D
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 245;

                    ;% rtP.Saturation_UpperSat
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 246;

                    ;% rtP.Saturation_LowerSat
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 247;

                    ;% rtP.PIesq_A
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 248;

                    ;% rtP.PIesq_C
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 249;

                    ;% rtP.PIesq_D
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 250;

                    ;% rtP.Saturation1_UpperSat
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 251;

                    ;% rtP.Saturation1_LowerSat
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 252;

                    ;% rtP.Gain_Gain
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 253;

                    ;% rtP.Gain1_Gain
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 254;

                    ;% rtP.Integrator_IC_la12cpfo5s
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 255;

                    ;% rtP.Yp_Time0
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 256;

                    ;% rtP.Yp_Data0
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 278;

                    ;% rtP.Xp_Time0
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 300;

                    ;% rtP.Xp_Data0
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 322;

                    ;% rtP.Gain_Gain_ejiryrm5j4
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 344;

                    ;% rtP.Gain1_Gain_kooogsc14x
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 345;

                    ;% rtP.Step1_Y0
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 346;

                    ;% rtP.Step1_YFinal
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 347;

                    ;% rtP.Md2_Gain
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 348;

                    ;% rtP.Fsr_Gain
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 349;

                    ;% rtP.Fkr_Gain
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 350;

                    ;% rtP.Fsl_Gain
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 351;

                    ;% rtP.Fkl_Gain
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 352;

                    ;% rtP.Gain1_Gain_i3zbnwm4y2
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 353;

                    ;% rtP.Step1_Y0_j4y32wgs52
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 354;

                    ;% rtP.Step1_YFinal_a0sklnvnzc
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 355;

                    ;% rtP.Step2_Y0
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 356;

                    ;% rtP.Step2_YFinal
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 357;

                    ;% rtP.alphakR_Value
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 358;

                    ;% rtP.alphasR_Value
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 359;

                    ;% rtP.alphakL_Value
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 360;

                    ;% rtP.alphasL_Value
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 361;

                    ;% rtP.Constant_Value
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 362;

                    ;% rtP.Constant_Value_ebq3giya5y
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 363;

                    ;% rtP.Constant_Value_dtwdy0lnur
                    section.data(59).logicalSrcIdx = 58;
                    section.data(59).dtTransOffset = 364;

                    ;% rtP.Constant_Value_gwwlgndyuo
                    section.data(60).logicalSrcIdx = 59;
                    section.data(60).dtTransOffset = 365;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
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
        nTotSects     = 1;
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
            section.nData     = 25;
            section.data(25)  = dumData; %prealloc

                    ;% rtB.ha2gv25mhx
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.cdu4i3mgs3
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.npg2rgfpun
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.afgd0lhtf4
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtB.nm5omszfx3
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtB.itsvmyrkai
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtB.pg5kicv5em
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtB.oe2lmsiz2a
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% rtB.kogoh4ns5v
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% rtB.kbrqy5f52m
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% rtB.dsmoak2jsv
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% rtB.ksxfj0gsfv
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% rtB.h5uzudgb5w
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% rtB.fapvpqm3of
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% rtB.ii0yohmyk1
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

                    ;% rtB.gavabcvo5r
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 15;

                    ;% rtB.hv31qc3uzw
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 16;

                    ;% rtB.oevdxkeqby
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 17;

                    ;% rtB.pnt2f1gct3
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 18;

                    ;% rtB.pq2bv34fsb
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 19;

                    ;% rtB.etvmuhuczs
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 20;

                    ;% rtB.pavpjlcqba
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 21;

                    ;% rtB.p51nm1vilc
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 22;

                    ;% rtB.olhqar1g4d
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 23;

                    ;% rtB.e5b5c1xnq0
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 24;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
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
        nTotSects     = 7;
        sectIdxOffset = 1;

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
            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% rtDW.f5e2gopavh
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.lpx2pph21r
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.adtef5njec
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.khlsdoxige
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% rtDW.c3dr1neq03.LoggedData
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.oty2qpav4u.LoggedData
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.kvmiotlkfk.LoggedData
                    section.data(3).logicalSrcIdx = 6;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.d5hpzicwc5.LoggedData
                    section.data(4).logicalSrcIdx = 7;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.jaq2k3c0ms.LoggedData
                    section.data(5).logicalSrcIdx = 8;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.ithk2wjz3d.LoggedData
                    section.data(6).logicalSrcIdx = 9;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.me34h4u1wh.LoggedData
                    section.data(7).logicalSrcIdx = 10;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.c3wmjp50zt.TimePtr
                    section.data(8).logicalSrcIdx = 11;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.p0h3tkrxan.TimePtr
                    section.data(9).logicalSrcIdx = 12;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.n0epb32tf2.LoggedData
                    section.data(10).logicalSrcIdx = 13;
                    section.data(10).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% rtDW.lju2musbk0
                    section.data(1).logicalSrcIdx = 14;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.dpg2qc3x1y
                    section.data(2).logicalSrcIdx = 15;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.hfmnviw2hz
                    section.data(3).logicalSrcIdx = 16;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% rtDW.hs5jgacqs1.PrevIndex
                    section.data(1).logicalSrcIdx = 17;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.denj1jmxfa.PrevIndex
                    section.data(2).logicalSrcIdx = 18;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.hobxq1jfh4
                    section.data(3).logicalSrcIdx = 19;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.hxoxcp0gyq
                    section.data(4).logicalSrcIdx = 20;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.hfipyfd2hy
                    section.data(5).logicalSrcIdx = 21;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.huwtgpmegi
                    section.data(6).logicalSrcIdx = 22;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.ml4tiyctab
                    section.data(7).logicalSrcIdx = 23;
                    section.data(7).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.djpwfvqboz
                    section.data(1).logicalSrcIdx = 24;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% rtDW.de1hz3dcad
                    section.data(1).logicalSrcIdx = 25;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.bgdd3ewqlm
                    section.data(2).logicalSrcIdx = 26;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.maa5oi5ny5
                    section.data(3).logicalSrcIdx = 27;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% rtDW.garatixfd3
                    section.data(1).logicalSrcIdx = 28;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.knd1gqgkyt
                    section.data(2).logicalSrcIdx = 29;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.olcxu21tfo
                    section.data(3).logicalSrcIdx = 30;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
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


    targMap.checksum0 = 1252585181;
    targMap.checksum1 = 2528956502;
    targMap.checksum2 = 3251025582;
    targMap.checksum3 = 418537064;

