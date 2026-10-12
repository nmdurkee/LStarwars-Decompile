/* Ghidra analysis pseudocode, not original source.
 * ev_d8945a36929edeac9ee45c1fd9ef4d2b22c6103a52c54fc2dc40f3cab4594402
 * Entry: 0x5de2d0; label: FUN_005de2d0
 */

void FUN_005de2d0(int param_1,int param_2)

{
  uint *puVar1;
  undefined1 *puVar2;
  
  if (param_2 != *(int *)(*(int *)(param_1 + 8) + 8)) {
    *DAT_009736e0 = *DAT_009736e0 + 0xf & 0xfffffff0;
    puVar1 = DAT_009736e0;
    *(uint *)(*(int *)(param_1 + 0x14) + 4) = *DAT_009736e0;
    if ((*(short *)(param_2 + 0x74) < 1) ||
       ((int)*(short *)(param_2 + 0x74) == *(int *)(*(int *)(param_1 + 8) + 0x14))) {
      puVar2 = (undefined1 *)*puVar1;
      *puVar1 = (uint)(puVar2 + 0x40);
    }
    else {
      puVar2 = (undefined1 *)*puVar1;
      *puVar1 = (uint)(puVar2 + 0x60);
      *puVar2 = 0x87;
      *(undefined4 *)(puVar2 + 4) = 0;
      puVar2[1] = 0;
      puVar2[0x10] = 0x87;
      *(undefined4 *)(puVar2 + 0x14) = 0;
      puVar2[0x11] = 0;
      puVar2 = puVar2 + 0x20;
      *(int *)(*(int *)(param_1 + 8) + 0x14) = (int)*(short *)(param_2 + 0x74);
    }
    *puVar2 = 0x80;
    *(int *)(puVar2 + 4) = param_2;
    puVar2[1] = 3;
    *(undefined4 *)(puVar2 + 0x14) = 0;
    puVar2[0x11] = 0;
    puVar2[0x10] = 0x87;
    *(undefined4 *)(puVar2 + 0x24) = 0;
    puVar2[0x21] = 0;
    puVar2[0x20] = 0x87;
    *(undefined4 *)(puVar2 + 0x34) = 0;
    puVar2[0x30] = 0x8d;
    puVar2[0x31] = 1;
    *(undefined1 **)(param_1 + 0x14) = puVar2 + 0x30;
    *(int *)(*(int *)(param_1 + 8) + 8) = param_2;
  }
  return;
}

