/* Ghidra pseudocode, not original source.
 * ev_291f832bd6f6d010a6248a6acee690ff87721c4cdff92148d1e7c4ba042507e6
 * Entry: 0x4fda20; label: FUN_004fda20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_004fda20(undefined4 param_1,uint *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = *param_2 + 0xf & 0xfffffff0;
  *param_2 = uVar5;
  iVar2 = FUN_004fd5d0(param_1,uVar5,*param_3 - uVar5);
  if (iVar2 != 0) {
    *param_2 = *param_2 + iVar2;
    *(int *)(uVar5 + 0x14) = *(int *)(uVar5 + 0x14) + uVar5;
    *(int *)(uVar5 + 0x20) = *(int *)(uVar5 + 0x20) + uVar5;
    iVar2 = 0;
    if (0 < *(int *)(uVar5 + 0x18)) {
      iVar4 = 0;
      do {
        psVar3 = (short *)(*(int *)(uVar5 + 0x14) + iVar4);
        if (0 < *psVar3) {
          piVar1 = (int *)(psVar3 + 2);
          *piVar1 = *piVar1 + uVar5;
        }
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 + 0xc;
      } while (iVar2 < *(int *)(uVar5 + 0x18));
    }
    return uVar5;
  }
  return 0;
}

