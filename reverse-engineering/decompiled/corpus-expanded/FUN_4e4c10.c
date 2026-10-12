/* Ghidra pseudocode, not original source.
 * ev_9cfa2c7caaff9bea1a8899eb9da7a192a21c6dc6359864cdd250e80ead8b0fa3
 * Entry: 0x4e4c10; label: FUN_004e4c10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e4c10(void)

{
  uint in_EAX;
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined **ppuVar4;
  int aiStackY_80120 [131055];
  int local_120 [4];
  undefined *local_110 [5];
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  int local_ec;
  undefined4 local_e4;
  code *local_d0;
  code *local_cc;
  code *local_bc;
  undefined4 local_84;
  undefined1 local_48 [68];
  
  local_120[1] = (int)DAT_007f1a40;
  local_120[3] = (int)DAT_007f1a44;
  local_120[0] = (int)DAT_007f1a3c;
  if (1 < in_EAX) {
    return;
  }
  iVar2 = 0;
  local_120[2] = local_120[0];
  do {
    if ((&DAT_0087a9a8)[iVar2] == 0) {
      FUN_005b4500(local_48,&DAT_008001ec + in_EAX * 0xc);
      iVar1 = FUN_0054fa60();
      iVar1 = FUN_0043d890(local_120[(int)(iVar1 + (iVar1 >> 0x1f & 0x3fffU)) >> 0xe],
                           &DAT_008001ec + in_EAX * 0xc,0,"default",0,0,0,0,0,0,0);
      (&DAT_0087a7f0)[iVar2] = iVar1;
      if (iVar1 != 0) {
        *(uint *)(iVar1 + 0xef4) =
             *(uint *)(iVar1 + 0xef4) ^ (DAT_00800144 << 5 ^ *(uint *)(iVar1 + 0xef4)) & 0x20;
        *(uint *)((&DAT_0087a7f0)[iVar2] + 0xef0) = *(uint *)((&DAT_0087a7f0)[iVar2] + 0xef0) | 0x10
        ;
        *(undefined2 *)((&DAT_0087a7f0)[iVar2] + 0x3ee) = 0xe9;
        *(undefined2 *)((&DAT_0087a7f0)[iVar2] + 0x3f0) = 5;
        *(uint *)((&DAT_0087a7f0)[iVar2] + 0xef0) =
             *(uint *)((&DAT_0087a7f0)[iVar2] + 0xef0) | 0x4000000;
        puVar3 = &DAT_00810210;
        ppuVar4 = local_110;
        for (iVar1 = 0x32; iVar1 != 0; iVar1 = iVar1 + -1) {
          *ppuVar4 = (undefined *)*puVar3;
          puVar3 = puVar3 + 1;
          ppuVar4 = ppuVar4 + 1;
        }
        local_fc = 0x3e19999a;
        local_f8 = 0x3e19999a;
        local_f4 = 0;
        local_110[0] = local_48;
        local_110[2] = &DAT_008001e0;
        local_ec = *(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xfe0;
        local_84 = _DAT_00925018;
        local_e4 = 0x8698;
        local_d0 = FUN_0042cf20;
        local_cc = FUN_004e4bb0;
        local_bc = FUN_004e4c00;
        iVar1 = FUN_0064d270(local_110);
        (&DAT_0087a9a8)[iVar2] = iVar1;
        *(undefined4 *)(iVar1 + 0x100) = 0x41f00000;
        if ((&DAT_0087a9a8)[iVar2] != 0) {
          return;
        }
        FUN_004364e0((&DAT_0087a7f0)[iVar2],4,0);
        (&DAT_0087a7f0)[iVar2] = 0;
        return;
      }
    }
    iVar2 = iVar2 + 1;
    if (7 < iVar2) {
      return;
    }
  } while( true );
}

