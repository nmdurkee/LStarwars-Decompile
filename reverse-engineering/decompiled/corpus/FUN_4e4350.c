/* Ghidra analysis pseudocode, not original source.
 * ev_fba68665c2ecb02d4c13d026ba12834cd95aaa1020801387b253bb991a5bde4e
 * Entry: 0x4e4350; label: FUN_004e4350
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e4350(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 *puVar4;
  undefined *puVar5;
  char **ppcVar6;
  char *local_28 [4];
  char *local_18;
  char *local_14;
  char *local_10;
  char *local_c;
  char *local_8;
  char *local_4;
  
  local_28[0] = "rock1";
  local_28[1] = "rock2";
  local_28[2] = "rock3";
  local_28[3] = "rock4";
  local_18 = "rock5";
  local_14 = "rock6";
  local_10 = "rock7";
  local_c = "rock8";
  local_8 = "rock10";
  local_4 = "rock11";
  _memset(&DAT_008894d0,0,0x98);
  DAT_008894d0 = FUN_005aac00(DAT_0095df4c,"FinalFight",0);
  DAT_008894d4 = FUN_0051ac10(*(undefined4 *)(param_1 + 0x2ae8),"Bigjump_0");
  puVar5 = &DAT_008894d8;
  ppcVar6 = local_28;
  puVar4 = &DAT_00889550;
  do {
    iVar2 = FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),puVar5,*ppcVar6,1);
    if (iVar2 == 0) {
      *puVar4 = 0xffff;
    }
    else {
      uVar3 = FUN_005cffb0(puVar5);
      uVar1 = FUN_0067c760(uVar3);
      *puVar4 = uVar1;
    }
    puVar5 = puVar5 + 0xc;
    ppcVar6 = ppcVar6 + 1;
    puVar4 = puVar4 + 1;
  } while ((int)puVar5 < 0x889550);
  _DAT_008895a8 = 0;
  DAT_00889568 = FUN_00578750(1);
  return;
}

