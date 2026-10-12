/* Ghidra pseudocode, not original source.
 * ev_0c39cc066d2b612e886b5e8dc629d567ae8f788bfbc7a0ed81832ee74aa3ece0
 * Entry: 0x403240; label: FUN_00403240
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00403240(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  
  iVar4 = 0;
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    param_3[1] = 0;
    param_3[2] = 0;
    param_3[3] = 0;
    param_3[4] = 0;
    param_3[5] = 0;
    param_3[6] = 0;
    param_3[7] = 0;
    param_3[8] = 0xffffffff;
    param_3[9] = 0xffffffff;
    param_3[10] = 0;
    if (((param_1 != 0) && (*(int *)(param_1 + 0x5098) != 0)) && (0 < *(int *)(param_1 + 0x509c))) {
      pbVar3 = (byte *)(*(int *)(param_1 + 0x5098) + 0x62);
      do {
        if (0x1f < iVar4) {
          return;
        }
        *(byte *)(iVar4 + (int)param_3) = pbVar3[-3];
        iVar1 = (int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5;
        uVar2 = 1 << ((byte)iVar4 & 0x1f);
        if ((*pbVar3 & 2) == 0) {
          param_3[iVar1 + 8] = param_3[iVar1 + 8] & ~uVar2;
        }
        if ((*pbVar3 & 1) == 0) {
          param_3[iVar1 + 9] = param_3[iVar1 + 9] & ~uVar2;
        }
        if ((*pbVar3 & 4) != 0) {
          param_3[iVar1 + 10] = param_3[iVar1 + 10] | uVar2;
        }
        iVar4 = iVar4 + 1;
        pbVar3 = pbVar3 + 0x74;
      } while (iVar4 < *(int *)(param_1 + 0x509c));
    }
  }
  return;
}

