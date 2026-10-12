/* Ghidra analysis pseudocode, not original source.
 * ev_afde76c9da02194678eff0a54ce656dfadfb8e6d7e607c68c4e1b37896a76ad5
 * Entry: 0x5fcdf0; label: FUN_005fcdf0
 */

void FUN_005fcdf0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  *DAT_009736e0 = *DAT_009736e0 + 0xf & 0xfffffff0;
  puVar1 = (undefined4 *)*DAT_009736e0;
  *DAT_009736e0 = (uint)(puVar1 + 0x2f);
  *puVar1 = *(undefined4 *)(param_1 + 0x38);
  puVar1[1] = *(undefined4 *)(param_1 + 0x3c);
  puVar1[2] = *(undefined4 *)(param_1 + 0x40);
  puVar1[3] = 0x3f800000;
  puVar1[4] = *(undefined4 *)(param_1 + 0x68);
  puVar1[5] = *(undefined4 *)(param_1 + 0x6c);
  puVar1[6] = *(undefined4 *)(param_1 + 0x70);
  puVar1[7] = 0x3f800000;
  puVar1[0x10] = *(undefined4 *)(param_1 + 0x44);
  puVar1[0x11] = *(undefined4 *)(param_1 + 0x48);
  puVar1[0x12] = *(undefined4 *)(param_1 + 0x4c);
  puVar1[0x13] = 0x3f800000;
  puVar1[8] = *(undefined4 *)(param_1 + 0x74);
  puVar1[9] = *(undefined4 *)(param_1 + 0x78);
  puVar1[10] = *(undefined4 *)(param_1 + 0x7c);
  puVar1[0xb] = 0x3f800000;
  puVar1[0x14] = *(undefined4 *)(param_1 + 0x50);
  puVar1[0x15] = *(undefined4 *)(param_1 + 0x54);
  puVar1[0x16] = *(undefined4 *)(param_1 + 0x58);
  puVar1[0x17] = 0x3f800000;
  puVar1[0xc] = *(undefined4 *)(param_1 + 0x80);
  puVar1[0xd] = *(undefined4 *)(param_1 + 0x84);
  puVar1[0xe] = *(undefined4 *)(param_1 + 0x88);
  puVar1[0xf] = 0x3f800000;
  puVar1[0x18] = *(undefined4 *)(param_1 + 0x5c);
  puVar1[0x19] = *(undefined4 *)(param_1 + 0x60);
  puVar1[0x1a] = *(undefined4 *)(param_1 + 100);
  puVar1[0x1b] = 0x3f800000;
  puVar3 = (undefined4 *)(param_1 + 0x90);
  puVar4 = puVar1 + 0x1c;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  puVar1[0x2c] = *(undefined4 *)(param_1 + 0xd0);
  puVar1[0x2d] = *(undefined4 *)(param_1 + 0xd4);
  puVar1[0x2e] = *(undefined4 *)(param_1 + 0xd8);
  return;
}

