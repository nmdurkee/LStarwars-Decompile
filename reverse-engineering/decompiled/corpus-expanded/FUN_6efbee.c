/* Ghidra pseudocode, not original source.
 * ev_167fb1af16662301ac7ec00e42056ea51ba92ee67c43a8d5117ba6e42cb74a01
 * Entry: 0x6efbee; label: ___libm_error_support
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    ___libm_error_support
   
   Library: Visual Studio 2005 Release */

void ___libm_error_support(double *param_1,undefined8 *param_2,double *param_3,int param_4)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_2c;
  undefined **local_28;
  double local_24;
  undefined8 local_1c;
  double local_14;
  undefined1 local_c;
  undefined1 uStack_b;
  undefined1 uStack_a;
  undefined1 uStack_9;
  undefined1 uStack_8;
  undefined1 uStack_7;
  undefined1 uStack_6;
  undefined1 uStack_5;
  
  local_c = 0;
  uStack_b = 0;
  uStack_a = 0;
  uStack_9 = 0;
  uStack_8 = 0;
  uStack_7 = 0;
  uStack_6 = 0;
  uStack_5 = 0;
  if (DAT_0297c534 == 0) {
    pcVar1 = FUN_00701fd5;
  }
  else {
    pcVar1 = (code *)FUN_006f01bc(DAT_029a9c40);
  }
  if (param_4 < 0xa7) {
    if (param_4 == 0xa6) {
      local_2c = 3;
      local_28 = (undefined **)0x777f94;
LAB_006efc9d:
      local_24 = *param_1;
      local_1c = *param_2;
      local_14 = *param_3;
      iVar2 = (*pcVar1)(&local_2c);
      if (iVar2 == 0) {
        puVar3 = (undefined4 *)FUN_006ead5f();
        *puVar3 = 0x22;
      }
    }
    else if (param_4 < 0x1a) {
      if (param_4 != 0x19) {
        local_2c = 2;
        if (param_4 == 2) {
          local_2c = 2;
          local_28 = (undefined **)&DAT_00777fac;
        }
        else {
          if (param_4 == 3) {
            local_28 = (undefined **)&DAT_00777fac;
            goto LAB_006efd0b;
          }
          if (param_4 == 8) {
            local_28 = (undefined **)0x777fb0;
          }
          else {
            if (param_4 == 9) {
              local_28 = (undefined **)0x777fb0;
              goto LAB_006efd0b;
            }
            if (param_4 != 0xe) {
              if (param_4 != 0xf) {
                if (param_4 != 0x18) {
                  return;
                }
                local_2c = 3;
                goto LAB_006efc96;
              }
              local_28 = (undefined **)&DAT_00777fb8;
              goto LAB_006efcd2;
            }
            local_2c = 3;
            local_28 = (undefined **)&DAT_00777fb8;
          }
        }
        goto LAB_006efc9d;
      }
      local_28 = (undefined **)&DAT_00777fbc;
LAB_006efcd2:
      local_24 = *param_1;
      local_1c = *param_2;
      local_2c = 4;
      local_14 = *param_3;
      (*pcVar1)(&local_2c);
    }
    else {
      if (param_4 != 0x1a) {
        if (param_4 != 0x1b) {
          if (param_4 == 0x1c) goto switchD_006efdc8_caseD_3ee;
          if (param_4 != 0x1d) {
            if (param_4 != 0x3a) {
              if (param_4 != 0x3d) {
                return;
              }
              goto switchD_006efdc8_caseD_3f1;
            }
            goto switchD_006efdc8_caseD_3f0;
          }
          local_28 = (undefined **)&DAT_00777fbc;
          goto LAB_006efd81;
        }
        local_2c = 2;
LAB_006efc96:
        local_28 = (undefined **)&DAT_00777fbc;
        goto LAB_006efc9d;
      }
      local_14 = 1.0;
    }
    goto LAB_006efe61;
  }
  switch(param_4) {
  case 1000:
    local_28 = (undefined **)&DAT_00777fac;
    break;
  case 0x3e9:
    local_28 = (undefined **)0x777fb0;
    break;
  case 0x3ea:
    local_28 = (undefined **)&DAT_00777fb8;
    break;
  case 0x3eb:
    local_28 = (undefined **)&DAT_00777f8c;
    break;
  case 0x3ec:
    local_28 = (undefined **)&DAT_00777f84;
    break;
  case 0x3ed:
    local_28 = (undefined **)0x777f7c;
    break;
  case 0x3ee:
switchD_006efdc8_caseD_3ee:
    local_28 = (undefined **)&DAT_00777fbc;
    goto LAB_006efd0b;
  case 0x3ef:
    local_28 = (undefined **)&DAT_00777f74;
    break;
  case 0x3f0:
switchD_006efdc8_caseD_3f0:
    local_28 = (undefined **)&DAT_00777f9c;
    goto LAB_006efd0b;
  case 0x3f1:
switchD_006efdc8_caseD_3f1:
    local_28 = (undefined **)&DAT_00777fa4;
    goto LAB_006efd0b;
  case 0x3f2:
    local_28 = (undefined **)&DAT_00777f70;
    goto LAB_006efe2d;
  case 0x3f3:
    local_28 = &PTR_PTR_00777f6c;
    goto LAB_006efe2d;
  case 0x3f4:
    local_28 = (undefined **)&DAT_00777f68;
LAB_006efe2d:
    local_14 = *param_1 *
               (double)CONCAT17(uStack_5,CONCAT16(uStack_6,CONCAT15(uStack_7,CONCAT14(uStack_8,
                                                  CONCAT13(uStack_9,CONCAT12(uStack_a,CONCAT11(
                                                  uStack_b,local_c)))))));
    *param_3 = local_14;
    local_24 = *param_1;
    local_1c = *param_2;
    goto LAB_006efe3e;
  default:
    goto switchD_006efdc8_default;
  }
LAB_006efd81:
  *param_3 = *param_1;
LAB_006efd0b:
  local_24 = *param_1;
  local_1c = *param_2;
  local_14 = *param_3;
LAB_006efe3e:
  local_2c = 1;
  iVar2 = (*pcVar1)(&local_2c);
  if (iVar2 == 0) {
    puVar3 = (undefined4 *)FUN_006ead5f();
    *puVar3 = 0x21;
  }
LAB_006efe61:
  *param_3 = local_14;
switchD_006efdc8_default:
  return;
}

