/* Ghidra pseudocode, not original source.
 * ev_fb6cd954323bef10c706b5185a175772da5bd325e62fab563c9169acbcfebd41
 * Entry: 0x613890; label: FUN_00613890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00613890(int *param_1,undefined4 param_2,int param_3,int param_4,int param_5,int *param_6,
                 undefined4 param_7)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *in_ECX;
  float *pfStack_138;
  byte local_131;
  float fStack_130;
  int local_12c;
  int *local_128;
  int *local_124;
  undefined4 local_120;
  int local_11c;
  undefined4 local_118;
  int local_114;
  uint auStack_110 [3];
  float afStack_104 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&pfStack_138;
  piVar1 = *(int **)(param_3 + 8);
  local_131 = *(byte *)((int)in_ECX + 0xe) >> 3 & 1;
  local_124 = in_ECX;
  local_118 = param_2;
  local_12c = param_4;
  local_11c = param_5;
  local_128 = param_6;
  local_120 = param_7;
  local_114 = param_3;
  do {
    if (piVar1 == (int *)0x0) {
      __security_check_cookie(local_4 ^ (uint)&pfStack_138);
      return;
    }
    if ((piVar1[7] & 0x80000000U) == 0) {
      if (piVar1[9] == (uint)*(ushort *)(local_124 + 3)) {
        iVar4 = FUN_006be710(piVar1[3]);
        iVar3 = piVar1[6];
        if (iVar3 < 1) {
          iVar3 = *(int *)(iVar4 + 4);
        }
        if (local_12c == 0) {
          (**(code **)(*param_1 + 4))(iVar3,1);
        }
        else {
          if (param_1[2] == 2) {
            (**(code **)(*piVar1 + 4))(local_12c,piVar1[3],afStack_104,0x100);
          }
          (**(code **)(iVar4 + 8))(param_1,afStack_104,iVar3);
          if (((param_1[2] == 1) && (*local_128 < 3)) && (local_131 == 0)) {
            (**(code **)(*piVar1 + 8))(local_12c,piVar1[3],afStack_104,0x100,local_120);
          }
        }
        iVar3 = piVar1[3];
        iVar4 = 1;
        if (iVar3 == DAT_02973ab4) {
LAB_00613ab6:
          pfStack_138 = afStack_104;
        }
        else {
          if ((iVar3 == DAT_02973ab8) || (iVar3 == DAT_02973ad0)) {
            iVar4 = 3;
            goto LAB_00613ab6;
          }
          if (iVar3 == DAT_02973aa8) {
            pfStack_138 = &fStack_130;
            fStack_130 = (float)(int)afStack_104[0]._0_1_;
          }
          else if (iVar3 == DAT_02973aac) {
            pfStack_138 = &fStack_130;
            fStack_130 = (float)(int)afStack_104[0]._0_2_;
          }
          else if (iVar3 == DAT_02973ab0) {
            fStack_130 = (float)(int)afStack_104[0];
            pfStack_138 = &fStack_130;
          }
          else {
            FUN_00611890();
          }
        }
        iVar3 = 0;
        if (iVar4 != 0) {
          iVar6 = *(int *)(local_11c + 8);
          do {
            uVar5 = iVar6 + 3U & 0xfffffffc;
            auStack_110[iVar3] = uVar5;
            iVar3 = iVar3 + 1;
            iVar6 = uVar5 + 0xc;
          } while (iVar3 < iVar4);
          *(int *)(local_11c + 8) = iVar6;
        }
        (**(code **)(*local_124 + 0xc))(local_114,local_12c,local_128,auStack_110,pfStack_138,iVar4)
        ;
      }
    }
    else {
      uVar2 = FUN_006be7f0(piVar1[3]);
      iVar3 = (**(code **)*piVar1)(local_12c);
      if ((DAT_02900a38 != 0) && (iVar3 == 0)) {
        iVar3 = local_12c;
      }
      iVar4 = FUN_006c66c0(param_1,iVar3);
      if (iVar4 != 0) {
        FUN_00613890(param_1,local_118,uVar2,iVar3,local_11c,local_128,local_120);
      }
    }
    piVar1 = (int *)piVar1[1];
  } while( true );
}

