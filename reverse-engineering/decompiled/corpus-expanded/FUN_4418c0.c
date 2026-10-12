/* Ghidra pseudocode, not original source.
 * ev_52b1dbacad98807a86fda1d7285f00f4b35f02131457f245004edfced337e57f
 * Entry: 0x4418c0; label: FUN_004418c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004418c0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_c [12];
  
  if (DAT_0292fc68 != 0) {
    iVar1 = FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),local_c,param_2,1);
    if (iVar1 != 0) {
      uVar2 = FUN_005cffb0(local_c);
      uVar2 = FUN_0067c760(uVar2);
      return uVar2;
    }
  }
  return 0xffffffff;
}

