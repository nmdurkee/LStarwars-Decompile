/* Ghidra pseudocode, not original source.
 * ev_1e128395f166d68d7029ddd19e18d2d5e170338b26e7199f616481a8a2050617
 * Entry: 0x4ecb50; label: FUN_004ecb50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ecb50(int param_1)

{
  undefined *puVar1;
  int iVar2;
  
  _DAT_0088aab0 = 0;
  _DAT_0088aa9c = 0;
  _DAT_0088aaa0 = 0;
  _DAT_0088aaa4 = 0;
  _DAT_0088aaa8 = 0;
  DAT_0088aaad = 0;
  iVar2 = 0;
  DAT_0088aaae = 0xff;
  DAT_0088aaaf = 0xff;
  if ('\0' < DAT_0088aaac) {
    puVar1 = &DAT_0088a794;
    do {
      FUN_005cfc00(puVar1 + -0xc0,1);
      FUN_005cfc00(puVar1,0);
      FUN_005cfc00(puVar1 + 0x180,0);
      FUN_005cfc00(puVar1 + 0x240,0);
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 0xc;
    } while (iVar2 < DAT_0088aaac);
  }
  DAT_0088aac0 = FUN_005ab050(DAT_0095df4c,"HelpWithDisco",0,0);
  DAT_0088aac4 = FUN_005ab050(DAT_0095df4c,"DiscoComplete",0,0);
  DAT_0088aac8 = FUN_005ab050(DAT_0095df4c,"DiscoState",0,0);
  _DAT_0088aa94 = FUN_00558920(*(undefined4 *)(param_1 + 0x46a4),"disco_off");
  _DAT_0088aa98 = FUN_00558920(*(undefined4 *)(param_1 + 0x46a4),"disco_on");
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0088a678,"floor_disco",1);
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0088a684,"light1_a",1);
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0088a690,"disco_ball1",1);
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0088a69c,"disco_ball2",1);
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0088a6a8,"shutter_1",1);
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0088a6b4,"jabba_door1",1);
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0088a6c0,"jabba_door2",1);
  DAT_0088a670 = (undefined4 *)FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_007f8cc4,"force5")
  ;
  DAT_0088a62c = FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802644,"obstacle5");
  DAT_0088a560 = FUN_0058e980(param_1,"buildit6");
  DAT_0088a564 = FUN_0058e980(param_1,"buildit4");
  DAT_0087aad4 = FUN_0051ac10(*(undefined4 *)(param_1 + 0x2ae8),"DiscoHelp");
  iVar2 = FUN_005cfac0(&DAT_0088a69c);
  if (iVar2 != 0) {
    FUN_005cfc00(&DAT_0088a69c,0);
  }
  iVar2 = FUN_005cfac0(&DAT_0088a678);
  if (iVar2 != 0) {
    FUN_005cfc00(&DAT_0088a678,0);
  }
  iVar2 = FUN_005cfac0(&DAT_0088a684);
  if (iVar2 != 0) {
    FUN_005cfc00(&DAT_0088a684,0);
  }
  iVar2 = FUN_00467890(*DAT_0088a670);
  if (iVar2 != 0) {
    FUN_00557940();
    return;
  }
  return;
}

