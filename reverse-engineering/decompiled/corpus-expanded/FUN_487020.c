/* Ghidra pseudocode, not original source.
 * ev_77fef26266fe5967585df020e38eccd49263e70128ef006db684616fa6a4691c
 * Entry: 0x487020; label: FUN_00487020
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00487020(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  float local_18;
  int local_14;
  undefined1 local_c [8];
  float local_4;
  
  if (*(char *)(param_1 + 0x7b5) == '\x17') {
    local_18 = 1.44;
  }
  else {
    local_18 = 0.48999998;
  }
  iVar2 = 0;
  if (DAT_007fa564 == 3) {
    local_14 = DAT_0093d500;
  }
  else {
    local_14 = 8;
  }
  iVar5 = 0;
  if (0 < local_14) {
    iVar3 = 0;
    do {
      if (DAT_007fa564 == 3) {
        iVar4 = DAT_0093d504 + iVar3;
      }
      else {
        iVar4 = (&DAT_0093d7f0)[iVar5];
      }
      if (((((((iVar4 != 0) && ((*(uint *)(iVar4 + 0x1fc) & 1) != 0)) &&
             ((*(uint *)(iVar4 + 0x1fc) & 0x1000) != 0)) &&
            ((iVar4 != param_1 && (*(char *)(iVar4 + 0x28b) == '\0')))) &&
           (((*(byte *)(iVar4 + 0x7c5) & 2) == 0 &&
            ((cVar1 = *(char *)(iVar4 + 0x7b5), cVar1 != '\x17' && (cVar1 != '=')))))) &&
          ((*(uint *)(PTR_PTR_007fb0e4 + cVar1 * 0x10 + 8) & 0x8000) == 0)) &&
         (((*(byte *)(iVar4 + 0xef4) & 2) == 0 || (*(short *)(param_1 + 0x1064) == DAT_007f198c))))
      {
        fVar6 = (float10)FUN_005b3c50(param_1 + 0x5c,iVar4 + 0x5c,local_c);
        if (((float)fVar6 < local_18) &&
           (FUN_005b3620(local_c,local_c,-(uint)*(ushort *)(param_1 + 0x27a)), local_4 < 0.0)) {
          iVar2 = iVar4;
          local_18 = (float)fVar6;
        }
      }
      iVar5 = iVar5 + 1;
      iVar3 = iVar3 + 0x10d8;
    } while (iVar5 < local_14);
  }
  return iVar2;
}

