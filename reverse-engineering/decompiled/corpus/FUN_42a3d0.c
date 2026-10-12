/* Ghidra analysis pseudocode, not original source.
 * ev_310631bb624827f7a98d5acd3a21e7258cb6e2cd16a2b6553760fed88e2e9667
 * Entry: 0x42a3d0; label: FUN_0042a3d0
 */

undefined4 FUN_0042a3d0(void)

{
  int iVar1;
  undefined1 local_44 [12];
  undefined1 local_38;
  char local_37;
  
  iVar1 = FUN_0055e340(local_44,&local_38);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  if (local_37 != '\x06') {
    if ((local_37 == '\a') || (local_37 == '\b')) {
      return 1;
    }
    if ((((local_37 != '\x02') && (local_37 != '\x03')) && (local_37 != '\x04')) &&
       (local_37 != '\t')) {
      return 0xffffffff;
    }
  }
  return 0;
}

