/* Ghidra pseudocode, not original source.
 * ev_04afb3492a8afd57c97545bb5c0eddf79bdf86b5b15013378a1fe0d824f4c6ce
 * Entry: 0x4f25e0; label: FUN_004f25e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004f25e0(ushort *param_1,ushort *param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  
  if (param_1 == (ushort *)0x0) {
    return 0xffffffff;
  }
  if (param_2 != (ushort *)0x0) {
    if (param_3 == 0) {
      return 0;
    }
    puVar3 = param_1;
    if ((param_3 == -1) || (puVar3 = param_2, param_3 == -2)) {
      param_3 = FUN_004f2370(puVar3);
    }
    do {
      uVar1 = *param_1;
      if (((ushort)(uVar1 - 0x61) < 0x1a) || ((ushort)(uVar1 - 0xe0) < 0x20)) {
        uVar1 = uVar1 - 0x20;
      }
      uVar2 = *param_2;
      if (((ushort)(uVar2 - 0x61) < 0x1a) || ((ushort)(uVar2 - 0xe0) < 0x20)) {
        uVar2 = uVar2 - 0x20;
      }
      if (uVar1 >= uVar2 && uVar1 != uVar2) {
        return 1;
      }
      if (uVar1 < uVar2) {
        return 0xffffffff;
      }
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
      param_3 = param_3 + -1;
    } while (((uVar1 != 0) && (uVar2 != 0)) && (param_3 != 0));
    return 0;
  }
  return 1;
}

