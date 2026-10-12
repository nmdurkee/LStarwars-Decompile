/* Ghidra pseudocode, not original source.
 * ev_73151266ff1c8f163ed19691e079968d47cc326d45708775e4f70bdc31fc3cf9
 * Entry: 0x5f5ce0; label: FUN_005f5ce0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f5ce0(void)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  *(undefined4 *)(in_ECX + 0x100) = 0x3c23d70a;
  *(undefined4 *)(in_ECX + 0x104) = 0x3a83126f;
  *(undefined4 *)(in_ECX + 0x374) = 0;
  *(undefined4 *)(in_ECX + 0x110) = 0x3f800000;
  *(undefined4 *)(in_ECX + 0x260) = 0;
  puVar5 = (undefined4 *)(in_ECX + 0x32c);
  puVar4 = (undefined4 *)(in_ECX + 0x2b4);
  iVar3 = 2;
  do {
    uVar2 = FUN_005f2200();
    puVar5[2] = uVar2;
    uVar2 = FUN_005f2160();
    *puVar5 = uVar2;
    _memset(puVar4 + -4,0,0x44);
    puVar1 = (undefined1 *)puVar5[2];
    *puVar4 = puVar1;
    *puVar1 = 0x8d;
    *(undefined4 *)(puVar1 + 4) = 0;
    puVar1[1] = 1;
    puVar4[1] = *puVar4;
    uVar2 = *puVar5;
    puVar4[-2] = uVar2;
    FUN_005fca40(uVar2);
    puVar4[1] = *puVar4;
    puVar5 = puVar5 + 1;
    puVar4 = puVar4 + 0x11;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

