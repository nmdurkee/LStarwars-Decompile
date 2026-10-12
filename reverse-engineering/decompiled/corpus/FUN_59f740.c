/* Ghidra analysis pseudocode, not original source.
 * ev_619d50b6392102a54c9e38c540a3f8930ee6fdfe94aeb342acdefb90820d232e
 * Entry: 0x59f740; label: FUN_0059f740
 */

void FUN_0059f740(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    *(char *)(param_1 + 0xc) = *(char *)(param_1 + 0xc) + '\x01';
    iVar1 = 0;
    iVar2 = *(int *)(param_1 + 8);
    if (0 < *(int *)(param_1 + 4)) {
      do {
        if ((*(char *)(iVar2 + 8) != *(char *)(param_1 + 0xc)) &&
           (((*(ushort *)(iVar2 + 10) & 1) != 0 || ((*(ushort *)(iVar2 + 10) & 0x100) != 0)))) {
          FUN_0059e090(param_1,iVar2,*(char *)(param_1 + 0xc));
        }
        *(undefined1 *)(iVar2 + 8) = *(undefined1 *)(param_1 + 0xc);
        iVar1 = iVar1 + 1;
        iVar2 = iVar2 + 0x20;
      } while (iVar1 < *(int *)(param_1 + 4));
    }
  }
  return;
}

