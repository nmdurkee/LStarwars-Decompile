/* Ghidra pseudocode, not original source.
 * ev_4cd49ed3a66acf658154edf3373401ea6a3421cc138b0b37f784f3d811d3c9f8
 * Entry: 0x502cb0; label: FUN_00502cb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00502cb0(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int local_10;
  int local_c;
  
  iVar1 = *(int *)(param_1 + 0x58);
  piVar2 = *(int **)(param_1 + 0xa4);
  piVar3 = *(int **)(iVar1 + 0x18);
  iVar4 = 0;
  local_c = 0;
  if ((short)piVar3[1] != 0) {
    local_10 = 0;
    do {
      piVar5 = (int *)(*piVar2 + local_10);
      iVar6 = *piVar3 + iVar4;
      if (*piVar5 != 0) {
        if (((*(byte *)(iVar6 + 0x5c) & 2) == 0) && (DAT_00921394 != (code *)0x0)) {
          (*DAT_00921394)(param_1,iVar1,piVar5,iVar6,param_2);
        }
        if ((DAT_0297ad54 == 0) && (DAT_00921390 != (code *)0x0)) {
          (*DAT_00921390)(piVar5,iVar6);
        }
      }
      local_10 = local_10 + 0x18;
      local_c = local_c + 1;
      iVar4 = iVar4 + 100;
    } while (local_c < (int)(uint)*(ushort *)(piVar3 + 1));
  }
  return;
}

