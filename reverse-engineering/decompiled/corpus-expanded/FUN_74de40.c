/* Ghidra pseudocode, not original source.
 * ev_9dff45b5f0eb52bcd65f8627f4ae852e719fa42162b45a2265e4036e2ee04965
 * Entry: 0x74de40; label: FUN_0074de40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0074de40(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 auStack_fc [4];
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined1 local_e8 [16];
  undefined1 local_d8 [204];
  uint local_c;
  
  local_c = DAT_00829570 ^ (uint)auStack_fc;
  local_f0 = param_2;
  FUN_00740f30(local_d8,200);
  iVar3 = 0;
  local_ec = 0;
  local_f8 = 0;
  local_f4 = 0;
  do {
    cVar1 = FUN_0074aac0(param_1,local_f0,&local_f8);
    if (cVar1 == '\0') goto LAB_0074df58;
    switch(iVar3) {
    case 0:
      cVar1 = FUN_0074a9a0("define");
      if (cVar1 == '\0') {
        cVar1 = FUN_0074a9a0("ifdef");
        if ((cVar1 == '\0') && (cVar1 = FUN_0074a9a0("ifndef"), cVar1 == '\0')) {
          cVar1 = FUN_0074a9a0("undef");
          if (cVar1 == '\0') {
            cVar1 = FUN_0074a9a0("include");
            if (cVar1 == '\0') {
              cVar1 = FUN_0074a9a0("pragma");
              if (cVar1 == '\0') {
                cVar1 = FUN_0074a9a0(&DAT_007ea3b4);
                if (cVar1 == '\0') {
                  cVar1 = FUN_0074a9a0(&DAT_007ea3ac);
                  if (cVar1 == '\0') {
                    cVar1 = FUN_0074a9a0(&DAT_007ea3a4);
                    if (cVar1 == '\0') {
                      cVar1 = FUN_0074a9a0("endif");
                      if (cVar1 != '\0') {
                        FUN_0074c230();
                      }
                    }
                    else {
                      uVar4 = FUN_0074c530(param_1,local_f0);
                      FUN_0074c1a0(uVar4);
                    }
                  }
                  else {
                    FUN_0074c180();
                  }
                }
                else {
                  uVar4 = FUN_0074c530(param_1,local_f0);
                  FUN_0074c0e0(uVar4);
                }
              }
              else {
                FUN_0074c9c0(param_1,local_f0);
              }
              goto LAB_0074df6b;
            }
            iVar3 = 4;
          }
          else {
            iVar3 = 3;
          }
        }
      }
      else {
        iVar3 = 1;
      }
      break;
    case 1:
      local_ec = FUN_0074aa40(local_e8);
      iVar3 = 2;
      break;
    case 2:
      uVar4 = FUN_0074aa40(local_e8);
      goto LAB_0074df5f;
    case 3:
      uVar4 = FUN_0074aa40(local_e8);
      FUN_0074c040(uVar4);
      goto LAB_0074df6b;
    case 4:
      iVar3 = FUN_0074aa10();
      iVar2 = FUN_0074dc90(iVar3 + 1);
      if (iVar2 != 0) {
        FUN_0074ba90(iVar2,0);
      }
      FUN_006e85b0(iVar3);
      goto LAB_0074df6b;
    default:
      if (iVar3 == 5) {
LAB_0074df58:
        if (iVar3 == 2) {
          uVar4 = 0;
LAB_0074df5f:
          FUN_0074bf60(local_ec,uVar4);
        }
LAB_0074df6b:
        FUN_00740e90();
        __security_check_cookie(local_c ^ (uint)auStack_fc);
        return;
      }
    }
  } while( true );
}

