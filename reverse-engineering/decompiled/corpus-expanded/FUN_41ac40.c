/* Ghidra pseudocode, not original source.
 * ev_a5c3a3c7ef2e1a12e467fd0202ed50a9ce8374cc5ec0bfb4f993dbf776f2abbe
 * Entry: 0x41ac40; label: FUN_0041ac40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0041ac40(void)

{
  int iVar1;
  int unaff_ESI;
  undefined4 auStack_40054 [65535];
  undefined4 local_54 [21];
  
  local_54[7] = 1;
  local_54[8] = 2;
  local_54[9] = 3;
  local_54[10] = 0x15;
  local_54[0xb] = 0x16;
  local_54[0xc] = 0x17;
  local_54[0xd] = 5;
  local_54[0xe] = 6;
  local_54[0xf] = 7;
  local_54[0x10] = 8;
  local_54[0x11] = 9;
  local_54[0x12] = 10;
  local_54[0x13] = 0x10;
  local_54[0x14] = 0x11;
  local_54[4] = 0xb;
  local_54[5] = 0xc;
  local_54[6] = 0xf;
  local_54[0] = 0xd;
  local_54[1] = 0xe;
  local_54[2] = 0x13;
  local_54[3] = 0x14;
  iVar1 = FUN_0054fa60();
  *(uint *)(unaff_ESI + 0xef0) =
       *(uint *)(unaff_ESI + 0xef0) ^
       ((uint)(iVar1 < 0x8000) << 9 ^ *(uint *)(unaff_ESI + 0xef0)) & 0x200;
  iVar1 = FUN_0054fa60();
  if (iVar1 < 0x8000) {
    *(uint *)(unaff_ESI + 0x1048) = *(uint *)(unaff_ESI + 0x1048) | 0x10;
  }
  *(undefined4 *)(unaff_ESI + 0x1048) = 1;
  iVar1 = FUN_0054fa60();
  *(uint *)(unaff_ESI + 0x1048) =
       *(uint *)(unaff_ESI + 0x1048) | 1 << ((byte)local_54[iVar1 / 0x2aab + 7] & 0x1f);
  iVar1 = FUN_0054fa60();
  *(uint *)(unaff_ESI + 0x1048) =
       *(uint *)(unaff_ESI + 0x1048) |
       1 << ((byte)local_54[((int)(iVar1 + (iVar1 >> 0x1f & 0x1fffU)) >> 0xd) + 0xd] & 0x1f);
  iVar1 = FUN_0054fa60();
  *(uint *)(unaff_ESI + 0x1048) =
       *(uint *)(unaff_ESI + 0x1048) | 1 << ((byte)local_54[iVar1 / 0x5556 + 4] & 0x1f);
  iVar1 = FUN_0054fa60();
  *(uint *)(unaff_ESI + 0x1048) =
       *(uint *)(unaff_ESI + 0x1048) |
       1 << ((byte)local_54[(int)(iVar1 + (iVar1 >> 0x1f & 0x7fffU)) >> 0xf] & 0x1f);
  iVar1 = FUN_0054fa60();
  *(uint *)(unaff_ESI + 0x1048) =
       *(uint *)(unaff_ESI + 0x1048) |
       1 << ((byte)local_54[((int)(iVar1 + (iVar1 >> 0x1f & 0x7fffU)) >> 0xf) + 2] & 0x1f);
  return;
}

