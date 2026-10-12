/* Ghidra pseudocode, not original source.
 * ev_ffad5e5ce23835b03a7ab4a596a1220c1c80cd63cb6050216f74ff540445a181
 * Entry: 0x66fff0; label: FUN_0066fff0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0066fff0(float param_1,float param_2,float param_3,float param_4,float param_5,float param_6
                ,float param_7,float param_8,float param_9,float *param_10)

{
  float fVar1;
  float fVar2;
  short extraout_AX;
  short extraout_AX_00;
  short extraout_AX_01;
  short extraout_AX_02;
  short extraout_AX_03;
  short extraout_AX_04;
  short extraout_AX_05;
  short extraout_AX_06;
  short extraout_AX_07;
  short sVar3;
  short extraout_AX_08;
  short extraout_AX_09;
  ushort extraout_var;
  ushort extraout_var_00;
  ushort extraout_var_01;
  ushort extraout_var_02;
  ushort extraout_var_03;
  float fVar4;
  ushort uVar5;
  ushort extraout_var_04;
  ushort extraout_var_05;
  ushort extraout_var_06;
  ushort extraout_var_07;
  ushort extraout_var_08;
  ushort extraout_var_09;
  
  fVar1 = param_6;
  if ((ABS(*param_10) < ABS(param_10[1]) == (ABS(*param_10) == ABS(param_10[1]))) ||
     (ABS(param_10[2]) < ABS(param_10[1]) == (ABS(param_10[2]) == ABS(param_10[1])))) {
    fVar4 = ABS(*param_10);
    uVar5 = (ushort)((uint)fVar4 >> 0x10);
    fVar2 = param_5;
    if (ABS(param_10[1]) < fVar4 != (ABS(param_10[1]) == fVar4)) {
      fVar4 = ABS(*param_10);
      uVar5 = (ushort)((uint)fVar4 >> 0x10);
      if (ABS(param_10[2]) < fVar4 != (ABS(param_10[2]) == fVar4)) {
        if (0.0 <= *param_10) {
          FUN_0066ffa0(param_2,param_3,0,0,param_5,param_6);
          uVar5 = extraout_var_06;
          if (extraout_AX_06 == 0) goto LAB_00670513;
          FUN_0066ffa0(param_2,param_3,param_8,param_9,0,0);
          uVar5 = extraout_var_07;
          sVar3 = extraout_AX_07;
        }
        else {
          FUN_0066ffa0(param_2,param_3,param_5,param_6,0,0);
          uVar5 = extraout_var_04;
          if (extraout_AX_04 == 0) goto LAB_00670513;
          FUN_0066ffa0(param_2,param_3,0,0,param_8,param_9);
          uVar5 = extraout_var_05;
          fVar1 = param_9;
          fVar2 = param_8;
          param_8 = param_5;
          param_9 = param_6;
          sVar3 = extraout_AX_05;
        }
        goto joined_r0x00670376;
      }
    }
    param_3 = param_1;
    if (0.0 <= param_10[2]) {
      if ((param_2 - param_5) * (0.0 - param_4) + (param_5 - 0.0) * (param_1 - param_4) < 0.0)
      goto LAB_00670513;
      FUN_0066ffa0(param_2,param_1,0,0,param_8,param_7);
      uVar5 = extraout_var_09;
      fVar1 = param_7;
      fVar2 = param_8;
      param_8 = param_5;
      param_9 = param_4;
      sVar3 = extraout_AX_09;
    }
    else {
      if ((param_4 - 0.0) * (param_2 - 0.0) + (param_1 - 0.0) * (0.0 - param_5) < 0.0) {
        return (uint)uVar5 << 0x10;
      }
      FUN_0066ffa0(param_2,param_1,param_8,param_7,0,0);
      uVar5 = extraout_var_08;
      fVar1 = param_4;
      param_9 = param_7;
      sVar3 = extraout_AX_08;
    }
  }
  else {
    param_2 = param_1;
    if (0.0 <= param_10[1]) {
      FUN_0066ffa0(param_1,param_3,param_4,param_6,0,0);
      uVar5 = extraout_var_02;
      if (extraout_AX_02 == 0) goto LAB_00670513;
      FUN_0066ffa0(param_1,param_3,0,0,param_7,param_9);
      uVar5 = extraout_var_03;
      fVar1 = param_9;
      fVar2 = param_7;
      param_8 = param_4;
      param_9 = param_6;
      sVar3 = extraout_AX_03;
    }
    else {
      FUN_0066ffa0(param_1,param_3,0,0,param_4,param_6);
      uVar5 = extraout_var;
      if (extraout_AX == 0) goto LAB_00670513;
      FUN_0066ffa0(param_1,param_3,param_7,param_9,0,0);
      uVar5 = extraout_var_00;
      fVar2 = param_4;
      param_8 = param_7;
      sVar3 = extraout_AX_00;
    }
  }
joined_r0x00670376:
  if ((sVar3 != 0) &&
     (FUN_0066ffa0(param_2,param_3,fVar2,fVar1,param_8,param_9), uVar5 = extraout_var_01,
     extraout_AX_01 != 0)) {
    return CONCAT22(extraout_var_01,1);
  }
LAB_00670513:
  return (uint)uVar5 << 0x10;
}

