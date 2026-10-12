/* Ghidra analysis pseudocode, not original source.
 * ev_9b402c9e9507e171b8c16fab1dff2f919b44cba00aab1d6e0da1cdd21bc5614e
 * Entry: 0x6444e0; label: FUN_006444e0
 */

void FUN_006444e0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined4 *puVar4;
  
  iVar1 = param_1 * 0x178;
  iVar2 = 0;
  puVar3 = &DAT_02913ae8 + param_1 * 0xbc;
  do {
    *puVar3 = 0xffff;
    (&DAT_02913af8)[iVar2 + iVar1] = 1;
    iVar2 = iVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (iVar2 < 8);
  (&DAT_02913b08)[iVar1] = 0;
  (&DAT_02913b14)[param_1 * 0x5e] = 0;
  (&DAT_02913b54)[param_1 * 0x5e] = 0;
  (&DAT_02913b58)[param_1 * 0x5e] = 0;
  (&DAT_02913b1c)[param_1 * 0x5e] = 0x3f800000;
  (&DAT_02913b5c)[param_1 * 0x5e] = 0;
  (&DAT_02913b24)[param_1 * 0x5e] = 0x3f800000;
  (&DAT_02913b6c)[param_1 * 0x5e] = 0;
  (&DAT_02913b44)[param_1 * 0x5e] = 0x3f800000;
  (&DAT_02913b70)[param_1 * 0x5e] = 0xffffffff;
  (&DAT_02913b74)[param_1 * 0x5e] = 0xffffffff;
  (&DAT_02913b20)[param_1 * 0x5e] = 0;
  (&DAT_02913b80)[param_1 * 0x5e] = 0xffffffff;
  (&DAT_02913b48)[param_1 * 0x5e] = 0;
  (&DAT_02913b9c)[param_1 * 0x5e] = 0xffffffff;
  (&DAT_02913b4c)[param_1 * 0x5e] = 0;
  (&DAT_02913b84)[param_1 * 0x5e] = 0xffffffff;
  (&DAT_02913b50)[param_1 * 0x5e] = 0;
  (&DAT_02913b88)[param_1 * 0x5e] = 0xffffffff;
  (&DAT_02913bc4)[param_1 * 0x5e] = 0;
  (&DAT_02913bcc)[param_1 * 0x5e] = 0xffffffff;
  iVar2 = 0;
  puVar4 = &DAT_02913ba0 + param_1 * 0x5e;
  (&DAT_02913bc8)[param_1 * 0x5e] = 0x3f800000;
  do {
    *puVar4 = 0xffffffff;
    (&DAT_02913bb0)[iVar2 + iVar1] = 0;
    iVar2 = iVar2 + 1;
    puVar4 = puVar4 + 1;
  } while (iVar2 < 4);
  return;
}

