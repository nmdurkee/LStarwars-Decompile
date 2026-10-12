/* Ghidra analysis pseudocode, not original source.
 * ev_469f0313f1021f0e4bd926e538674038e4b9c059f1b4f78e0c32d78ee9f9f283
 * Entry: 0x4d5f00; label: FUN_004d5f00
 */

int FUN_004d5f00(int param_1,undefined4 param_2,float param_3,float *param_4,int *param_5,
                int param_6)

{
  float fVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float local_10;
  int local_c;
  int local_8;
  
  iVar4 = *(int *)(param_1 + 0x4688);
  if (iVar4 == 0) {
    return 0;
  }
  local_8 = 0;
  local_c = 0;
  local_10 = (param_3 + 0.25) * (param_3 + 0.25);
  if (0 < *(int *)(param_1 + 0x468c)) {
    do {
      if (param_6 == 0) goto LAB_004d5fa3;
      uVar2 = *(ushort *)(iVar4 + 0x68);
      if (((uVar2 & 0x40) != 0) && ((char)uVar2 < '\0')) {
        if ((uVar2 & 0x20) == 0) {
          if (((*(uint *)(*(int *)(*(int *)(param_6 + 0x54) + 0x24) + 0x94) & 0x20000000) == 0) &&
             (((uVar2 & 2) != 0 || (*(char *)(param_6 + 0x280) == -1)))) goto LAB_004d5fa3;
        }
        else if ((*(uint *)(*(int *)(*(int *)(param_6 + 0x54) + 0x24) + 0x94) & 0x20000000) != 0) {
LAB_004d5fa3:
          iVar3 = 0;
          do {
            if ((param_6 == 0) ||
               ((iVar3 != 1 && ((iVar3 != 2 || ((*(byte *)(iVar4 + 0x68) & 8) != 0)))))) {
              fVar5 = (float10)FUN_005b3c50(param_2,iVar4 + 0x10 + iVar3 * 0xc,0);
              fVar1 = (float)fVar5;
              if ((fVar1 < local_10) && (local_10 = fVar1, local_8 = iVar4, param_5 != (int *)0x0))
              {
                *param_5 = iVar3;
              }
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < 3);
        }
      }
      local_c = local_c + 1;
      iVar4 = iVar4 + 0x7c;
    } while (local_c < *(int *)(param_1 + 0x468c));
  }
  if (param_4 != (float *)0x0) {
    *param_4 = local_10;
  }
  return local_8;
}

