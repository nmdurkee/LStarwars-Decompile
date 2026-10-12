/* Ghidra pseudocode, not original source.
 * ev_0e37ff2b068f2f451a629821c3494056628992f54992bdfe8536c4096373c130
 * Entry: 0x4e8650; label: FUN_004e8650
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e8650(void)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  iVar3 = FUN_0055f450();
  FUN_0055e340(local_18,0);
  if (*(int *)(iVar3 + 0x128) == DAT_0087b1dc) {
    if (DAT_0087a96c == (int *)0x0) {
      return;
    }
    iVar1 = *DAT_0087a96c;
    if (iVar1 == 0) {
      return;
    }
    if ((*(byte *)(iVar1 + 0x17) & 0x48) != 0) {
      return;
    }
    if (9 < DAT_0088a288) {
      return;
    }
    DAT_0088a288 = DAT_0088a288 + 1;
    if (DAT_0088a288 != 10) {
      FUN_00561940(local_18,DAT_0088a288,10,200,100,0x1e,0x3f400000);
      return;
    }
    local_24 = 0;
    local_20 = 0;
    local_1c = 0x41200000;
    FUN_005b35a0(&local_24,&local_24,0xfffff1c8);
    FUN_005b3620(&local_24,&local_24,0xffffe000);
    FUN_005b37d0(&local_24,&local_24,iVar1 + 8);
    FUN_00577880(&local_24,iVar1 + 8,0,0,0x40800000,0,0,0,0,0);
    FUN_0055a250(*(undefined4 *)(iVar3 + 0x2ac8),DAT_0087a96c,1,1);
    puVar4 = local_c;
    bVar2 = DAT_0088a288;
  }
  else {
    if (*(int *)(iVar3 + 0x128) != DAT_0087b1e4) {
      return;
    }
    if (DAT_0087a970 == (int *)0x0) {
      return;
    }
    iVar1 = *DAT_0087a970;
    if (iVar1 == 0) {
      return;
    }
    if ((*(byte *)(iVar1 + 0x17) & 0x48) != 0) {
      return;
    }
    if (9 < DAT_0088a289) {
      return;
    }
    DAT_0088a289 = DAT_0088a289 + 1;
    if (DAT_0088a289 == 10) {
      local_24 = 0;
      local_20 = 0;
      local_1c = 0x41c80000;
      FUN_005b35a0(&local_24,&local_24,0xffffeaab);
      FUN_005b3620(&local_24,&local_24,0xffff78e4);
      FUN_005b37d0(&local_24,&local_24,iVar1 + 8);
      FUN_00577880(&local_24,iVar1 + 8,0,0,0x40800000,0,0,0,0,0);
      FUN_0055a250(*(undefined4 *)(iVar3 + 0x2ac8),DAT_0087a970,1,1);
      FUN_00561940(local_c,DAT_0088a289,10,200,100,0x1e,0x3f400000);
      return;
    }
    puVar4 = local_18;
    bVar2 = DAT_0088a289;
  }
  FUN_00561940(puVar4,bVar2,10,200,100,0x1e,0x3f400000);
  return;
}

