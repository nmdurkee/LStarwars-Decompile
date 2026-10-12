/* Ghidra analysis pseudocode, not original source.
 * ev_cf42e26bdd29ce594f9da2c695f01b0cbf0dbb26fec502101b142af0e3962cb1
 * Entry: 0x581e40; label: FUN_00581e40
 */

void FUN_00581e40(int param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  char *pcVar5;
  int iVar6;
  undefined1 auStack_c4 [4];
  int local_c0;
  int local_bc;
  char local_b8 [48];
  undefined2 local_88;
  undefined2 local_86;
  uint local_c;
  
  local_c = DAT_00829570 ^ (uint)auStack_c4;
  local_c0 = param_1;
  _memset((void *)(param_1 + 0x4b14),0,0x520);
  iVar2 = FUN_004fc900("bolttypes",param_2,0xffff);
  local_bc = iVar2;
  if (iVar2 != 0) {
    FUN_004f10e0(iVar2,&PTR_DAT_008040c0);
    bVar1 = false;
    iVar3 = FUN_004fc5b0(iVar2);
    while (iVar3 != 0) {
      iVar3 = FUN_004f7fb0(iVar2);
      iVar6 = param_1;
      if (iVar3 != 0) {
        if (bVar1) {
          iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"bolttype_end");
          if (iVar3 == 0) {
            bVar1 = false;
            if (local_b8[0] != '\0') {
              FUN_00580150(param_1);
            }
          }
          else {
            FUN_004fa020(iVar2);
          }
        }
        else {
          iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"bolttype_start");
          if (iVar3 == 0) {
            bVar1 = true;
            DAT_00951cc0 = local_b8;
            DAT_00951cb8 = DAT_00924880;
            puVar4 = &DAT_00804018;
            pcVar5 = DAT_00951cc0;
            for (iVar2 = 0x29; iVar2 != 0; iVar2 = iVar2 + -1) {
              *(undefined4 *)pcVar5 = *puVar4;
              puVar4 = puVar4 + 1;
              pcVar5 = pcVar5 + 4;
            }
            local_b8[0] = '\0';
            local_88 = 0xffff;
            local_86 = 0xffff;
            DAT_00951cd0 = 0;
            iVar2 = local_bc;
            iVar6 = local_c0;
            DAT_00951cd4 = param_1;
          }
        }
      }
      iVar3 = FUN_004fc5b0(iVar2);
      param_1 = iVar6;
    }
    FUN_004fa300(iVar2);
  }
  __security_check_cookie(local_c ^ (uint)auStack_c4);
  return;
}

