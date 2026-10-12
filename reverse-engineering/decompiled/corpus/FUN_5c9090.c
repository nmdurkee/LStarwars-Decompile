/* Ghidra analysis pseudocode, not original source.
 * ev_58a5325186d3cd5df394779674731c2ac26ad2d4ec877fc6396ce44c5c65b6b5
 * Entry: 0x5c9090; label: FUN_005c9090
 */

void FUN_005c9090(void)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = (undefined4 *)(in_ECX + 0x2dc);
  iVar1 = 2;
  do {
    iVar3 = iVar1;
    FUN_00605b60(*puVar2,0,0,0);
    FUN_00605b60(*puVar2,4,0,0);
    puVar2 = puVar2 + 1;
    iVar1 = iVar3 + -1;
  } while (iVar1 != 0);
  FUN_00605b60(*(undefined4 *)(in_ECX + 0x2f4),0,0,0);
  FUN_005f7b40(*(undefined4 *)(in_ECX + 0x30));
  FUN_005f7b40(*(undefined4 *)(in_ECX + 0x34));
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  FUN_005f7b40(*(undefined4 *)(in_ECX + 0x2c));
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  puVar2 = (undefined4 *)(in_ECX + 0x38);
  iVar3 = iVar3 + 1;
  do {
    FUN_005f7b40(*puVar2);
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

