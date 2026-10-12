/* Ghidra pseudocode, not original source.
 * ev_2fc6966d7cb88e652aff05d91af92c1aae7a14fbd03261d64dee7cfe7594468f
 * Entry: 0x6d0e10; label: FUN_006d0e10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d0e10(void)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar5 = *(undefined4 **)(in_ECX + 0x10);
  puVar3 = (undefined4 *)0x0;
  if (puVar5 != (undefined4 *)0x0) {
    do {
      puVar1 = *(undefined4 **)(in_ECX + 0xc);
      if (puVar1 == (undefined4 *)0x0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        iVar2 = FUN_0061f030();
        if (puVar1[2] != iVar2) {
          puVar1 = (undefined4 *)FUN_006c5c10(*puVar1);
        }
      }
      puVar4 = puVar5;
      if (puVar5 != puVar1) {
        FUN_006cd130(puVar5);
        puVar4 = puVar3;
      }
      puVar5 = (undefined4 *)puVar5[1];
      puVar3 = puVar4;
    } while (puVar5 != (undefined4 *)0x0);
    if (puVar4 != (undefined4 *)0x0) {
      FUN_006cd130(puVar4);
    }
  }
  return;
}

