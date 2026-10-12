/* Ghidra pseudocode, not original source.
 * ev_347e1f77405e8535e9481480e28747f276aa6cf4478f7a28ab99ed1128324eac
 * Entry: 0x644e10; label: FUN_00644e10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00644e10(void)

{
  int iVar1;
  undefined2 uVar2;
  
  iVar1 = DAT_0292096c;
  if (DAT_0292096c != 0) {
    uVar2 = FUN_006e6b90();
    *(undefined2 *)(iVar1 + 0x46) = uVar2;
  }
  return;
}

