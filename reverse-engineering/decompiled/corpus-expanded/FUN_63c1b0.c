/* Ghidra pseudocode, not original source.
 * ev_0e84ad542db3be7599677a500db2c2fcd5f6f463504cd13a52c31f7d7facbfa7
 * Entry: 0x63c1b0; label: FUN_0063c1b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0063c1b0(float param_1,int param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float local_c;
  float local_8;
  float local_4;
  
  if ((*(int *)(param_2 + 0x554) == -1) ||
     (FUN_005b3800(&local_c,&DAT_029134a4,param_2 + 0xd4 + *(int *)(param_2 + 0x554) * 0x24),
     local_4 * local_4 + local_c * local_c + local_8 * local_8 != 0.0)) {
    *(undefined4 *)(param_2 + 0x554) = 0xffffffff;
    iVar2 = 0;
    iVar3 = param_2 + 0xd4;
    do {
      if (*(int *)(iVar3 + -4) != 0) {
        FUN_005b3800(&local_c,&DAT_029134a4,iVar3);
        fVar1 = local_4 * local_4 + local_c * local_c + local_8 * local_8;
        if ((param_1 < 0.0) || (fVar1 < param_1)) {
          *(int *)(param_2 + 0x554) = iVar2;
          param_1 = fVar1;
        }
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x24;
    } while (iVar2 < 0x20);
  }
  return;
}

