/* Ghidra pseudocode, not original source.
 * ev_57e4595202f6848139a561b6e4253d561eb3ad03e2f9632ed29ba9ff4f0bafc7
 * Entry: 0x59d8e0; label: FUN_0059d8e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059d8e0(undefined4 *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_2 + 0xc);
  if (((*(ushort *)(param_2 + 10) & 0x1000) == 0) && (iVar2 = 0, 0 < *piVar1)) {
    do {
      FUN_0055a250(*param_1,**(undefined4 **)(piVar1[2] + iVar2 * 4),0,1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < *piVar1);
  }
  return;
}

