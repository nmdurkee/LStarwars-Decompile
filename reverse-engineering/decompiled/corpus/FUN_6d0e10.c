/* Ghidra analysis pseudocode, not original source.
 * ev_b8d156e74790e07078a260599393ca89d6d858c624833fd21a4e8cf1d6239801
 * Entry: 0x6d0e10; label: FUN_006d0e10
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

