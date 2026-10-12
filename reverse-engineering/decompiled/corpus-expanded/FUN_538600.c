/* Ghidra pseudocode, not original source.
 * ev_b6e394b5e6447b25b30eeb5758ac1a35d86131e46c625f62ba009b62f4fc19bf
 * Entry: 0x538600; label: FUN_00538600
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00538600(void)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  void *local_224;
  int local_220;
  undefined1 local_21c [16];
  char local_20c;
  char local_20b;
  char local_20a;
  char local_209;
  char local_208;
  short local_206;
  char local_104 [128];
  char local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_224;
  local_224 = (void *)(DAT_009238e4 + 0x43838);
  local_220 = DAT_009238e4 + 0xc3838;
  _memset(local_224,0,0x80000);
  iVar2 = FUN_005322d0(&local_224,&local_220,&DAT_00921f64,&DAT_00921f68);
  if ((iVar2 != 0) && (*(int *)(DAT_009238e4 + 0x43830) != 0)) {
    _sprintf(local_104,"%sLevels\\%s\\%s\\%s.ai2",PTR_DAT_00801c70,
             *(undefined4 *)(DAT_009238e4 + 0x4382c),*(undefined4 *)(DAT_009238e4 + 0x43834),
             *(undefined4 *)(DAT_009238e4 + 0x43830));
    iVar3 = thunk_FUN_004fa610(local_104);
    if (iVar3 != 0) {
      iVar3 = FUN_004ff970(local_104,local_21c);
      if (iVar3 != 0) {
        pcVar1 = local_104;
        iVar3 = FUN_004f8a70(pcVar1,&DAT_0075a204);
        while (iVar3 != 0) {
          pcVar1 = (char *)(iVar3 + 1);
          iVar3 = FUN_004f8a70(pcVar1,&DAT_0075a204);
        }
        _sprintf(local_84,"ai_backups\\%s.%d_%d_%d_%d_%d_%d",pcVar1,(int)local_206,(int)local_208,
                 (int)local_209,(int)local_20a,(int)local_20b,(int)local_20c);
        FUN_004fd850(local_84,local_104);
      }
      _sprintf(local_84,"%s.bak",local_104);
      FUN_004fd850(local_84,local_104);
    }
    FUN_006211c0(1);
    iVar3 = FUN_00621270(local_104,1);
    if (iVar3 == 0) {
      __security_check_cookie(local_4 ^ (uint)&local_224);
      return;
    }
    FUN_00621520(DAT_0080171c);
    FUN_00525080(iVar2);
    FUN_00520ee0();
    FUN_00521cb0(iVar2);
    FUN_005285f0(iVar2);
    FUN_00528210();
    if (DAT_009238ec != (code *)0x0) {
      (*DAT_009238ec)(iVar2);
    }
    FUN_006213e0();
  }
  __security_check_cookie(local_4 ^ (uint)&local_224);
  return;
}

