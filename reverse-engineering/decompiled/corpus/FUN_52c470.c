/* Ghidra analysis pseudocode, not original source.
 * ev_cadbdcea344f284c720862a9d60fea326d89961e952df44594a2f8e4339e7270
 * Entry: 0x52c470; label: FUN_0052c470
 */

void FUN_0052c470(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined1 *puVar7;
  int local_d48;
  undefined *local_d44;
  undefined4 local_d40;
  undefined4 local_d3c;
  undefined4 local_d38;
  undefined4 local_d34;
  int local_d30;
  undefined4 local_d2c [5];
  undefined1 local_d18 [148];
  char local_c84 [128];
  undefined1 local_c04 [3072];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_d48;
  iVar6 = 0;
  local_d30 = param_1;
  local_d3c = param_2;
  local_d38 = param_3;
  local_d40 = param_4;
  local_d48 = param_5;
  if (param_5 == 0) {
    local_d44 = &DAT_00921ee8;
  }
  else {
    local_d44 = (undefined *)(param_5 + 0x1c);
  }
  if (param_1 == 0) {
LAB_0052c556:
    _sprintf(local_c84,"%s\\script.txt",local_d3c);
    iVar2 = FUN_004fa5f0(local_c84,0);
    if (iVar2 == 0) goto LAB_0052c618;
  }
  else {
    iVar2 = FUN_004f9de0(param_1,"script.txt");
    if (iVar2 == 0) {
      if (DAT_00922248 == 1) {
        iVar2 = FUN_00512870();
      }
      else {
        iVar2 = FUN_00512850();
      }
LAB_0052c53a:
      if (DAT_00923874 == iVar2) {
        if (DAT_00922248 == iVar2) {
          FUN_00512860();
        }
        else {
          FUN_00512850();
        }
      }
      goto LAB_0052c556;
    }
    FUN_004f0f30(param_1,iVar2,local_d2c,&local_d34);
    iVar2 = FUN_004f02d0(local_d2c[0],local_d34,0);
    if (iVar2 == 0) {
      FUN_00512870();
      iVar2 = 1;
      goto LAB_0052c53a;
    }
  }
  iVar3 = FUN_004fc750(iVar2);
  if (iVar3 != 0) {
    iVar4 = FUN_004fc5b0(iVar3);
    if (iVar4 != 0) {
      puVar7 = local_c04;
      do {
        FUN_004f7fb0(iVar3);
        uVar5 = FUN_004f1ff0(*(undefined4 *)(iVar3 + 0x510));
        if (0xf < uVar5) {
          FUN_00512850(local_d18);
        }
        FUN_004f1f10(puVar7,*(undefined4 *)(iVar3 + 0x510));
        FUN_004f1e80(puVar7,&DAT_0075ffd8);
        iVar6 = iVar6 + 1;
        puVar7 = puVar7 + 0x18;
        iVar4 = FUN_004fc5b0(iVar3);
        param_5 = local_d48;
      } while (iVar4 != 0);
    }
    FUN_004f12e0(iVar3);
  }
  FUN_004f99e0(iVar2);
LAB_0052c618:
  if (0 < iVar6) {
    puVar7 = local_c04;
    do {
      iVar2 = FUN_0052c320(puVar7,local_d38,local_d40);
      if ((iVar2 != 0) && (FUN_004f1310(local_d44,iVar2), local_d48 != 0)) {
        *(uint *)(iVar2 + 0x3c) = *(uint *)(iVar2 + 0x3c) | 1;
      }
      puVar7 = puVar7 + 0x18;
      iVar6 = iVar6 + -1;
      param_5 = local_d48;
    } while (iVar6 != 0);
  }
  if (param_5 != 0) {
    do {
      bVar1 = true;
      iVar6 = FUN_004f1440(param_5 + 0x1c);
      if (iVar6 == 0) break;
      do {
        iVar2 = FUN_00513f20(iVar6,local_d38,local_d40,local_d48);
        if (iVar2 == 0) {
          bVar1 = false;
        }
        iVar6 = FUN_004f1460(param_5 + 0x1c,iVar6);
      } while (iVar6 != 0);
    } while (!bVar1);
  }
  __security_check_cookie(local_4 ^ (uint)&local_d48);
  return;
}

