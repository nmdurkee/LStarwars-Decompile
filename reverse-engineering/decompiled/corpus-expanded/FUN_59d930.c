/* Ghidra pseudocode, not original source.
 * ev_57e4595202f6848139a561b6e4253d561eb3ad03e2f9632ed29ba9ff4f0bafc7
 * Entry: 0x59d930; label: FUN_0059d930
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0059d930(undefined4 *param_1,int param_2,undefined1 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 local_4;
  
  piVar1 = *(int **)(param_2 + 0xc);
  local_4 = 1;
  if ((((*(ushort *)(param_2 + 10) & 0x4000) != 0) || (DAT_0093b2a4 != 0)) &&
     (((*(ushort *)(param_2 + 10) & 0x2000) != 0 || (DAT_0093b2a4 == 0)))) {
    iVar3 = 0;
    if (0 < *piVar1) {
      do {
        iVar2 = FUN_0055a1b0(*param_1,**(undefined4 **)(piVar1[2] + iVar3 * 4),param_3,
                             *(ushort *)(param_2 + 10) >> 0xc & 1);
        if (iVar2 == 0) {
          local_4 = 0;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < *piVar1);
    }
    return local_4;
  }
  return 1;
}

