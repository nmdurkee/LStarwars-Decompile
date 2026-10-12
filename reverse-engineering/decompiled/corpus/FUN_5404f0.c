/* Ghidra analysis pseudocode, not original source.
 * ev_5e8001be3994efa046f160ea8bbb155dc91a9aa9b9ccef45a0e0570780a0cbe5
 * Entry: 0x5404f0; label: FUN_005404f0
 */

void FUN_005404f0(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 int param_6)

{
  char *pcVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if ((((param_1 != (int *)0x0) && (param_2 != 0)) && (param_6 != 0)) &&
     (iVar3 = FUN_004fc900("socks",param_2,0xffff), iVar3 != 0)) {
    DAT_029838e0 = param_6;
    DAT_009242c4 = param_4;
    DAT_009242dc = param_5;
    FUN_004f1120(iVar3,&PTR_s_circuit_00801e40);
    bVar2 = false;
    iVar4 = FUN_004fc5b0(iVar3);
    while (iVar4 != 0) {
      FUN_004f7fb0(iVar3);
      pcVar1 = *(char **)(iVar3 + 0x510);
      if (*pcVar1 != '\0') {
        if (bVar2) {
          iVar4 = FUN_004f8b10(pcVar1,"sock_end");
          if (iVar4 == 0) {
            bVar2 = false;
          }
          else {
            FUN_004fa180(iVar3,0);
          }
        }
        else {
          iVar4 = FUN_004f8b10(pcVar1,"sock_start");
          if ((iVar4 == 0) && (uVar5 = FUN_004f9e70(iVar3), uVar5 < 0x40)) {
            DAT_029838fc = uVar5 * 0x13c + *param_1;
            bVar2 = true;
          }
        }
      }
      iVar4 = FUN_004fc5b0(iVar3);
    }
    FUN_004fa300(iVar3);
  }
  return;
}

