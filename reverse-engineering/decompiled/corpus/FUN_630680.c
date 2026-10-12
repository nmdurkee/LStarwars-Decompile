/* Ghidra analysis pseudocode, not original source.
 * ev_e26d15e716f54b37dc9752c5bbece96131eaa1b0064d3ed9476ea38cc0029dc6
 * Entry: 0x630680; label: FUN_00630680
 */

undefined4 FUN_00630680(short *param_1,int param_2,int *param_3)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  
  if (param_1 != (short *)0x0) {
    iVar3 = 0;
    sVar2 = *param_1;
    while (sVar2 != -1) {
      if (sVar2 == param_2) {
        if (param_3 != (int *)0x0) {
          *param_3 = iVar3;
        }
        return 1;
      }
      psVar1 = param_1 + 2;
      param_1 = param_1 + 2;
      iVar3 = iVar3 + 1;
      sVar2 = *psVar1;
    }
  }
  if (param_3 != (int *)0x0) {
    *param_3 = -1;
  }
  return 0;
}

