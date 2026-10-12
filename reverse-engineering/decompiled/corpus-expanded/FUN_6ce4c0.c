/* Ghidra pseudocode, not original source.
 * ev_9b11381a0c0b3e4dd58bf4ee610de1a55b8174f7034ba55ce3625dcac2ea44f3
 * Entry: 0x6ce4c0; label: FUN_006ce4c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_006ce4c0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  
  puVar2 = (undefined4 *)FUN_00633440(0x58,1);
  iVar4 = 0;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    if (puVar2 + 1 != (undefined4 *)0x0) {
      puVar2[1] = 0;
      puVar2[2] = 0;
    }
    *puVar2 = &PTR_FUN_0076fa4c;
    puVar2[0xb] = 0;
    puVar2[0xc] = 0;
    puVar2[0xd] = 0;
    puVar2[0xe] = 0;
    puVar2[0xf] = 0;
    puVar2[0x10] = 0;
    *(undefined2 *)(puVar2 + 0x11) = DAT_02973aa0;
  }
  FUN_004f1f10(puVar2 + 3,in_ECX + 0xc);
  puVar5 = *(undefined4 **)(in_ECX + 0x2c);
  if (0 < *(int *)(in_ECX + 0x34)) {
    do {
      puVar3 = (undefined4 *)FUN_00633440(0x50,1);
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        *puVar3 = 0;
        puVar3[1] = 0;
        *(undefined2 *)(puVar3 + 0x11) = DAT_02973aa0;
      }
      puVar3[0x10] = puVar2;
      *puVar3 = 0;
      puVar3[1] = puVar2[0xc];
      if ((undefined4 *)puVar2[0xc] != (undefined4 *)0x0) {
        *(undefined4 *)puVar2[0xc] = puVar3;
      }
      puVar2[0xc] = puVar3;
      if (puVar2[0xb] == 0) {
        puVar2[0xb] = puVar3;
      }
      puVar2[0xd] = puVar2[0xd] + 1;
      puVar3[4] = puVar5[4];
      iVar4 = iVar4 + 1;
      puVar3[5] = puVar5[5];
      puVar3[6] = puVar5[6];
      puVar3[7] = puVar5[7];
      puVar3[8] = puVar5[8];
      puVar3[9] = puVar5[9];
      puVar3[10] = puVar5[10];
      puVar3[0xb] = puVar5[0xb];
      puVar3[0xc] = puVar5[0xc];
      puVar3[0xd] = puVar5[0xd];
      puVar3[0xe] = puVar5[0xe];
      puVar1 = puVar5 + 0xf;
      puVar5 = (undefined4 *)*puVar5;
      puVar3[0xf] = *puVar1;
    } while (iVar4 < *(int *)(in_ECX + 0x34));
  }
  puVar2[0x12] = *(undefined4 *)(in_ECX + 0x48);
  puVar2[0x13] = *(undefined4 *)(in_ECX + 0x4c);
  puVar2[0x14] = *(undefined4 *)(in_ECX + 0x50);
  puVar2[0x15] = *(undefined4 *)(in_ECX + 0x54);
  if (_DAT_0081fa00 <= *(float *)(in_ECX + 0x48)) {
    FUN_006c7730();
    return puVar2;
  }
  FUN_006c7660();
  return puVar2;
}

