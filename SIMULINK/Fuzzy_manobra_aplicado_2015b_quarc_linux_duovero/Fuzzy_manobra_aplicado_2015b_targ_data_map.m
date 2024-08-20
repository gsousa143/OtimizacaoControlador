  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
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
    ;% Auto data (Fuzzy_manobra_aplicado_2015b_P)
    ;%
      section.nData     = 48;
      section.data(48)  = dumData; %prealloc
      
	  ;% Fuzzy_manobra_aplicado_2015b_P.L
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.N_sp
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.R
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.k_i
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.k_p
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.setpoints
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.MP_a
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 51;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.G_a
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 52;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.MP_b
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 53;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.G_b
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 54;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.MP_c
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 55;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.G_c
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 56;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.CompareToConstant_const
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 57;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.MP_d
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 58;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.G_d
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 59;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.BiasRemoval_end_time
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 60;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.HILInitialize_final_other_outpu
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 61;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.HILInitialize_final_pwm_outputs
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 64;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.SecondOrderLowPassFilter2_input
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 65;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.SecondOrderLowPassFilter2_inp_b
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 66;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.SecondOrderLowPassFilter2_inp_p
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 67;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.SecondOrderLowPassFilter2_inp_f
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 68;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.EN_mu
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 69;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.GN_mu
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 70;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.MN_mu
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 71;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Z_mu
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 72;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.MP_mu
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 73;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.GP_mu
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 74;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.EP_mu
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 75;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.PNF_mu
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 76;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.PPF_mu
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 77;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.PNR_mu
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 78;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.PPR_mu
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 79;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.HILInitialize_set_other_outputs
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 80;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.HILInitialize_set_other_outpu_m
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 81;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.EN_sigma
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 82;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.GN_sigma
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 83;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.MN_sigma
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 84;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Z_sigma
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 85;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.MP_sigma
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 86;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.GP_sigma
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 87;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.EP_sigma
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 88;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.PNF_sigma
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 89;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.PPF_sigma
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 90;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.PNR_sigma
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 91;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.PPR_sigma
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 92;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.BiasRemoval_start_time
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 93;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.BiasRemoval_switch_id
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 94;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Fuzzy_manobra_aplicado_2015b_P.HILRead1_analog_channels
	  section.data(1).logicalSrcIdx = 48;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.HILRead1_digital_channels
	  section.data(2).logicalSrcIdx = 49;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.HILRead1_encoder_channels
	  section.data(3).logicalSrcIdx = 50;
	  section.data(3).dtTransOffset = 4;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.HILRead1_other_channels
	  section.data(4).logicalSrcIdx = 51;
	  section.data(4).dtTransOffset = 6;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.HILWrite_other_channels
	  section.data(5).logicalSrcIdx = 52;
	  section.data(5).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% Fuzzy_manobra_aplicado_2015b_P.HILInitialize_active
	  section.data(1).logicalSrcIdx = 53;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.HILInitialize_final_digital_out
	  section.data(2).logicalSrcIdx = 54;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.HILInitialize_set_analog_output
	  section.data(3).logicalSrcIdx = 55;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.HILInitialize_set_analog_outp_f
	  section.data(4).logicalSrcIdx = 56;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.HILInitialize_set_digital_outpu
	  section.data(5).logicalSrcIdx = 57;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.HILInitialize_set_digital_out_f
	  section.data(6).logicalSrcIdx = 58;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.HILInitialize_set_pwm_outputs_a
	  section.data(7).logicalSrcIdx = 59;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.HILInitialize_set_pwm_output_ah
	  section.data(8).logicalSrcIdx = 60;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 83;
      section.data(83)  = dumData; %prealloc
      
	  ;% Fuzzy_manobra_aplicado_2015b_P.Out1_Y0
	  section.data(1).logicalSrcIdx = 61;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.One_Value
	  section.data(2).logicalSrcIdx = 62;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Out1_Y0_j
	  section.data(3).logicalSrcIdx = 63;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.One_Value_m
	  section.data(4).logicalSrcIdx = 64;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Out1_Y0_p
	  section.data(5).logicalSrcIdx = 65;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.u_Value
	  section.data(6).logicalSrcIdx = 66;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Out1_Y0_l
	  section.data(7).logicalSrcIdx = 67;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.u_Value_g
	  section.data(8).logicalSrcIdx = 68;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Out1_Y0_d
	  section.data(9).logicalSrcIdx = 69;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.u_Value_p
	  section.data(10).logicalSrcIdx = 70;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Out1_Y0_i
	  section.data(11).logicalSrcIdx = 71;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.u_Value_h
	  section.data(12).logicalSrcIdx = 72;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.unity_Value
	  section.data(13).logicalSrcIdx = 73;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.UnitDelay_InitialCondition
	  section.data(14).logicalSrcIdx = 74;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Sumk1n1xk_InitialCondition
	  section.data(15).logicalSrcIdx = 75;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.zero_Y0
	  section.data(16).logicalSrcIdx = 76;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Constant_Value
	  section.data(17).logicalSrcIdx = 77;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Vbiased_Y0
	  section.data(18).logicalSrcIdx = 78;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Vunbiased_Y0
	  section.data(19).logicalSrcIdx = 79;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Stepstart_time_Y0
	  section.data(20).logicalSrcIdx = 80;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Stepstart_time_YFinal
	  section.data(21).logicalSrcIdx = 81;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Stepend_time_Y0
	  section.data(22).logicalSrcIdx = 82;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Stepend_time_YFinal
	  section.data(23).logicalSrcIdx = 83;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Integrator3_IC
	  section.data(24).logicalSrcIdx = 84;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Integrator1_IC
	  section.data(25).logicalSrcIdx = 85;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Integrator2_IC
	  section.data(26).logicalSrcIdx = 86;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.xdata_Value
	  section.data(27).logicalSrcIdx = 87;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Weight_Value
	  section.data(28).logicalSrcIdx = 88;
	  section.data(28).dtTransOffset = 127;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.UnitDelay_InitialCondition_d
	  section.data(29).logicalSrcIdx = 89;
	  section.data(29).dtTransOffset = 128;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.P_Value
	  section.data(30).logicalSrcIdx = 90;
	  section.data(30).dtTransOffset = 129;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.N_Value
	  section.data(31).logicalSrcIdx = 91;
	  section.data(31).dtTransOffset = 230;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Weight_Value_h
	  section.data(32).logicalSrcIdx = 92;
	  section.data(32).dtTransOffset = 331;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Gain_Gain
	  section.data(33).logicalSrcIdx = 93;
	  section.data(33).dtTransOffset = 332;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Gain1_Gain
	  section.data(34).logicalSrcIdx = 94;
	  section.data(34).dtTransOffset = 333;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Gain_Gain_l
	  section.data(35).logicalSrcIdx = 95;
	  section.data(35).dtTransOffset = 334;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.R_Value
	  section.data(36).logicalSrcIdx = 96;
	  section.data(36).dtTransOffset = 335;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Weight_Value_g
	  section.data(37).logicalSrcIdx = 97;
	  section.data(37).dtTransOffset = 436;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Gain_Gain_c
	  section.data(38).logicalSrcIdx = 98;
	  section.data(38).dtTransOffset = 437;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.AH_Value
	  section.data(39).logicalSrcIdx = 99;
	  section.data(39).dtTransOffset = 438;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Weight_Value_n
	  section.data(40).logicalSrcIdx = 100;
	  section.data(40).dtTransOffset = 539;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Gain_Gain_k
	  section.data(41).logicalSrcIdx = 101;
	  section.data(41).dtTransOffset = 540;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.H_Value
	  section.data(42).logicalSrcIdx = 102;
	  section.data(42).dtTransOffset = 541;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Weight_Value_p
	  section.data(43).logicalSrcIdx = 103;
	  section.data(43).dtTransOffset = 642;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Gain_Gain_a
	  section.data(44).logicalSrcIdx = 104;
	  section.data(44).dtTransOffset = 643;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.F_Value
	  section.data(45).logicalSrcIdx = 105;
	  section.data(45).dtTransOffset = 644;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Weight_Value_nc
	  section.data(46).logicalSrcIdx = 106;
	  section.data(46).dtTransOffset = 745;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Gain_Gain_e
	  section.data(47).logicalSrcIdx = 107;
	  section.data(47).dtTransOffset = 746;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Weight_Value_e
	  section.data(48).logicalSrcIdx = 108;
	  section.data(48).dtTransOffset = 747;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Gain_Gain_o
	  section.data(49).logicalSrcIdx = 109;
	  section.data(49).dtTransOffset = 748;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Weight_Value_k
	  section.data(50).logicalSrcIdx = 110;
	  section.data(50).dtTransOffset = 749;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Gain_Gain_eg
	  section.data(51).logicalSrcIdx = 111;
	  section.data(51).dtTransOffset = 750;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Weight_Value_a
	  section.data(52).logicalSrcIdx = 112;
	  section.data(52).dtTransOffset = 751;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Gain_Gain_b
	  section.data(53).logicalSrcIdx = 113;
	  section.data(53).dtTransOffset = 752;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.MF_Value
	  section.data(54).logicalSrcIdx = 114;
	  section.data(54).dtTransOffset = 753;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Weight_Value_ec
	  section.data(55).logicalSrcIdx = 115;
	  section.data(55).dtTransOffset = 854;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Gain_Gain_d
	  section.data(56).logicalSrcIdx = 116;
	  section.data(56).dtTransOffset = 855;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Weight_Value_l
	  section.data(57).logicalSrcIdx = 117;
	  section.data(57).dtTransOffset = 856;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Gain_Gain_p
	  section.data(58).logicalSrcIdx = 118;
	  section.data(58).dtTransOffset = 857;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.MR_Value
	  section.data(59).logicalSrcIdx = 119;
	  section.data(59).dtTransOffset = 858;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Weight_Value_ez
	  section.data(60).logicalSrcIdx = 120;
	  section.data(60).dtTransOffset = 959;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Gain_Gain_kj
	  section.data(61).logicalSrcIdx = 121;
	  section.data(61).dtTransOffset = 960;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.xdata_Value_k
	  section.data(62).logicalSrcIdx = 122;
	  section.data(62).dtTransOffset = 961;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Zero_Value
	  section.data(63).logicalSrcIdx = 123;
	  section.data(63).dtTransOffset = 1062;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.MidRange_Value
	  section.data(64).logicalSrcIdx = 124;
	  section.data(64).dtTransOffset = 1063;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Switch_Threshold
	  section.data(65).logicalSrcIdx = 125;
	  section.data(65).dtTransOffset = 1065;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Integrator2_IC_l
	  section.data(66).logicalSrcIdx = 126;
	  section.data(66).dtTransOffset = 1066;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Integrator4_IC
	  section.data(67).logicalSrcIdx = 127;
	  section.data(67).dtTransOffset = 1067;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Integrator5_IC
	  section.data(68).logicalSrcIdx = 128;
	  section.data(68).dtTransOffset = 1068;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.sat2_UpperSat
	  section.data(69).logicalSrcIdx = 129;
	  section.data(69).dtTransOffset = 1069;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.sat2_LowerSat
	  section.data(70).logicalSrcIdx = 130;
	  section.data(70).dtTransOffset = 1070;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Integrator2_IC_b
	  section.data(71).logicalSrcIdx = 131;
	  section.data(71).dtTransOffset = 1071;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.sat1_UpperSat
	  section.data(72).logicalSrcIdx = 132;
	  section.data(72).dtTransOffset = 1072;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.sat1_LowerSat
	  section.data(73).logicalSrcIdx = 133;
	  section.data(73).dtTransOffset = 1073;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.tickstoencoderrotation_Gain
	  section.data(74).logicalSrcIdx = 134;
	  section.data(74).dtTransOffset = 1074;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.encoderrotationtowheelrotationg
	  section.data(75).logicalSrcIdx = 135;
	  section.data(75).dtTransOffset = 1075;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Constant_Value_n
	  section.data(76).logicalSrcIdx = 136;
	  section.data(76).dtTransOffset = 1076;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.x0_Value
	  section.data(77).logicalSrcIdx = 137;
	  section.data(77).dtTransOffset = 1077;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.tickstoencoderrotation_Gain_a
	  section.data(78).logicalSrcIdx = 138;
	  section.data(78).dtTransOffset = 1078;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.encoderrotationtowheelrotatio_i
	  section.data(79).logicalSrcIdx = 139;
	  section.data(79).dtTransOffset = 1079;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Constant_Value_p
	  section.data(80).logicalSrcIdx = 140;
	  section.data(80).dtTransOffset = 1080;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.x0_Value_p
	  section.data(81).logicalSrcIdx = 141;
	  section.data(81).dtTransOffset = 1081;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.Integrator_IC
	  section.data(82).logicalSrcIdx = 142;
	  section.data(82).dtTransOffset = 1082;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.FixPtConstant_Value
	  section.data(83).logicalSrcIdx = 143;
	  section.data(83).dtTransOffset = 1083;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Fuzzy_manobra_aplicado_2015b_P.sw5_CurrentSetting
	  section.data(1).logicalSrcIdx = 144;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Fuzzy_manobra_aplicado_2015b_P.HILRead1_Active
	  section.data(1).logicalSrcIdx = 145;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Fuzzy_manobra_aplicado_2015b_P.HILWrite_Active
	  section.data(2).logicalSrcIdx = 146;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
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
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Fuzzy_manobra_aplicado_2015b_B)
    ;%
      section.nData     = 41;
      section.data(41)  = dumData; %prealloc
      
	  ;% Fuzzy_manobra_aplicado_2015b_B.Integrator3
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.Integrator1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.Integrator2
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.UnitDelay
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.Merge
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.TrigonometricFunction1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.Product
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.Merge_k
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.Merge_j
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.Merge_jt
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.DataTypeConversion
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.Product_c
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.Product1
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.wheelradiousm
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.Integrator4
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.Integrator5
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.ErrovR
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.sat2
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.Product1_f
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.Product1_k
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.wheelradiousmm1
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.ErrovL
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.sat1
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.encoderrotationtowheelrotationg
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.x0
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.Product_a
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.encoderrotationtowheelrotatio_f
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.x0_b
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.Product_k
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.FixPtSum1
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.Switch
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.x_sp
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.y_sp
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.VVavg
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.Vin
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.Constant
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 35;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.div
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 36;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.x_dot
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 37;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.y_dot
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 38;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.psi_dot
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 39;
	
	  ;% Fuzzy_manobra_aplicado_2015b_B.Omega
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 40;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Fuzzy_manobra_aplicado_2015b_B.IfActionSubsystem3.dc
	  section.data(1).logicalSrcIdx = 41;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Fuzzy_manobra_aplicado_2015b_B.IfActionSubsystem1.ba
	  section.data(1).logicalSrcIdx = 42;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Fuzzy_manobra_aplicado_2015b_B.IfActionSubsystem3_m.dc
	  section.data(1).logicalSrcIdx = 43;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Fuzzy_manobra_aplicado_2015b_B.IfActionSubsystem1_i.ba
	  section.data(1).logicalSrcIdx = 44;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
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
    nTotSects     = 13;
    sectIdxOffset = 5;
    
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
    ;% Auto data (Fuzzy_manobra_aplicado_2015b_DW)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Fuzzy_manobra_aplicado_2015b_DW.UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.UnitDelay_DSTATE_p
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.Sumk1n1xk_DSTATE
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_POValues
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.HILWrite_OtherBuffer
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% Fuzzy_manobra_aplicado_2015b_DW.Thetarobo_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.Xrobo_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.Yrobo_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.HILRead1_PWORK
	  section.data(4).logicalSrcIdx = 9;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.ud_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 10;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.ud1_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 11;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.ud2_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 12;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.ud3_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 13;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.ud4_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 14;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.ud5_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 15;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.ue_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 16;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.ue1_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 17;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.x_sp_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 18;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.y_sp_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 19;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.HILWrite_PWORK
	  section.data(15).logicalSrcIdx = 20;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.d_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 21;
	  section.data(16).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Fuzzy_manobra_aplicado_2015b_DW.HILRead1_EncoderBuffer
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Fuzzy_manobra_aplicado_2015b_DW.Integrator1_IWORK
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.Integrator1_IWORK_j
	  section.data(2).logicalSrcIdx = 24;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% Fuzzy_manobra_aplicado_2015b_DW.If_ActiveSubsystem
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem_SubsysRanBC
	  section.data(2).logicalSrcIdx = 26;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem2_SubsysRanBC
	  section.data(3).logicalSrcIdx = 27;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.If_ActiveSubsystem_l
	  section.data(4).logicalSrcIdx = 28;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem_SubsysRanBC_m
	  section.data(5).logicalSrcIdx = 29;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem2_SubsysRanB_o
	  section.data(6).logicalSrcIdx = 30;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.If_ActiveSubsystem_a
	  section.data(7).logicalSrcIdx = 31;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.ActionOne_SubsysRanBC
	  section.data(8).logicalSrcIdx = 32;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.If_ActiveSubsystem_f
	  section.data(9).logicalSrcIdx = 33;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.ActionOne_SubsysRanBC_h
	  section.data(10).logicalSrcIdx = 34;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.EnabledMovingAverage_SubsysRanB
	  section.data(11).logicalSrcIdx = 35;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.SwitchCase_ActiveSubsystem
	  section.data(12).logicalSrcIdx = 36;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.SwitchCaseActionSubsystem_Subsy
	  section.data(13).logicalSrcIdx = 37;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.SwitchCaseActionSubsystem1_Subs
	  section.data(14).logicalSrcIdx = 38;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Fuzzy_manobra_aplicado_2015b_DW.SwitchCaseActionSubsystem2_Subs
	  section.data(15).logicalSrcIdx = 39;
	  section.data(15).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Fuzzy_manobra_aplicado_2015b_DW.EnabledMovingAverage_MODE
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem3.IfActionSubsystem3_SubsysRanBC
	  section.data(1).logicalSrcIdx = 41;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 42;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem3_m.IfActionSubsystem3_SubsysRanBC
	  section.data(1).logicalSrcIdx = 43;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem1_i.IfActionSubsystem1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 44;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Fuzzy_manobra_aplicado_2015b_DW.Actionu1_l.Actionu1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 45;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Fuzzy_manobra_aplicado_2015b_DW.Actionu1.Actionu1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 46;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
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


  targMap.checksum0 = 1222950069;
  targMap.checksum1 = 3518685006;
  targMap.checksum2 = 795471527;
  targMap.checksum3 = 1186167036;

