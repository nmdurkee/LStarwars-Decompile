/* Ghidra analysis pseudocode, not original source.
 * ev_d43409c1beaf04de5181c7e79b8ae898b4513b764b0aa0772119c8ac5b4cb60b
 * Entry: 0x74c9c0; label: FUN_0074c9c0
 */

void FUN_0074c9c0(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_11c;
  undefined4 local_118;
  uint local_114;
  int local_110;
  int local_108;
  undefined4 local_104;
  uint local_100;
  int local_fc;
  undefined4 local_f8;
  int local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined1 local_e8 [16];
  undefined1 local_d8 [204];
  uint local_c;
  
  local_c = DAT_00829570 ^ (uint)&local_11c;
  local_f0 = param_2;
  local_ec = param_1;
  FUN_00740f30(local_d8,200);
  iVar3 = 0;
  iVar2 = 0;
  local_114 = 0xffffffff;
  local_110 = -1;
  local_108 = -1;
  uVar4 = 1;
  local_fc = 0;
  local_104 = 0;
  local_f8 = 0;
  local_f4 = 1;
  local_100 = local_100 & 0xffffff00;
  local_11c = 0;
  local_118 = 0;
  do {
    cVar1 = FUN_0074aac0(local_ec,local_f0,&local_11c);
    if (cVar1 == '\0') goto LAB_0074d3df;
    switch(iVar3) {
    case 0:
      cVar1 = FUN_0074a9a0("nu2_use");
      if (cVar1 == '\0') {
        cVar1 = FUN_0074a9a0("nu2_declare");
        if (cVar1 == '\0') {
          cVar1 = FUN_0074a9a0("nu2_anchorPoint");
          if (cVar1 == '\0') {
            cVar1 = FUN_0074a9a0("nu2_showDefine");
            if (cVar1 == '\0') {
              FUN_0074a9a0("nu2_debug");
              goto LAB_0074d3df;
            }
            iVar3 = 1;
          }
          else {
            iVar3 = 0x16;
          }
        }
        else {
          iVar3 = 7;
        }
      }
      else {
        iVar3 = 2;
      }
      break;
    case 1:
      cVar1 = FUN_0074a9a0(&DAT_0075fff8);
      if (cVar1 == '\0') {
        cVar1 = FUN_0074a9a0("false");
        if (cVar1 != '\0') {
          local_114 = local_114 & 0xffffff00;
        }
        FUN_0074c2b0(local_114);
      }
      else {
        local_114 = CONCAT31(local_114._1_3_,1);
        FUN_0074c2b0(local_114);
      }
      goto LAB_0074d3df;
    case 2:
      cVar1 = FUN_0074a9a0(&DAT_00755d74);
      if (cVar1 == '\0') goto LAB_0074d3df;
      iVar3 = 3;
      break;
    case 3:
      cVar1 = FUN_0074a9a0("vs_local");
      if (cVar1 == '\0') {
        cVar1 = FUN_0074a9a0("fs_local");
        if (cVar1 == '\0') {
          cVar1 = FUN_0074a9a0("varying");
          if (cVar1 == '\0') {
            cVar1 = FUN_0074a9a0("attribute");
            if (cVar1 == '\0') {
              cVar1 = FUN_0074a9a0("uniform");
              if (cVar1 == '\0') goto LAB_0074d3df;
              uVar4 = 0x3020;
              iVar3 = 4;
            }
            else {
              uVar4 = 0x2010;
              iVar3 = 4;
            }
          }
          else {
            uVar4 = 0x3008;
            iVar3 = 4;
          }
        }
        else {
          uVar4 = 0x1004;
          iVar3 = 4;
        }
      }
      else {
        uVar4 = 0x2002;
        iVar3 = 4;
      }
      break;
    case 4:
      FUN_0074a9a0(&DAT_007710b0);
      iVar3 = 5;
      break;
    case 5:
      cVar1 = FUN_0074a9a0(&DAT_00771534);
      if (cVar1 == '\0') {
        local_104 = FUN_0074aa40(local_e8);
        iVar3 = 6;
      }
      else {
        local_fc = local_fc + 1;
      }
      break;
    case 6:
      cVar1 = FUN_0074a9a0(&DAT_00755d70);
      if (cVar1 != '\0') {
        FUN_0074c310(uVar4,local_fc,local_104);
      }
      goto LAB_0074d3df;
    case 7:
      FUN_0074a9a0(&DAT_00755d74);
      iVar3 = 8;
      break;
    case 8:
      cVar1 = FUN_0074a9a0("vs_local");
      if (cVar1 == '\0') {
        cVar1 = FUN_0074a9a0("fs_local");
        if (cVar1 == '\0') {
          cVar1 = FUN_0074a9a0("varying");
          if (cVar1 == '\0') {
            cVar1 = FUN_0074a9a0("attribute");
            if (cVar1 == '\0') {
              cVar1 = FUN_0074a9a0("uniform");
              if (cVar1 == '\0') {
                cVar1 = FUN_0074a9a0("shared");
                if (cVar1 == '\0') goto LAB_0074d3df;
                iVar3 = 9;
                local_100 = CONCAT31(local_100._1_3_,1);
              }
              else {
                uVar4 = 0x3020;
                iVar3 = 10;
              }
            }
            else {
              uVar4 = 0x2010;
              iVar3 = 0xc;
            }
          }
          else {
            uVar4 = 0x3008;
            iVar3 = 0xc;
          }
        }
        else {
          uVar4 = 0x1004;
          iVar3 = 0xc;
        }
      }
      else {
        uVar4 = 0x2002;
        iVar3 = 0xc;
      }
      break;
    case 9:
      cVar1 = FUN_0074a9a0("uniform");
      if (cVar1 == '\0') goto LAB_0074d3df;
      uVar4 = 0x3020;
      iVar3 = 10;
      break;
    case 10:
      cVar1 = FUN_0074a9a0(&DAT_007710b0);
      if (cVar1 == '\0') {
        cVar1 = FUN_0074a9e0(&DAT_007ea324);
        if (cVar1 == '\0') {
          cVar1 = FUN_0074a9e0(&DAT_007ea31c);
          if (cVar1 != '\0') {
            local_108 = FUN_0074aa80(4);
          }
          iVar3 = 0xb;
        }
        else {
          local_110 = FUN_0074aa80(4);
          iVar3 = 0xb;
        }
      }
      else {
        iVar3 = 0xd;
        uVar4 = -(uint)((char)local_100 != '\0') & 0x4000 | 0x3020;
      }
      break;
    case 0xb:
      cVar1 = FUN_0074a9a0(&DAT_007710b0);
      if (cVar1 == '\0') {
        cVar1 = FUN_0074a9e0(&DAT_007ea324);
        if (cVar1 == '\0') {
          cVar1 = FUN_0074a9e0(&DAT_007ea31c);
          if (cVar1 != '\0') {
            local_108 = FUN_0074aa80(4);
          }
          iVar3 = 0xc;
        }
        else {
          local_110 = FUN_0074aa80(4);
          iVar3 = 0xc;
        }
      }
      else {
        iVar3 = 0xd;
        uVar4 = FUN_0074af30(local_100,-1 < local_110,-1 < local_108);
      }
      break;
    case 0xc:
      FUN_0074a9a0(&DAT_007710b0);
      if ((uVar4 >> 5 & 1) != 0) {
        uVar4 = FUN_0074af30(local_100,-1 < local_110,-1 < local_108);
      }
      iVar3 = 0xd;
      break;
    case 0xd:
      cVar1 = FUN_0074a9a0(&DAT_00763618);
      if (cVar1 == '\0') {
        cVar1 = FUN_0074a9a0(&DAT_00771da0);
        if (cVar1 == '\0') {
          cVar1 = FUN_0074a9a0(&DAT_00771d9c);
          if (cVar1 == '\0') {
            cVar1 = FUN_0074a9a0(&DAT_00771d98);
            if (cVar1 == '\0') {
              cVar1 = FUN_0074a9a0("float");
              if (cVar1 == '\0') {
                cVar1 = FUN_0074a9a0("float1");
                if (cVar1 == '\0') {
                  cVar1 = FUN_0074a9a0("float2");
                  if (cVar1 == '\0') {
                    cVar1 = FUN_0074a9a0("float3");
                    if (cVar1 == '\0') {
                      cVar1 = FUN_0074a9a0("float4");
                      if (cVar1 == '\0') {
                        cVar1 = FUN_0074a9a0("float3x3");
                        if (cVar1 == '\0') {
                          cVar1 = FUN_0074a9a0("float4x4");
                          if (cVar1 == '\0') {
                            cVar1 = FUN_0074a9a0(&DAT_007e9410);
                            if (cVar1 == '\0') {
                              cVar1 = FUN_0074a9a0("half1");
                              if (cVar1 == '\0') {
                                cVar1 = FUN_0074a9a0("half2");
                                if (cVar1 == '\0') {
                                  cVar1 = FUN_0074a9a0("half3");
                                  if (cVar1 == '\0') {
                                    cVar1 = FUN_0074a9a0("half4");
                                    if (cVar1 == '\0') {
                                      cVar1 = FUN_0074a9a0("half3x3");
                                      if (cVar1 == '\0') {
                                        cVar1 = FUN_0074a9a0("half4x4");
                                        if (cVar1 == '\0') {
                                          cVar1 = FUN_0074a9a0(&DAT_007811bc);
                                          if (cVar1 == '\0') {
                                            cVar1 = FUN_0074a9a0(&DAT_007e93b0);
                                            if (cVar1 == '\0') {
                                              cVar1 = FUN_0074a9a0(&DAT_00781208);
                                              if (cVar1 == '\0') {
                                                cVar1 = FUN_0074a9a0("sampler");
                                                if (cVar1 == '\0') {
                                                  cVar1 = FUN_0074a9a0("sampler1D");
                                                  if (cVar1 == '\0') {
                                                    cVar1 = FUN_0074a9a0("sampler2D");
                                                    if (cVar1 == '\0') {
                                                      cVar1 = FUN_0074a9a0("sampler3D");
                                                      if (cVar1 == '\0') {
                                                        cVar1 = FUN_0074a9a0("samplerCUBE");
                                                        if (cVar1 != '\0') {
                                                          iVar2 = 0x14;
                                                        }
                                                      }
                                                      else {
                                                        iVar2 = 0x13;
                                                      }
                                                    }
                                                    else {
                                                      iVar2 = 0x12;
                                                    }
                                                  }
                                                  else {
                                                    iVar2 = 0x11;
                                                  }
                                                }
                                                else {
                                                  iVar2 = 0x12;
                                                }
                                              }
                                              else {
                                                iVar2 = 0x10;
                                              }
                                            }
                                            else {
                                              iVar2 = 0x15;
                                            }
                                          }
                                          else {
                                            iVar2 = 0xf;
                                          }
                                        }
                                        else {
                                          iVar2 = 0xe;
                                        }
                                      }
                                      else {
                                        iVar2 = 0xd;
                                      }
                                    }
                                    else {
                                      iVar2 = 0xc;
                                    }
                                  }
                                  else {
                                    iVar2 = 0xb;
                                  }
                                }
                                else {
                                  iVar2 = 10;
                                }
                              }
                              else {
                                iVar2 = 9;
                              }
                            }
                            else {
                              iVar2 = 8;
                            }
                          }
                          else {
                            iVar2 = 7;
                          }
                        }
                        else {
                          iVar2 = 6;
                        }
                      }
                      else {
                        iVar2 = 5;
                      }
                    }
                    else {
                      iVar2 = 4;
                    }
                  }
                  else {
                    iVar2 = 3;
                  }
                }
                else {
                  iVar2 = 2;
                }
              }
              else {
                iVar2 = 1;
              }
            }
            else {
              iVar2 = 5;
            }
          }
          else {
            iVar2 = 4;
          }
        }
        else {
          iVar2 = 3;
        }
      }
      else {
        iVar2 = 1;
      }
      iVar3 = (-(uint)(iVar2 != 0) & 0xfffffff4) + 0x1a;
    default:
      if (iVar3 == 0x1a) {
LAB_0074d3df:
        FUN_00740e90();
        __security_check_cookie(local_c ^ (uint)&local_11c);
        return;
      }
      break;
    case 0xe:
      cVar1 = FUN_0074a9a0(&DAT_00753374);
      if (cVar1 == '\0') goto switchD_0074ca6f_caseD_11;
      iVar3 = 0xf;
      break;
    case 0xf:
      cVar1 = FUN_0074a9a0(&DAT_00753370);
      if (cVar1 == '\0') {
        local_114 = FUN_0074aa80(0);
        iVar3 = 0x10;
      }
      else {
        local_114 = 0xfffffffe;
        iVar3 = 0x11;
      }
      break;
    case 0x10:
      cVar1 = FUN_0074a9a0(&DAT_00753370);
      if (cVar1 == '\0') goto LAB_0074d3df;
      iVar3 = 0x11;
      break;
    case 0x11:
switchD_0074ca6f_caseD_11:
      cVar1 = FUN_0074a9a0(&DAT_007710b0);
      if (cVar1 == '\0') goto LAB_0074d3df;
      iVar3 = 0x12;
      break;
    case 0x12:
      local_104 = FUN_0074aa40(local_e8);
      iVar3 = 0x13;
      break;
    case 0x13:
      FUN_0074a9a0(&DAT_007710b0);
      iVar3 = 0x14;
      break;
    case 0x14:
      local_f4 = FUN_0074b3a0(&local_11c);
      if (local_f4 == 0) {
        local_f8 = FUN_0074aa40(local_e8);
      }
      iVar3 = 0x15;
      break;
    case 0x15:
      cVar1 = FUN_0074a9a0(&DAT_00755d70);
      if (cVar1 != '\0') {
        FUN_0074c3c0(uVar4,iVar2,local_114,local_104,local_f4,local_f8,local_110,local_108);
      }
      goto LAB_0074d3df;
    case 0x16:
      FUN_0074a9a0(&DAT_00755d74);
      iVar3 = 0x17;
      break;
    case 0x17:
      cVar1 = FUN_0074a9a0("uniform");
      if (cVar1 == '\0') {
        cVar1 = FUN_0074a9a0("attribute");
        if (cVar1 == '\0') {
          cVar1 = FUN_0074a9a0("varying");
          if (cVar1 == '\0') {
            cVar1 = FUN_0074a9a0("vs_local");
            if (cVar1 == '\0') {
              cVar1 = FUN_0074a9a0("fs_local");
              if (cVar1 == '\0') goto LAB_0074d3df;
              uVar4 = 0x1004;
              iVar3 = 0x18;
            }
            else {
              uVar4 = 0x2002;
              iVar3 = 0x18;
            }
          }
          else {
            uVar4 = 0x3008;
            iVar3 = 0x18;
          }
        }
        else {
          uVar4 = 0x2010;
          iVar3 = 0x18;
        }
      }
      else {
        uVar4 = 0x3020;
        iVar3 = 0x18;
      }
      break;
    case 0x18:
      cVar1 = FUN_0074a9a0(&DAT_00755d70);
      if (cVar1 != '\0') {
        FUN_0074c4d0(uVar4);
      }
      goto LAB_0074d3df;
    }
  } while( true );
}

