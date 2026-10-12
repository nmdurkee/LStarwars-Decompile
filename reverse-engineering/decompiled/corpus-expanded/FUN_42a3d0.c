/* Ghidra pseudocode, not original source.
 * ev_07ae9e2e04489686a5b927c1fa0593b6d570aedc464c7aee9c2d2b7a39d3047e
 * Entry: 0x42a3d0; label: FUN_0042a3d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

