/* Ghidra pseudocode, not original source.
 * ev_2ffc02f844b111bcf8c927080cf20237220999a93cf27a25e92d9f9e0dff8274
 * Entry: 0x511ea0; label: FUN_00511ea0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00511ea0(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  ushort in_FPUControlWord;
  char *pcVar5;
  uint local_10c;
  uint local_108;
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_10c;
  puVar3 = (undefined4 *)(DAT_02976c28 * 0x10 + _DAT_02976be4);
  if (DAT_0297ae1c == 0) {
    FUN_006ded20();
  }
  FUN_004f2740(local_104,"%s: %d x %d",DAT_0297adcc,*puVar3,puVar3[1]);
  FUN_0050f740(param_1,local_104,DAT_00921d60);
  if (DAT_0297ae1c == 0) {
    FUN_006ded20();
  }
  FUN_004f2740(local_104,"%s: %dHz",DAT_0297add0,puVar3[2]);
  FUN_0050f740(param_1,local_104,DAT_00921d60);
  switch(DAT_00921d04) {
  case 0:
    if (DAT_0297ae1c == 0) {
      FUN_006ded20();
    }
    pcVar5 = "%s: 4:3";
    break;
  case 1:
    if (DAT_0297ae1c == 0) {
      FUN_006ded20();
    }
    pcVar5 = "%s: 16:9";
    break;
  case 2:
    if (DAT_0297ae1c == 0) {
      FUN_006ded20();
    }
    pcVar5 = "%s: 16:10";
    break;
  case 3:
    if (DAT_0297ae1c == 0) {
      FUN_006ded20();
    }
    uVar4 = DAT_0297ade0;
    if (DAT_0297ae1c == 0) {
      FUN_006ded20();
    }
    FUN_004f2740(local_104,"%s: %s",DAT_0297add8,uVar4);
    goto LAB_00512025;
  default:
    if (DAT_0297ae1c == 0) {
      FUN_006ded20();
    }
    pcVar5 = "%s: ERROR";
  }
  FUN_004f2740(local_104,pcVar5,DAT_0297add8);
LAB_00512025:
  FUN_0050f740(param_1,local_104,DAT_00921d60);
  if (DAT_00921d14 == 0) {
    uVar4 = DAT_0297adc0;
    if (DAT_0297ae1c == 0) {
      FUN_006ded20();
      uVar4 = DAT_0297adc0;
    }
  }
  else {
    uVar4 = DAT_0297adbc;
    if (DAT_0297ae1c == 0) {
      FUN_006ded20();
      uVar4 = DAT_0297adbc;
    }
  }
  if (DAT_0297ae1c == 0) {
    FUN_006ded20();
  }
  FUN_004f2740(local_104,"%s: %s",DAT_0297addc,uVar4);
  local_108 = (uint)in_FPUControlWord;
  local_10c = (uint)ROUND((float)(byte)((-(DAT_008264c9 != '\0') & 0xbfU) + 0x40) * _DAT_00921d5c);
  FUN_0050f740(param_1,local_104,local_10c & 0xff);
  cVar1 = FUN_006e2b40();
  if ((cVar1 == '\0') && (cVar1 = FUN_00509180(), cVar1 == '\0')) {
    if (DAT_0297ae1c == 0) {
      FUN_006ded20();
    }
    FUN_004f2740(local_104,&DAT_00758828,DAT_0297ada8);
    uVar2 = (uint)DAT_00921d60;
  }
  else {
    if (DAT_0297ae1c == 0) {
      FUN_006ded20();
    }
    FUN_004f2740(local_104,&DAT_00758828,DAT_0297ada0);
    local_108 = CONCAT22(local_108._2_2_,in_FPUControlWord);
    local_10c = (uint)ROUND((float)(byte)-(DAT_009213e4 != 0) * _DAT_00921d5c);
    uVar2 = local_10c & 0xff;
  }
  FUN_0050f740(param_1,local_104,uVar2);
  __security_check_cookie(local_4 ^ (uint)&local_10c);
  return;
}

