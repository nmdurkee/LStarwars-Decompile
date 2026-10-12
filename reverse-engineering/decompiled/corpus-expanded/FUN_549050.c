/* Ghidra pseudocode, not original source.
 * ev_ba19024e936acaebc8caa887b02629c3d2df1b51d473842281df89ce325ba5c8
 * Entry: 0x549050; label: FUN_00549050
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00549050(int param_1,float *param_2)

{
  float fVar1;
  int iVar2;
  undefined2 in_FPUControlWord;
  float10 fVar3;
  undefined4 uVar4;
  undefined2 uVar5;
  
  uVar4 = 0;
  if (0.0 < _DAT_00925058) {
    _DAT_00925058 = _DAT_00925058 - _DAT_00925018;
    uVar4 = 0x3f800000;
  }
  fVar3 = (float10)FUN_0054fad0(_DAT_009250ac,uVar4,_DAT_00925018 + _DAT_00925018);
  uVar5 = (undefined2)((uint)uVar4 >> 0x10);
  _DAT_009250ac = (float)fVar3;
  if (DAT_0093b328 == 0) {
    if (param_2 != (float *)0x0) {
      *param_2 = *param_2 + _DAT_00925018;
    }
    FUN_00548fe0(&DAT_0092505c);
    FUN_00548fe0(&DAT_0092509c);
    FUN_00548fe0(&DAT_0092507c);
    FUN_00548fe0(&DAT_00925044);
    if (DAT_00951be0 == 0) {
      if ((((*(int *)(param_1 + 0x128) != 0) &&
           ((*(byte *)(*(int *)(param_1 + 0x128) + 100) & 2) != 0)) && (DAT_00950748 == 0)) &&
         ((DAT_0093d7f0 != 0 || (DAT_0093d7f4 != 0)))) {
        FUN_00548fe0(&DAT_00924fdc);
        FUN_00548fe0(&DAT_0092508c);
        if (DAT_007f3b14 == -1) {
          FUN_00548fe0(&DAT_00925008);
        }
        if (((*(uint *)(*(int *)(param_1 + 0x128) + 100) & 0x2000) != 0) &&
           (FUN_00548fe0(&DAT_0092506c), 36000.0 < _DAT_0092506c)) {
          FUN_00548fb0(&DAT_0092506c,0x470ca000);
        }
        if ((*(int *)(param_1 + 300) != 0) &&
           ((*(byte *)(*(int *)(param_1 + 300) + 0x7a) & 0x10) != 0)) {
          if (DAT_00856c08 == 1) {
            FUN_00548fe0(&DAT_0085ea64);
            if ((DAT_0095136c != 0) &&
               (fVar1 = *(float *)(DAT_0095136c + 8 + *(int *)(param_1 + 0x120) * 0xc),
               fVar1 < _DAT_0085ea64 != (fVar1 == _DAT_0085ea64))) {
              FUN_0042f3a0(3,1);
            }
          }
          else {
            iVar2 = FUN_0058a930(0);
            if (((iVar2 == 1) &&
                (fVar1 = (float)*(ushort *)(*(int *)(DAT_009553d4 + 4) + 0x10),
                FUN_00548fe0(DAT_009553d4 + 8),
                fVar1 < *(float *)(DAT_009553d4 + 8) != (fVar1 == *(float *)(DAT_009553d4 + 8)))) &&
               (DAT_00951b50 == 0)) {
              FUN_00497760(DAT_009553d4,3,1);
            }
          }
        }
      }
      FUN_00561020();
      if ((DAT_0087b924 == 0) || (iVar2 = FUN_00574e20(), iVar2 != -1)) {
        uVar4 = 0;
      }
      else {
        uVar4 = 0x3f800000;
      }
      fVar3 = (float10)FUN_0054fad0(_DAT_00925040,uVar4,_DAT_00925018);
      uVar5 = (undefined2)((uint)uVar4 >> 0x10);
    }
    else {
      fVar3 = (float10)0;
    }
  }
  else if ((DAT_00950744 != 0) || (FUN_00548fe0(&DAT_00924ff8), 0.5 <= _DAT_00925058)) {
    fVar3 = (float10)0;
  }
  else {
    _DAT_00925058 = 0.5;
    fVar3 = (float10)0;
  }
  _DAT_00925040 = (float)fVar3;
  FUN_00548fe0(&DAT_00925028);
  fVar3 = (float10)FUN_005b7d30(_DAT_00925030,0x3e4ccccd);
  DAT_009213e4 = (uint)(fVar3 < (float10)0.10000000149011612);
  fVar3 = (float10)FUN_005b7d30(_DAT_00925064,0x3f000000);
  _DAT_009250b8 =
       (&DAT_029899a0)[(uint)(int)ROUND((fVar3 + fVar3) * (float10)65536.0) >> 1 & 0x7fff];
  fVar3 = (float10)FUN_005b7d30(_DAT_00925030,0x3f000000,CONCAT22(uVar5,in_FPUControlWord));
  _DAT_009250bc =
       (&DAT_029899a0)[(uint)(int)ROUND((fVar3 + fVar3) * (float10)65536.0) >> 1 & 0x7fff];
  fVar3 = (float10)FUN_0054fad0(_DAT_00950678,_DAT_0095067c,_DAT_00925018,in_FPUControlWord);
  _DAT_00950678 = (float)fVar3;
  FUN_0054fa60();
  return;
}

