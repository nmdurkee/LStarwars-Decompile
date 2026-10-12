/* Ghidra analysis pseudocode, not original source.
 * ev_966db37b3c76367cdd19664fe0d1b84c77d56b151d5f2c268a183ca8a07fabfc
 * Entry: 0x490160; label: FUN_00490160
 */

int FUN_00490160(float param_1,undefined4 param_2,int param_3,float *param_4)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  int local_10;
  undefined1 local_c [12];
  
  iVar2 = (int)param_1;
  param_1 = 1e+09;
  iVar4 = *(int *)(iVar2 + 0x5068);
  iVar5 = 0;
  local_10 = 0;
  iVar3 = 0;
  if (0 < *(int *)(iVar2 + 0x506c)) {
    do {
      if (param_3 == 0) {
        fVar6 = (float10)FUN_005b3c50(param_2,iVar4 + 0x68,0);
LAB_004901f5:
        if ((float)fVar6 < param_1) {
          param_1 = (float)fVar6;
          local_10 = iVar4;
        }
      }
      else {
        uVar1 = *(ushort *)(iVar4 + 0x94);
        if (((((char)uVar1 < '\0') && ((uVar1 & 0x10) != 0)) && ((uVar1 & 3) == 0)) &&
           ((*(float *)(iVar4 + 0x78) == 0.0 && (*(float *)(iVar4 + 0x44) != 2e+06)))) {
          FUN_004900e0(iVar4,local_c);
          fVar6 = (float10)FUN_005b3c50(param_2,local_c,0);
          goto LAB_004901f5;
        }
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0xa0;
      iVar3 = local_10;
    } while (iVar5 < *(int *)(iVar2 + 0x506c));
  }
  if (param_4 != (float *)0x0) {
    *param_4 = param_1;
  }
  return iVar3;
}

