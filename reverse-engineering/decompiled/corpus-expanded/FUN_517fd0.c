/* Ghidra pseudocode, not original source.
 * ev_7610d2e5ecab5d7a95653def000f5e9425ca0c842a62593dc010feaabdcb80b1
 * Entry: 0x517fd0; label: FUN_00517fd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00517fd0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar2 = param_1 + 0x3c;
    iVar3 = 0;
    do {
      if ((*(byte *)(iVar2 + 0x50) & 1) == 0) {
        puVar1 = (uint *)(iVar3 * 0x134 + 0x8c + param_1);
        *puVar1 = *puVar1 | 1;
        *(uint *)(iVar2 + 0x50) = *(uint *)(iVar2 + 0x50) & 0xfffffff7;
        *(undefined4 *)(iVar2 + 0x128) = param_3;
        *(undefined4 *)(iVar2 + 300) = param_4;
        *(undefined1 *)(iVar2 + 8) = (undefined1)param_2;
        *(undefined4 *)(iVar2 + 0x130) = param_5;
        return iVar2;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x134;
    } while (iVar3 < 0x10);
  }
  return 0;
}

