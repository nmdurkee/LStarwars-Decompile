/* Ghidra pseudocode, not original source.
 * ev_fbc0fd73cf89a7f733f4465e4ab1049333b8e7c593c45a6546f4f82b49062809
 * Entry: 0x5eed30; label: FUN_005eed30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005eed30(int *param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_2 == 0xffffffff) {
    return 0;
  }
  if ((param_2 & 0x4000) != 0) {
    iVar2 = FUN_005e5390(param_1,param_2);
    if (iVar2 == 0) {
      iVar2 = FUN_005f8fd0();
      if ((0 < iVar2) && (iVar2 = *(int *)(DAT_0097157c + -4 + iVar2 * 4), iVar2 != 0)) {
        piVar1 = (int *)(iVar2 + 0x18);
        *piVar1 = *piVar1 + 1;
      }
      iVar2 = *(int *)(param_1[2] + (param_2 & 0x3fff) * 4);
      iVar2 = FUN_005c1300(*(undefined1 *)(iVar2 + 8),*(undefined1 *)(iVar2 + 9),
                           *(undefined1 *)(iVar2 + 10),*(undefined1 *)(iVar2 + 0xb),
                           *(undefined1 *)(iVar2 + 0xc),*(undefined1 *)(iVar2 + 0xd),
                           *(undefined1 *)(iVar2 + 0xe),*(undefined1 *)(iVar2 + 0xf),
                           *(undefined1 *)(iVar2 + 0x10),*(undefined1 *)(iVar2 + 0x11),
                           *(undefined1 *)(iVar2 + 0x12),*(undefined1 *)(iVar2 + 0x13),
                           *(undefined1 *)(iVar2 + 0x14),*(undefined1 *)(iVar2 + 0x15),
                           *(undefined1 *)(iVar2 + 0x16),*(undefined1 *)(iVar2 + 0x17));
    }
    return iVar2;
  }
  return *(int *)(*param_1 + param_2 * 4);
}

