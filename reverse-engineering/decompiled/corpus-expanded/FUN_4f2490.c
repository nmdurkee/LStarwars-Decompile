/* Ghidra pseudocode, not original source.
 * ev_04afb3492a8afd57c97545bb5c0eddf79bdf86b5b15013378a1fe0d824f4c6ce
 * Entry: 0x4f2490; label: FUN_004f2490
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004f2490(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  ushort uVar2;
  
  if (param_1 == (ushort *)0x0) {
    return 0xffffffff;
  }
  if (param_2 != (ushort *)0x0) {
    while( true ) {
      uVar1 = *param_1;
      uVar2 = *param_2;
      if (uVar2 < uVar1) break;
      if (uVar1 < uVar2) {
        return 0xffffffff;
      }
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
      if ((uVar1 == 0) || (uVar2 == 0)) {
        return 0;
      }
    }
  }
  return 1;
}

