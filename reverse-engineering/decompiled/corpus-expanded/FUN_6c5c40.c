/* Ghidra pseudocode, not original source.
 * ev_647b85ee0a7e8e41d889ce710347a98583a3d140d8a364c007ecae69f59044b8
 * Entry: 0x6c5c40; label: FUN_006c5c40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006c5c40(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  puVar2 = *(undefined4 **)(in_ECX + 0xc);
  if (puVar2 != (undefined4 *)0x0) {
    iVar1 = FUN_0061f030();
    if (puVar2[2] != iVar1) {
      puVar2 = (undefined4 *)FUN_006c5c10(*puVar2);
    }
    if (puVar2 != (undefined4 *)0x0) {
      return *puVar2;
    }
  }
  return 0;
}

