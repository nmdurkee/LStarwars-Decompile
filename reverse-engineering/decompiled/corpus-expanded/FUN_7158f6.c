/* Ghidra pseudocode, not original source.
 * ev_d0ee5b940732101f19a6f5ed1cc5d22784960ef3dbbb4fefd6b0cd8a13c6d459
 * Entry: 0x7158f6; label: FUN_007158f6
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

char * FUN_007158f6(int param_1)

{
  if (param_1 < -0x7ff6cefd) {
    if (param_1 == -0x7ff6cefe) {
      return "CRYPT_E_ASN1_EOD";
    }
    if (param_1 < -0x7ff8f946) {
      if (param_1 == -0x7ff8f947) {
LAB_0071da80:
        return "RPC_S_OUT_OF_RESOURCES";
      }
      if (param_1 < -0x7ffb2ff4) {
        if (param_1 == -0x7ffb2ff5) {
          return "XACT_E_NOISORETAIN";
        }
        if (param_1 < -0x7ffbfe05) {
          if (param_1 == -0x7ffbfe06) {
            return "CO_E_WRONGOSFORAPP";
          }
          if (param_1 < -0x7ffd735e) {
            if (param_1 == -0x7ffd735f) {
              return "TYPE_E_OUTOFBOUNDS";
            }
            if (param_1 < -0x7ffefeed) {
              if (param_1 == -0x7ffefeee) {
                return "RPC_E_INVALID_EXTENSION";
              }
              if (param_1 < -0x7fffbfd5) {
                if (param_1 == -0x7fffbfd6) {
                  return "CO_E_SERVER_INIT_TIMEOUT";
                }
                if (param_1 < -0x7fffbfea) {
                  if (param_1 == -0x7fffbfeb) {
                    return "CO_E_WRONG_SERVER_IDENTITY";
                  }
                  if (param_1 < -0x7fffbff5) {
                    if (param_1 == -0x7fffbff6) {
                      return "CO_E_INIT_RPC_CHANNEL";
                    }
                    if (param_1 < -0x7fffbffa) {
                      if (param_1 == -0x7fffbffb) {
                        return "E_FAIL";
                      }
                      if (param_1 == -0x7ffffff6) {
                        return "E_PENDING";
                      }
                      if (param_1 == -0x7fffbfff) {
                        return "E_NOTIMPL";
                      }
                      if (param_1 == -0x7fffbffe) {
                        return "E_NOINTERFACE";
                      }
                      if (param_1 == -0x7fffbffd) {
                        return "E_POINTER";
                      }
                      if (param_1 == -0x7fffbffc) {
                        return "E_ABORT";
                      }
                    }
                    else {
                      if (param_1 == -0x7fffbffa) {
                        return "CO_E_INIT_TLS";
                      }
                      if (param_1 == -0x7fffbff9) {
                        return "CO_E_INIT_SHARED_ALLOCATOR";
                      }
                      if (param_1 == -0x7fffbff8) {
                        return "CO_E_INIT_MEMORY_ALLOCATOR";
                      }
                      if (param_1 == -0x7fffbff7) {
                        return "CO_E_INIT_CLASS_CACHE";
                      }
                    }
                  }
                  else {
                    switch(param_1) {
                    case -0x7fffbff5:
                      return "CO_E_INIT_TLS_SET_CHANNEL_CONTROL";
                    case -0x7fffbff4:
                      return "CO_E_INIT_TLS_CHANNEL_CONTROL";
                    case -0x7fffbff3:
                      return "CO_E_INIT_UNACCEPTED_USER_ALLOCATOR";
                    case -0x7fffbff2:
                      return "CO_E_INIT_SCM_MUTEX_EXISTS";
                    case -0x7fffbff1:
                      return "CO_E_INIT_SCM_FILE_MAPPING_EXISTS";
                    case -0x7fffbff0:
                      return "CO_E_INIT_SCM_MAP_VIEW_OF_FILE";
                    case -0x7fffbfef:
                      return "CO_E_INIT_SCM_EXEC_FAILURE";
                    case -0x7fffbfee:
                      return "CO_E_INIT_ONLY_SINGLE_THREADED";
                    case -0x7fffbfed:
                      return "CO_E_CANT_REMOTE";
                    case -0x7fffbfec:
                      return "CO_E_BAD_SERVER_NAME";
                    }
                  }
                }
                else {
                  switch(param_1) {
                  case -0x7fffbfea:
                    return "CO_E_OLE1DDE_DISABLED";
                  case -0x7fffbfe9:
                    return "CO_E_RUNAS_SYNTAX";
                  case -0x7fffbfe8:
                    return "CO_E_CREATEPROCESS_FAILURE";
                  case -0x7fffbfe7:
                    return "CO_E_RUNAS_CREATEPROCESS_FAILURE";
                  case -0x7fffbfe6:
                    return "CO_E_RUNAS_LOGON_FAILURE";
                  case -0x7fffbfe5:
                    return "CO_E_LAUNCH_PERMSSION_DENIED";
                  case -0x7fffbfe4:
                    return "CO_E_START_SERVICE_FAILURE";
                  case -0x7fffbfe3:
                    return "CO_E_REMOTE_COMMUNICATION_FAILURE";
                  case -0x7fffbfe2:
                    return "CO_E_SERVER_START_TIMEOUT";
                  case -0x7fffbfe1:
                    return "CO_E_CLSREG_INCONSISTENT";
                  case -0x7fffbfe0:
                    return "CO_E_IIDREG_INCONSISTENT";
                  case -0x7fffbfdf:
                    return "CO_E_NOT_SUPPORTED";
                  case -0x7fffbfde:
                    return "CO_E_RELOAD_DLL";
                  case -0x7fffbfdd:
                    return "CO_E_MSI_ERROR";
                  case -0x7fffbfdc:
                    return "CO_E_ATTEMPT_TO_CREATE_OUTSIDE_CLIENT_CONTEXT";
                  case -0x7fffbfdb:
                    return "CO_E_SERVER_PAUSED";
                  case -0x7fffbfda:
                    return "CO_E_SERVER_NOT_PAUSED";
                  case -0x7fffbfd9:
                    return "CO_E_CLASS_DISABLED";
                  case -0x7fffbfd8:
                    return "CO_E_CLRNOTAVAILABLE";
                  case -0x7fffbfd7:
                    return "CO_E_ASYNC_WORK_REJECTED";
                  }
                }
              }
              else if (param_1 < -0x7ffeffef) {
                if (param_1 == -0x7ffefff0) {
                  return "RPC_E_INVALID_PARAMETER";
                }
                if (param_1 < -0x7ffefffa) {
                  if (param_1 == -0x7ffefffb) {
                    return "RPC_E_CANTCALLOUT_INEXTERNALCALL";
                  }
                  if (param_1 < -0x7fff0000) {
                    if (param_1 == -0x7fff0001) {
                      return "E_UNEXPECTED";
                    }
                    if (param_1 == -0x7fffbfd5) {
                      return "CO_E_NO_SECCTX_IN_ACTIVATE";
                    }
                    if (param_1 == -0x7fffbfd0) {
                      return "CO_E_TRACKER_CONFIG";
                    }
                    if (param_1 == -0x7fffbfcf) {
                      return "CO_E_THREADPOOL_CONFIG";
                    }
                    if (param_1 == -0x7fffbfce) {
                      return "CO_E_SXS_CONFIG";
                    }
                    if (param_1 == -0x7fffbfcd) {
                      return "CO_E_MALFORMED_SPN";
                    }
                  }
                  else {
                    if (param_1 == -0x7ffeffff) {
                      return "RPC_E_CALL_REJECTED";
                    }
                    if (param_1 == -0x7ffefffe) {
                      return "RPC_E_CALL_CANCELED";
                    }
                    if (param_1 == -0x7ffefffd) {
                      return "RPC_E_CANTPOST_INSENDCALL";
                    }
                    if (param_1 == -0x7ffefffc) {
                      return "RPC_E_CANTCALLOUT_INASYNCCALL";
                    }
                  }
                }
                else {
                  switch(param_1) {
                  case -0x7ffefffa:
                    return "RPC_E_CONNECTION_TERMINATED";
                  case -0x7ffefff9:
                    return "RPC_E_SERVER_DIED";
                  case -0x7ffefff8:
                    return "RPC_E_CLIENT_DIED";
                  case -0x7ffefff7:
                    return "RPC_E_INVALID_DATAPACKET";
                  case -0x7ffefff6:
                    return "RPC_E_CANTTRANSMIT_CALL";
                  case -0x7ffefff5:
                    return "RPC_E_CLIENT_CANTMARSHAL_DATA";
                  case -0x7ffefff4:
                    return "RPC_E_CLIENT_CANTUNMARSHAL_DATA";
                  case -0x7ffefff3:
                    return "RPC_E_SERVER_CANTMARSHAL_DATA";
                  case -0x7ffefff2:
                    return "RPC_E_SERVER_CANTUNMARSHAL_DATA";
                  case -0x7ffefff1:
                    return "RPC_E_INVALID_DATA";
                  }
                }
              }
              else if (param_1 < -0x7ffefef7) {
                if (param_1 == -0x7ffefef8) {
                  return "RPC_E_DISCONNECTED";
                }
                if (param_1 < -0x7ffefefc) {
                  if (param_1 == -0x7ffefefd) {
                    return "RPC_E_NOT_REGISTERED";
                  }
                  if (param_1 == -0x7ffeffef) {
                    return "RPC_E_CANTCALLOUT_AGAIN";
                  }
                  if (param_1 == -0x7ffeffee) {
                    return "RPC_E_SERVER_DIED_DNE";
                  }
                  if (param_1 == -0x7ffeff00) {
                    return "RPC_E_SYS_CALL_FAILED";
                  }
                  if (param_1 == -0x7ffefeff) {
                    return "RPC_E_OUT_OF_RESOURCES";
                  }
                  if (param_1 == -0x7ffefefe) {
                    return "RPC_E_ATTEMPTED_MULTITHREAD";
                  }
                }
                else {
                  if (param_1 == -0x7ffefefc) {
                    return "RPC_E_FAULT";
                  }
                  if (param_1 == -0x7ffefefb) {
                    return "RPC_E_SERVERFAULT";
                  }
                  if (param_1 == -0x7ffefefa) {
                    return "RPC_E_CHANGED_MODE";
                  }
                  if (param_1 == -0x7ffefef9) {
                    return "RPC_E_INVALIDMETHOD";
                  }
                }
              }
              else {
                switch(param_1) {
                case -0x7ffefef7:
                  return "RPC_E_RETRY";
                case -0x7ffefef6:
                  return "RPC_E_SERVERCALL_RETRYLATER";
                case -0x7ffefef5:
                  return "RPC_E_SERVERCALL_REJECTED";
                case -0x7ffefef4:
                  return "RPC_E_INVALID_CALLDATA";
                case -0x7ffefef3:
                  return "RPC_E_CANTCALLOUT_ININPUTSYNCCALL";
                case -0x7ffefef2:
                  return "RPC_E_WRONG_THREAD";
                case -0x7ffefef1:
                  return "RPC_E_THREAD_NOT_INIT";
                case -0x7ffefef0:
                  return "RPC_E_VERSION_MISMATCH";
                case -0x7ffefeef:
                  return "RPC_E_INVALID_HEADER";
                }
              }
            }
            else if (param_1 < -0x7ffe0000) {
              if (param_1 == -0x7ffe0001) {
                return "RPC_E_UNEXPECTED";
              }
              switch(param_1) {
              case -0x7ffefeed:
                return "RPC_E_INVALID_IPID";
              case -0x7ffefeec:
                return "RPC_E_INVALID_OBJECT";
              case -0x7ffefeeb:
                return "RPC_S_CALLPENDING";
              case -0x7ffefeea:
                return "RPC_S_WAITONTIMER";
              case -0x7ffefee9:
                return "RPC_E_CALL_COMPLETE";
              case -0x7ffefee8:
                return "RPC_E_UNSECURE_CALL";
              case -0x7ffefee7:
                return "RPC_E_TOO_LATE";
              case -0x7ffefee6:
                return "RPC_E_NO_GOOD_SECURITY_PACKAGES";
              case -0x7ffefee5:
                return "RPC_E_ACCESS_DENIED";
              case -0x7ffefee4:
                return "RPC_E_REMOTE_DISABLED";
              case -0x7ffefee3:
                return "RPC_E_INVALID_OBJREF";
              case -0x7ffefee2:
                return "RPC_E_NO_CONTEXT";
              case -0x7ffefee1:
                return "RPC_E_TIMEOUT";
              case -0x7ffefee0:
                return "RPC_E_NO_SYNC";
              case -0x7ffefedf:
                return "RPC_E_FULLSIC_REQUIRED";
              case -0x7ffefede:
                return "RPC_E_INVALID_STD_NAME";
              case -0x7ffefedd:
                return "CO_E_FAILEDTOIMPERSONATE";
              case -0x7ffefedc:
                return "CO_E_FAILEDTOGETSECCTX";
              case -0x7ffefedb:
                return "CO_E_FAILEDTOOPENTHREADTOKEN";
              case -0x7ffefeda:
                return "CO_E_FAILEDTOGETTOKENINFO";
              case -0x7ffefed9:
                return "CO_E_TRUSTEEDOESNTMATCHCLIENT";
              case -0x7ffefed8:
                return "CO_E_FAILEDTOQUERYCLIENTBLANKET";
              case -0x7ffefed7:
                return "CO_E_FAILEDTOSETDACL";
              case -0x7ffefed6:
                return "CO_E_ACCESSCHECKFAILED";
              case -0x7ffefed5:
                return "CO_E_NETACCESSAPIFAILED";
              case -0x7ffefed4:
                return "CO_E_WRONGTRUSTEENAMESYNTAX";
              case -0x7ffefed3:
                return "CO_E_INVALIDSID";
              case -0x7ffefed2:
                return "CO_E_CONVERSIONFAILED";
              case -0x7ffefed1:
                return "CO_E_NOMATCHINGSIDFOUND";
              case -0x7ffefed0:
                return "CO_E_LOOKUPACCSIDFAILED";
              case -0x7ffefecf:
                return "CO_E_NOMATCHINGNAMEFOUND";
              case -0x7ffefece:
                return "CO_E_LOOKUPACCNAMEFAILED";
              case -0x7ffefecd:
                return "CO_E_SETSERLHNDLFAILED";
              case -0x7ffefecc:
                return "CO_E_FAILEDTOGETWINDIR";
              case -0x7ffefecb:
                return "CO_E_PATHTOOLONG";
              case -0x7ffefeca:
                return "CO_E_FAILEDTOGENUUID";
              case -0x7ffefec9:
                return "CO_E_FAILEDTOCREATEFILE";
              case -0x7ffefec8:
                return "CO_E_FAILEDTOCLOSEHANDLE";
              case -0x7ffefec7:
                return "CO_E_EXCEEDSYSACLLIMIT";
              case -0x7ffefec6:
                return "CO_E_ACESINWRONGORDER";
              case -0x7ffefec5:
                return "CO_E_INCOMPATIBLESTREAMVERSION";
              case -0x7ffefec4:
                return "CO_E_FAILEDTOOPENPROCESSTOKEN";
              case -0x7ffefec3:
                return "CO_E_DECODEFAILED";
              case -0x7ffefec1:
                return "CO_E_ACNOTINITIALIZED";
              case -0x7ffefec0:
                return "CO_E_CANCEL_DISABLED";
              }
            }
            else if (param_1 < -0x7ffd7fe9) {
              if (param_1 == -0x7ffd7fea) {
                return "TYPE_E_BUFFERTOOSMALL";
              }
              switch(param_1) {
              case -0x7ffdffff:
                return "DISP_E_UNKNOWNINTERFACE";
              case -0x7ffdfffd:
                return "DISP_E_MEMBERNOTFOUND";
              case -0x7ffdfffc:
                return "DISP_E_PARAMNOTFOUND";
              case -0x7ffdfffb:
                return "DISP_E_TYPEMISMATCH";
              case -0x7ffdfffa:
                return "DISP_E_UNKNOWNNAME";
              case -0x7ffdfff9:
                return "DISP_E_NONAMEDARGS";
              case -0x7ffdfff8:
                return "DISP_E_BADVARTYPE";
              case -0x7ffdfff7:
                return "DISP_E_EXCEPTION";
              case -0x7ffdfff6:
                return "DISP_E_OVERFLOW";
              case -0x7ffdfff5:
                return "DISP_E_BADINDEX";
              case -0x7ffdfff4:
                return "DISP_E_UNKNOWNLCID";
              case -0x7ffdfff3:
                return "DISP_E_ARRAYISLOCKED";
              case -0x7ffdfff2:
                return "DISP_E_BADPARAMCOUNT";
              case -0x7ffdfff1:
                return "DISP_E_PARAMNOTOPTIONAL";
              case -0x7ffdfff0:
                return "DISP_E_BADCALLEE";
              case -0x7ffdffef:
                return "DISP_E_NOTACOLLECTION";
              case -0x7ffdffee:
                return "DISP_E_DIVBYZERO";
              case -0x7ffdffed:
                return "DISP_E_BUFFERTOOSMALL";
              }
            }
            else if (param_1 < -0x7ffd7fd4) {
              if (param_1 == -0x7ffd7fd5) {
                return "TYPE_E_ELEMENTNOTFOUND";
              }
              switch(param_1) {
              case -0x7ffd7fe9:
                return "TYPE_E_FIELDNOTFOUND";
              case -0x7ffd7fe8:
                return "TYPE_E_INVDATAREAD";
              case -0x7ffd7fe7:
                return "TYPE_E_UNSUPFORMAT";
              case -0x7ffd7fe4:
                return "TYPE_E_REGISTRYACCESS";
              case -0x7ffd7fe3:
                return "TYPE_E_LIBNOTREGISTERED";
              case -0x7ffd7fd9:
                return "TYPE_E_UNDEFINEDTYPE";
              case -0x7ffd7fd8:
                return "TYPE_E_QUALIFIEDNAMEDISALLOWED";
              case -0x7ffd7fd7:
                return "TYPE_E_INVALIDSTATE";
              case -0x7ffd7fd6:
                return "TYPE_E_WRONGTYPEKIND";
              }
            }
            else if (param_1 < -0x7ffd7742) {
              if (param_1 == -0x7ffd7743) {
                return "TYPE_E_BADMODULEKIND";
              }
              if (param_1 == -0x7ffd7fd4) {
                return "TYPE_E_AMBIGUOUSNAME";
              }
              if (param_1 == -0x7ffd7fd3) {
                return "TYPE_E_NAMECONFLICT";
              }
              if (param_1 == -0x7ffd7fd2) {
                return "TYPE_E_UNKNOWNLCID";
              }
              if (param_1 == -0x7ffd7fd1) {
                return "TYPE_E_DLLFUNCTIONNOTFOUND";
              }
            }
            else {
              if (param_1 == -0x7ffd773b) {
                return "TYPE_E_SIZETOOBIG";
              }
              if (param_1 == -0x7ffd773a) {
                return "TYPE_E_DUPLICATEID";
              }
              if (param_1 == -0x7ffd7731) {
                return "TYPE_E_INVALIDID";
              }
              if (param_1 == -0x7ffd7360) {
                return "TYPE_E_TYPEMISMATCH";
              }
            }
          }
          else if (param_1 < -0x7ffbfef0) {
            if (param_1 == -0x7ffbfef1) {
              return "DRAGDROP_E_LAST";
            }
            if (param_1 < -0x7ffcfeed) {
              if (param_1 == -0x7ffcfeee) {
                return "STG_E_NOTSIMPLEFORMAT";
              }
              if (param_1 < -0x7ffcffa8) {
                if (param_1 == -0x7ffcffa9) {
                  return "STG_E_INVALIDPARAMETER";
                }
                if (param_1 < -0x7ffcfff9) {
                  if (param_1 == -0x7ffcfffa) {
                    return "STG_E_INVALIDHANDLE";
                  }
                  if (param_1 < -0x7ffcfffe) {
                    if (param_1 == -0x7ffcffff) {
                      return "STG_E_INVALIDFUNCTION";
                    }
                    if (param_1 == -0x7ffd735e) {
                      return "TYPE_E_IOERROR";
                    }
                    if (param_1 == -0x7ffd735d) {
                      return "TYPE_E_CANTCREATETMPFILE";
                    }
                    if (param_1 == -0x7ffd63b6) {
                      return "TYPE_E_CANTLOADLIBRARY";
                    }
                    if (param_1 == -0x7ffd637d) {
                      return "TYPE_E_INCONSISTENTPROPFUNCS";
                    }
                    if (param_1 == -0x7ffd637c) {
                      return "TYPE_E_CIRCULARTYPE";
                    }
                  }
                  else {
                    if (param_1 == -0x7ffcfffe) {
                      return "STG_E_FILENOTFOUND";
                    }
                    if (param_1 == -0x7ffcfffd) {
                      return "STG_E_PATHNOTFOUND";
                    }
                    if (param_1 == -0x7ffcfffc) {
                      return "STG_E_TOOMANYOPENFILES";
                    }
                    if (param_1 == -0x7ffcfffb) {
                      return "STG_E_ACCESSDENIED";
                    }
                  }
                }
                else if (param_1 < -0x7ffcffe2) {
                  if (param_1 == -0x7ffcffe3) {
                    return "STG_E_WRITEFAULT";
                  }
                  if (param_1 == -0x7ffcfff8) {
                    return "STG_E_INSUFFICIENTMEMORY";
                  }
                  if (param_1 == -0x7ffcfff7) {
                    return "STG_E_INVALIDPOINTER";
                  }
                  if (param_1 == -0x7ffcffee) {
                    return "STG_E_NOMOREFILES";
                  }
                  if (param_1 == -0x7ffcffed) {
                    return "STG_E_DISKISWRITEPROTECTED";
                  }
                  if (param_1 == -0x7ffcffe7) {
                    return "STG_E_SEEKERROR";
                  }
                }
                else {
                  if (param_1 == -0x7ffcffe2) {
                    return "STG_E_READFAULT";
                  }
                  if (param_1 == -0x7ffcffe0) {
                    return "STG_E_SHAREVIOLATION";
                  }
                  if (param_1 == -0x7ffcffdf) {
                    return "STG_E_LOCKVIOLATION";
                  }
                  if (param_1 == -0x7ffcffb0) {
                    return "STG_E_FILEALREADYEXISTS";
                  }
                }
              }
              else if (param_1 < -0x7ffcfefd) {
                if (param_1 == -0x7ffcfefe) {
                  return "STG_E_REVERTED";
                }
                if (param_1 < -0x7ffcff02) {
                  if (param_1 == -0x7ffcff03) {
                    return "STG_E_UNKNOWN";
                  }
                  if (param_1 == -0x7ffcff90) {
                    return "STG_E_MEDIUMFULL";
                  }
                  if (param_1 == -0x7ffcff10) {
                    return "STG_E_PROPSETMISMATCHED";
                  }
                  if (param_1 == -0x7ffcff06) {
                    return "STG_E_ABNORMALAPIEXIT";
                  }
                  if (param_1 == -0x7ffcff05) {
                    return "STG_E_INVALIDHEADER";
                  }
                  if (param_1 == -0x7ffcff04) {
                    return "STG_E_INVALIDNAME";
                  }
                }
                else {
                  if (param_1 == -0x7ffcff02) {
                    return "STG_E_UNIMPLEMENTEDFUNCTION";
                  }
                  if (param_1 == -0x7ffcff01) {
                    return "STG_E_INVALIDFLAG";
                  }
                  if (param_1 == -0x7ffcff00) {
                    return "STG_E_INUSE";
                  }
                  if (param_1 == -0x7ffcfeff) {
                    return "STG_E_NOTCURRENT";
                  }
                }
              }
              else {
                switch(param_1) {
                case -0x7ffcfefd:
                  return "STG_E_CANTSAVE";
                case -0x7ffcfefc:
                  return "STG_E_OLDFORMAT";
                case -0x7ffcfefb:
                  return "STG_E_OLDDLL";
                case -0x7ffcfefa:
                  return "STG_E_SHAREREQUIRED";
                case -0x7ffcfef9:
                  return "STG_E_NOTFILEBASEDSTORAGE";
                case -0x7ffcfef8:
                  return "STG_E_EXTANTMARSHALLINGS";
                case -0x7ffcfef7:
                  return "STG_E_DOCFILECORRUPT";
                case -0x7ffcfef0:
                  return "STG_E_BADBASEADDRESS";
                case -0x7ffcfeef:
                  return "STG_E_DOCFILETOOLARGE";
                }
              }
            }
            else if (param_1 < -0x7ffbfff3) {
              if (param_1 == -0x7ffbfff4) {
                return "OLE_E_PROMPTSAVECANCELLED";
              }
              if (param_1 < -0x7ffbfffe) {
                if (param_1 == -0x7ffbffff) {
                  return "OLE_E_ADVF";
                }
                if (param_1 < -0x7ffcfcf7) {
                  if (param_1 == -0x7ffcfcf8) {
                    return "STG_E_CSS_KEY_NOT_ESTABLISHED";
                  }
                  if (param_1 == -0x7ffcfdff) {
                    return "STG_E_INCOMPLETE";
                  }
                  if (param_1 == -0x7ffcfdfe) {
                    return "STG_E_TERMINATED";
                  }
                  if (param_1 == -0x7ffcfcfb) {
                    return "STG_E_STATUS_COPY_PROTECTION_FAILURE";
                  }
                  if (param_1 == -0x7ffcfcfa) {
                    return "STG_E_CSS_AUTHENTICATION_FAILURE";
                  }
                  if (param_1 == -0x7ffcfcf9) {
                    return "STG_E_CSS_KEY_NOT_PRESENT";
                  }
                }
                else {
                  if (param_1 == -0x7ffcfcf7) {
                    return "STG_E_CSS_SCRAMBLED_SECTOR";
                  }
                  if (param_1 == -0x7ffcfcf6) {
                    return "STG_E_CSS_REGION_MISMATCH";
                  }
                  if (param_1 == -0x7ffcfcf5) {
                    return "STG_E_RESETS_EXHAUSTED";
                  }
                  if (param_1 == -0x7ffc0000) {
                    return "OLE_E_FIRST";
                  }
                }
              }
              else {
                switch(param_1) {
                case -0x7ffbfffe:
                  return "OLE_E_ENUM_NOMORE";
                case -0x7ffbfffd:
                  return "OLE_E_ADVISENOTSUPPORTED";
                case -0x7ffbfffc:
                  return "OLE_E_NOCONNECTION";
                case -0x7ffbfffb:
                  return "OLE_E_NOTRUNNING";
                case -0x7ffbfffa:
                  return "OLE_E_NOCACHE";
                case -0x7ffbfff9:
                  return "OLE_E_BLANK";
                case -0x7ffbfff8:
                  return "OLE_E_CLASSDIFF";
                case -0x7ffbfff7:
                  return "OLE_E_CANT_GETMONIKER";
                case -0x7ffbfff6:
                  return "OLE_E_CANT_BINDTOSOURCE";
                case -0x7ffbfff5:
                  return "OLE_E_STATIC";
                }
              }
            }
            else if (param_1 < -0x7ffbff97) {
              if (param_1 == -0x7ffbff98) {
                return "DV_E_LINDEX";
              }
              if (param_1 < -0x7ffbffed) {
                if (param_1 == -0x7ffbffee) {
                  return "OLE_E_NOSTORAGE";
                }
                if (param_1 == -0x7ffbfff3) {
                  return "OLE_E_INVALIDRECT";
                }
                if (param_1 == -0x7ffbfff2) {
                  return "OLE_E_WRONGCOMPOBJ";
                }
                if (param_1 == -0x7ffbfff1) {
                  return "OLE_E_INVALIDHWND";
                }
                if (param_1 == -0x7ffbfff0) {
                  return "OLE_E_NOT_INPLACEACTIVE";
                }
                if (param_1 == -0x7ffbffef) {
                  return "OLE_E_CANTCONVERT";
                }
              }
              else {
                if (param_1 == -0x7ffbff9c) {
                  return "DV_E_FORMATETC";
                }
                if (param_1 == -0x7ffbff9b) {
                  return "DV_E_DVTARGETDEVICE";
                }
                if (param_1 == -0x7ffbff9a) {
                  return "DV_E_STGMEDIUM";
                }
                if (param_1 == -0x7ffbff99) {
                  return "DV_E_STATDATA";
                }
              }
            }
            else if (param_1 < -0x7ffbff92) {
              if (param_1 == -0x7ffbff93) {
                return "DV_E_NOIVIEWOBJECT";
              }
              if (param_1 == -0x7ffbff97) {
                return "DV_E_TYMED";
              }
              if (param_1 == -0x7ffbff96) {
                return "DV_E_CLIPFORMAT";
              }
              if (param_1 == -0x7ffbff95) {
                return "DV_E_DVASPECT";
              }
              if (param_1 == -0x7ffbff94) {
                return "DV_E_DVTARGETDEVICE_SIZE";
              }
            }
            else {
              if (param_1 == -0x7ffbff01) {
                return "OLE_E_LAST";
              }
              if (param_1 == -0x7ffbff00) {
                return "DRAGDROP_E_FIRST";
              }
              if (param_1 == -0x7ffbfeff) {
                return "DRAGDROP_E_ALREADYREGISTERED";
              }
              if (param_1 == -0x7ffbfefe) {
                return "DRAGDROP_E_INVALIDHWND";
              }
            }
          }
          else {
            switch(param_1) {
            case -0x7ffbfef0:
              return "CLASSFACTORY_E_FIRST";
            case -0x7ffbfeef:
              return "CLASS_E_CLASSNOTAVAILABLE";
            case -0x7ffbfeee:
              return "CLASS_E_NOTLICENSED";
            case -0x7ffbfee1:
              return "CLASSFACTORY_E_LAST";
            case -0x7ffbfee0:
              return "MARSHAL_E_FIRST";
            case -0x7ffbfed1:
              return "MARSHAL_E_LAST";
            case -0x7ffbfed0:
              return "DATA_E_FIRST";
            case -0x7ffbfec1:
              return "DATA_E_LAST";
            case -0x7ffbfec0:
              return "VIEW_E_FIRST";
            case -0x7ffbfeb1:
              return "VIEW_E_LAST";
            case -0x7ffbfeb0:
              return "REGDB_E_FIRST";
            case -0x7ffbfeaf:
              return "REGDB_E_WRITEREGDB";
            case -0x7ffbfeae:
              return "REGDB_E_KEYMISSING";
            case -0x7ffbfead:
              return "REGDB_E_INVALIDVALUE";
            case -0x7ffbfeac:
              return "REGDB_E_CLASSNOTREG";
            case -0x7ffbfeab:
              return "REGDB_E_IIDNOTREG";
            case -0x7ffbfeaa:
              return "REGDB_E_BADTHREADINGMODEL";
            case -0x7ffbfea1:
              return "REGDB_E_LAST";
            case -0x7ffbfea0:
              return "CAT_E_FIRST";
            case -0x7ffbfe9f:
              return "CAT_E_LAST";
            case -0x7ffbfe9c:
              return "CS_E_FIRST";
            case -0x7ffbfe9b:
              return "CS_E_NOT_DELETABLE";
            case -0x7ffbfe9a:
              return "CS_E_CLASS_NOTFOUND";
            case -0x7ffbfe99:
              return "CS_E_INVALID_VERSION";
            case -0x7ffbfe98:
              return "CS_E_NO_CLASSSTORE";
            case -0x7ffbfe97:
              return "CS_E_OBJECT_NOTFOUND";
            case -0x7ffbfe96:
              return "CS_E_OBJECT_ALREADY_EXISTS";
            case -0x7ffbfe95:
              return "CS_E_INVALID_PATH";
            case -0x7ffbfe94:
              return "CS_E_NETWORK_ERROR";
            case -0x7ffbfe93:
              return "CS_E_ADMIN_LIMIT_EXCEEDED";
            case -0x7ffbfe92:
              return "CS_E_SCHEMA_MISMATCH";
            case -0x7ffbfe91:
              return "CS_E_LAST";
            case -0x7ffbfe90:
              return "CACHE_E_FIRST";
            case -0x7ffbfe81:
              return "CACHE_E_LAST";
            case -0x7ffbfe80:
              return "OLEOBJ_E_FIRST";
            case -0x7ffbfe7f:
              return "OLEOBJ_E_INVALIDVERB";
            case -0x7ffbfe71:
              return "OLEOBJ_E_LAST";
            case -0x7ffbfe70:
              return "CLIENTSITE_E_FIRST";
            case -0x7ffbfe61:
              return "CLIENTSITE_E_LAST";
            case -0x7ffbfe60:
              return "INPLACE_E_NOTUNDOABLE";
            case -0x7ffbfe5f:
              return "INPLACE_E_NOTOOLSPACE";
            case -0x7ffbfe51:
              return "INPLACE_E_LAST";
            case -0x7ffbfe50:
              return "ENUM_E_FIRST";
            case -0x7ffbfe41:
              return "ENUM_E_LAST";
            case -0x7ffbfe40:
              return "CONVERT10_E_FIRST";
            case -0x7ffbfe3f:
              return "CONVERT10_E_OLESTREAM_PUT";
            case -0x7ffbfe3e:
              return "CONVERT10_E_OLESTREAM_FMT";
            case -0x7ffbfe3d:
              return "CONVERT10_E_OLESTREAM_BITMAP_TO_DIB";
            case -0x7ffbfe3c:
              return "CONVERT10_E_STG_FMT";
            case -0x7ffbfe3b:
              return "CONVERT10_E_STG_NO_STD_STREAM";
            case -0x7ffbfe3a:
              return "CONVERT10_E_STG_DIB_TO_BITMAP";
            case -0x7ffbfe31:
              return "CONVERT10_E_LAST";
            case -0x7ffbfe30:
              return "CLIPBRD_E_FIRST";
            case -0x7ffbfe2f:
              return "CLIPBRD_E_CANT_EMPTY";
            case -0x7ffbfe2e:
              return "CLIPBRD_E_CANT_SET";
            case -0x7ffbfe2d:
              return "CLIPBRD_E_BAD_DATA";
            case -0x7ffbfe2c:
              return "CLIPBRD_E_CANT_CLOSE";
            case -0x7ffbfe21:
              return "CLIPBRD_E_LAST";
            case -0x7ffbfe20:
              return "MK_E_FIRST";
            case -0x7ffbfe1f:
              return "MK_E_EXCEEDEDDEADLINE";
            case -0x7ffbfe1e:
              return "MK_E_NEEDGENERIC";
            case -0x7ffbfe1d:
              return "MK_E_UNAVAILABLE";
            case -0x7ffbfe1c:
              return "MK_E_SYNTAX";
            case -0x7ffbfe1b:
              return "MK_E_NOOBJECT";
            case -0x7ffbfe1a:
              return "MK_E_INVALIDEXTENSION";
            case -0x7ffbfe19:
              return "MK_E_INTERMEDIATEINTERFACENOTSUPPORTED";
            case -0x7ffbfe18:
              return "MK_E_NOTBINDABLE";
            case -0x7ffbfe17:
              return "MK_E_NOTBOUND";
            case -0x7ffbfe16:
              return "MK_E_CANTOPENFILE";
            case -0x7ffbfe15:
              return "MK_E_MUSTBOTHERUSER";
            case -0x7ffbfe14:
              return "MK_E_NOINVERSE";
            case -0x7ffbfe13:
              return "MK_E_NOSTORAGE";
            case -0x7ffbfe12:
              return "MK_E_NOPREFIX";
            case -0x7ffbfe11:
              return "MK_E_LAST";
            case -0x7ffbfe10:
              return "CO_E_NOTINITIALIZED";
            case -0x7ffbfe0f:
              return "CO_E_ALREADYINITIALIZED";
            case -0x7ffbfe0e:
              return "CO_E_CANTDETERMINECLASS";
            case -0x7ffbfe0d:
              return "CO_E_CLASSSTRING";
            case -0x7ffbfe0c:
              return "CO_E_IIDSTRING";
            case -0x7ffbfe0b:
              return "CO_E_APPNOTFOUND";
            case -0x7ffbfe0a:
              return "CO_E_APPSINGLEUSE";
            case -0x7ffbfe09:
              return "CO_E_ERRORINAPP";
            case -0x7ffbfe08:
              return "CO_E_DLLNOTFOUND";
            case -0x7ffbfe07:
              return "CO_E_ERRORINDLL";
            }
          }
        }
        else if (param_1 < -0x7ffbfc0d) {
          if (param_1 == -0x7ffbfc0e) {
            return "VFW_E_BAD_KEY";
          }
          if (param_1 + 0x7ffbfe05U < 0x10b) {
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
            switch(*(undefined1 *)(param_1 + -0x7f91e43f)) {
            case 0:
              return "CO_E_OBJNOTREG";
            case 1:
              return "CO_E_OBJISREG";
            case 2:
              return "CO_E_OBJNOTCONNECTED";
            case 3:
              return "CO_E_APPDIDNTREG";
            case 4:
              return "CO_E_RELEASED";
            case 5:
              return "DIERR_INSUFFICIENTPRIVS & VFW_E_INVALIDMEDIATYPE";
            case 6:
              return "DIERR_DEVICEFULL & VFW_E_INVALIDSUBTYPE & DMO_E_INVALIDSTREAMINDEX";
            case 7:
              return "DIERR_MOREDATA & VFW_E_NEED_OWNER & DMO_E_INVALIDTYPE";
            case 8:
              return "DIERR_NOTDOWNLOADED & VFW_E_ENUM_OUT_OF_SYNC & DMO_E_TYPE_NOT_SET";
            case 9:
              return "DIERR_HASEFFECTS & VFW_E_ALREADY_CONNECTED & DMO_E_NOTACCEPTING";
            case 10:
              return "DIERR_NOTEXCLUSIVEACQUIRED & VFW_E_FILTER_ACTIVE & DMO_E_TYPE_NOT_ACCEPTED";
            case 0xb:
              return "DIERR_INCOMPLETEEFFECT & VFW_E_NO_TYPES & DMO_E_NO_MORE_ITEMS";
            case 0xc:
              return "DIERR_NOTBUFFERED & VFW_E_NO_ACCEPTABLE_TYPES";
            case 0xd:
              return "DIERR_EFFECTPLAYING & VFW_E_INVALID_DIRECTION";
            case 0xe:
              return "DIERR_UNPLUGGED & VFW_E_NOT_CONNECTED";
            case 0xf:
              return "DIERR_REPORTFULL & VFW_E_NO_ALLOCATOR";
            case 0x10:
              return "DIERR_MAPFILEFAIL & VFW_E_RUNTIME_ERROR";
            case 0x11:
              return "VFW_E_BUFFER_NOTSET";
            case 0x12:
              return "VFW_E_BUFFER_OVERFLOW";
            case 0x13:
              return "VFW_E_BADALIGN";
            case 0x14:
              return "VFW_E_ALREADY_COMMITTED";
            case 0x15:
              return "VFW_E_BUFFERS_OUTSTANDING";
            case 0x16:
              return "VFW_E_NOT_COMMITTED";
            case 0x17:
              return "VFW_E_SIZENOTSET";
            case 0x18:
              return "VFW_E_NO_CLOCK";
            case 0x19:
              return "VFW_E_NO_SINK";
            case 0x1a:
              return "VFW_E_NO_INTERFACE";
            case 0x1b:
              return "VFW_E_NOT_FOUND";
            case 0x1c:
              return "VFW_E_CANNOT_CONNECT";
            case 0x1d:
              return "VFW_E_CANNOT_RENDER";
            case 0x1e:
              return "VFW_E_CHANGING_FORMAT";
            case 0x1f:
              return "VFW_E_NO_COLOR_KEY_SET";
            case 0x20:
              return "VFW_E_NOT_OVERLAY_CONNECTION";
            case 0x21:
              return "VFW_E_NOT_SAMPLE_CONNECTION";
            case 0x22:
              return "VFW_E_PALETTE_SET";
            case 0x23:
              return "VFW_E_COLOR_KEY_SET";
            case 0x24:
              return "VFW_E_NO_COLOR_KEY_FOUND";
            case 0x25:
              return "VFW_E_NO_PALETTE_AVAILABLE";
            case 0x26:
              return "VFW_E_NO_DISPLAY_PALETTE";
            case 0x27:
              return "VFW_E_TOO_MANY_COLORS";
            case 0x28:
              return "VFW_E_STATE_CHANGED";
            case 0x29:
              return "VFW_E_NOT_STOPPED";
            case 0x2a:
              return "VFW_E_NOT_PAUSED";
            case 0x2b:
              return "VFW_E_NOT_RUNNING";
            case 0x2c:
              return "VFW_E_WRONG_STATE";
            case 0x2d:
              return "VFW_E_START_TIME_AFTER_END";
            case 0x2e:
              return "VFW_E_INVALID_RECT";
            case 0x2f:
              return "VFW_E_TYPE_NOT_ACCEPTED";
            case 0x30:
              return "VFW_E_SAMPLE_REJECTED";
            case 0x31:
              return "VFW_E_SAMPLE_REJECTED_EOS";
            case 0x32:
              return "VFW_E_DUPLICATE_NAME";
            case 0x33:
              return "VFW_E_TIMEOUT";
            case 0x34:
              return "VFW_E_INVALID_FILE_FORMAT";
            case 0x35:
              return "VFW_E_ENUM_OUT_OF_RANGE";
            case 0x36:
              return "VFW_E_CIRCULAR_GRAPH";
            case 0x37:
              return "VFW_E_NOT_ALLOWED_TO_SAVE";
            case 0x38:
              return "VFW_E_TIME_ALREADY_PASSED";
            case 0x39:
              return "VFW_E_ALREADY_CANCELLED";
            case 0x3a:
              return "VFW_E_CORRUPT_GRAPH_FILE";
            case 0x3b:
              return "VFW_E_ADVISE_ALREADY_SET";
            case 0x3c:
              return "VFW_E_NO_MODEX_AVAILABLE";
            case 0x3d:
              return "VFW_E_NO_ADVISE_SET";
            case 0x3e:
              return "VFW_E_NO_FULLSCREEN";
            case 0x3f:
              return "VFW_E_IN_FULLSCREEN_MODE";
            case 0x40:
              return "VFW_E_UNKNOWN_FILE_TYPE";
            case 0x41:
              return "VFW_E_CANNOT_LOAD_SOURCE_FILTER";
            case 0x42:
              return "VFW_E_FILE_TOO_SHORT";
            case 0x43:
              return "VFW_E_INVALID_FILE_VERSION";
            case 0x44:
              return "VFW_E_INVALID_CLSID";
            case 0x45:
              return "VFW_E_INVALID_MEDIA_TYPE";
            case 0x46:
              return "VFW_E_SAMPLE_TIME_NOT_SET";
            case 0x47:
              return "VFW_E_MEDIA_TIME_NOT_SET";
            case 0x48:
              return "VFW_E_NO_TIME_FORMAT_SET";
            case 0x49:
              return "VFW_E_MONO_AUDIO_HW";
            case 0x4a:
              return "VFW_E_NO_DECOMPRESSOR";
            case 0x4b:
              return "VFW_E_NO_AUDIO_HARDWARE";
            case 0x4c:
              return "VFW_E_RPZA";
            case 0x4d:
              return "VFW_E_PROCESSOR_NOT_SUITABLE";
            case 0x4e:
              return "VFW_E_UNSUPPORTED_AUDIO";
            case 0x4f:
              return "VFW_E_UNSUPPORTED_VIDEO";
            case 0x50:
              return "VFW_E_MPEG_NOT_CONSTRAINED";
            case 0x51:
              return "VFW_E_NOT_IN_GRAPH";
            case 0x52:
              return "VFW_E_NO_TIME_FORMAT";
            case 0x53:
              return "VFW_E_READ_ONLY";
            case 0x54:
              return "VFW_E_BUFFER_UNDERFLOW";
            case 0x55:
              return "VFW_E_UNSUPPORTED_STREAM";
            case 0x56:
              return "VFW_E_NO_TRANSPORT";
            case 0x57:
              return "VFW_E_BAD_VIDEOCD";
            case 0x58:
              return "VFW_E_OUT_OF_VIDEO_MEMORY";
            case 0x59:
              return "VFW_E_VP_NEGOTIATION_FAILED";
            case 0x5a:
              return "VFW_E_DDRAW_CAPS_NOT_SUITABLE";
            case 0x5b:
              return "VFW_E_NO_VP_HARDWARE";
            case 0x5c:
              return "VFW_E_NO_CAPTURE_HARDWARE";
            case 0x5d:
              return "VFW_E_DVD_OPERATION_INHIBITED";
            case 0x5e:
              return "VFW_E_DVD_INVALIDDOMAIN";
            case 0x5f:
              return "VFW_E_DVD_NO_BUTTON";
            case 0x60:
              return "VFW_E_DVD_GRAPHNOTREADY";
            case 0x61:
              return "VFW_E_DVD_RENDERFAIL";
            case 0x62:
              return "VFW_E_DVD_DECNOTENOUGH";
            case 99:
              return "VFW_E_DDRAW_VERSION_NOT_SUITABLE";
            case 100:
              return "VFW_E_COPYPROT_FAILED";
            case 0x65:
              return "VFW_E_TIME_EXPIRED";
            case 0x66:
              return "VFW_E_DVD_WRONG_SPEED";
            case 0x67:
              return "VFW_E_DVD_MENU_DOES_NOT_EXIST";
            case 0x68:
              return "VFW_E_DVD_CMD_CANCELLED";
            case 0x69:
              return "VFW_E_DVD_STATE_WRONG_VERSION";
            case 0x6a:
              return "VFW_E_DVD_STATE_CORRUPT";
            case 0x6b:
              return "VFW_E_DVD_STATE_WRONG_DISC";
            case 0x6c:
              return "VFW_E_DVD_INCOMPATIBLE_REGION";
            case 0x6d:
              return "VFW_E_DVD_NO_ATTRIBUTES";
            case 0x6e:
              return "VFW_E_DVD_NO_GOUP_PGC";
            case 0x6f:
              return "VFW_E_DVD_LOW_PARENTAL_LEVEL";
            case 0x70:
              return "VFW_E_DVD_NOT_IN_KARAOKE_MODE";
            case 0x71:
              return "VFW_E_FRAME_STEP_UNSUPPORTED";
            case 0x72:
              return "VFW_E_DVD_STREAM_DISABLED";
            case 0x73:
              return "VFW_E_DVD_TITLE_UNKNOWN";
            case 0x74:
              return "VFW_E_DVD_INVALID_DISC";
            case 0x75:
              return "VFW_E_DVD_NO_RESUME_INFORMATION";
            case 0x76:
              return "VFW_E_PIN_ALREADY_BLOCKED_ON_THIS_THREAD";
            case 0x77:
              return "VFW_E_PIN_ALREADY_BLOCKED";
            case 0x78:
              return "VFW_E_CERTIFICATION_FAILURE";
            case 0x79:
              return "DIERR_DRIVERFIRST";
            case 0x7a:
              return "DIERR_DRIVERFIRST+1";
            case 0x7b:
              return "DIERR_DRIVERFIRST+2";
            case 0x7c:
              return "DIERR_DRIVERFIRST+3";
            case 0x7d:
              return "DIERR_DRIVERFIRST+4";
            case 0x7e:
              return "DIERR_DRIVERFIRST+5";
            }
          }
        }
        else if (param_1 < -0x7ffbeffe) {
          if (param_1 == -0x7ffbefff) {
            return "WBEM_E_FAILED";
          }
          switch(param_1) {
          case -0x7ffbfc01:
            return "DIERR_DRIVERLAST";
          case -0x7ffbfc00:
            return "DIERR_INVALIDCLASSINSTALLER";
          case -0x7ffbfbff:
            return "DIERR_CANCELLED & MS_E_SAMPLEALLOC";
          case -0x7ffbfbfe:
            return "DIERR_BADINF & MS_E_PURPOSEID";
          case -0x7ffbfbfd:
            return "MS_E_NOSTREAM";
          case -0x7ffbfbfc:
            return "MS_E_NOSEEKING";
          case -0x7ffbfbfb:
            return "MS_E_INCOMPATIBLE";
          case -0x7ffbfbfa:
            return "MS_E_BUSY";
          case -0x7ffbfbf9:
            return "MS_E_NOTINIT";
          case -0x7ffbfbf8:
            return "MS_E_SOURCEALREADYDEFINED";
          case -0x7ffbfbf7:
            return "MS_E_INVALIDSTREAMTYPE";
          case -0x7ffbfbf6:
            return "MS_E_NOTRUNNING";
          }
        }
        else if (param_1 < -0x7ffbecf6) {
          if (param_1 == -0x7ffbecf7) {
            return "SCHED_E_TRIGGER_NOT_FOUND";
          }
          switch(param_1) {
          case -0x7ffbeffe:
            return "WBEM_E_NOT_FOUND";
          case -0x7ffbeffd:
            return "WBEM_E_ACCESS_DENIED";
          case -0x7ffbeffc:
            return "WBEM_E_PROVIDER_FAILURE";
          case -0x7ffbeffb:
            return "WBEM_E_TYPE_MISMATCH";
          case -0x7ffbeffa:
            return "WBEM_E_OUT_OF_MEMORY";
          case -0x7ffbeff9:
            return "WBEM_E_INVALID_CONTEXT";
          case -0x7ffbeff8:
            return "WBEM_E_INVALID_PARAMETER";
          case -0x7ffbeff7:
            return "WBEM_E_NOT_AVAILABLE";
          case -0x7ffbeff6:
            return "WBEM_E_CRITICAL_ERROR";
          case -0x7ffbeff5:
            return "WBEM_E_INVALID_STREAM";
          case -0x7ffbeff4:
            return "WBEM_E_NOT_SUPPORTED";
          case -0x7ffbeff3:
            return "WBEM_E_INVALID_SUPERCLASS";
          case -0x7ffbeff2:
            return "WBEM_E_INVALID_NAMESPACE";
          case -0x7ffbeff1:
            return "WBEM_E_INVALID_OBJECT";
          case -0x7ffbeff0:
            return "WBEM_E_INVALID_CLASS";
          case -0x7ffbefef:
            return "WBEM_E_PROVIDER_NOT_FOUND";
          case -0x7ffbefee:
            return "WBEM_E_INVALID_PROVIDER_REGISTRATION";
          case -0x7ffbefed:
            return "WBEM_E_PROVIDER_LOAD_FAILURE";
          case -0x7ffbefec:
            return "WBEM_E_INITIALIZATION_FAILURE";
          case -0x7ffbefeb:
            return "WBEM_E_TRANSPORT_FAILURE";
          case -0x7ffbefea:
            return "WBEM_E_INVALID_OPERATION";
          case -0x7ffbefe9:
            return "WBEM_E_INVALID_QUERY";
          case -0x7ffbefe8:
            return "WBEM_E_INVALID_QUERY_TYPE";
          case -0x7ffbefe7:
            return "WBEM_E_ALREADY_EXISTS";
          case -0x7ffbefe6:
            return "WBEM_E_OVERRIDE_NOT_ALLOWED";
          case -0x7ffbefe5:
            return "WBEM_E_PROPAGATED_QUALIFIER";
          case -0x7ffbefe4:
            return "WBEM_E_PROPAGATED_PROPERTY";
          case -0x7ffbefe3:
            return "WBEM_E_UNEXPECTED";
          case -0x7ffbefe2:
            return "WBEM_E_ILLEGAL_OPERATION";
          case -0x7ffbefe1:
            return "WBEM_E_CANNOT_BE_KEY";
          case -0x7ffbefe0:
            return "WBEM_E_INCOMPLETE_CLASS";
          case -0x7ffbefdf:
            return "WBEM_E_INVALID_SYNTAX";
          case -0x7ffbefde:
            return "WBEM_E_NONDECORATED_OBJECT";
          case -0x7ffbefdd:
            return "WBEM_E_READ_ONLY";
          case -0x7ffbefdc:
            return "WBEM_E_PROVIDER_NOT_CAPABLE";
          case -0x7ffbefdb:
            return "WBEM_E_CLASS_HAS_CHILDREN";
          case -0x7ffbefda:
            return "WBEM_E_CLASS_HAS_INSTANCES";
          case -0x7ffbefd9:
            return "WBEM_E_QUERY_NOT_IMPLEMENTED";
          case -0x7ffbefd8:
            return "WBEM_E_ILLEGAL_NULL";
          case -0x7ffbefd7:
            return "WBEM_E_INVALID_QUALIFIER_TYPE";
          case -0x7ffbefd6:
            return "WBEM_E_INVALID_PROPERTY_TYPE";
          case -0x7ffbefd5:
            return "WBEM_E_VALUE_OUT_OF_RANGE";
          case -0x7ffbefd4:
            return "WBEM_E_CANNOT_BE_SINGLETON";
          case -0x7ffbefd3:
            return "WBEM_E_INVALID_CIM_TYPE";
          case -0x7ffbefd2:
            return "WBEM_E_INVALID_METHOD";
          case -0x7ffbefd1:
            return "WBEM_E_INVALID_METHOD_PARAMETERS";
          case -0x7ffbefd0:
            return "WBEM_E_SYSTEM_PROPERTY";
          case -0x7ffbefcf:
            return "WBEM_E_INVALID_PROPERTY";
          case -0x7ffbefce:
            return "WBEM_E_CALL_CANCELLED";
          case -0x7ffbefcd:
            return "WBEM_E_SHUTTING_DOWN";
          case -0x7ffbefcc:
            return "WBEM_E_PROPAGATED_METHOD";
          case -0x7ffbefcb:
            return "WBEM_E_UNSUPPORTED_PARAMETER";
          case -0x7ffbefca:
            return "WBEM_E_MISSING_PARAMETER_ID";
          case -0x7ffbefc9:
            return "WBEM_E_INVALID_PARAMETER_ID";
          case -0x7ffbefc8:
            return "WBEM_E_NONCONSECUTIVE_PARAMETER_IDS";
          case -0x7ffbefc7:
            return "WBEM_E_PARAMETER_ID_ON_RETVAL";
          case -0x7ffbefc6:
            return "WBEM_E_INVALID_OBJECT_PATH";
          case -0x7ffbefc5:
            return "WBEM_E_OUT_OF_DISK_SPACE";
          case -0x7ffbefc4:
            return "WBEM_E_BUFFER_TOO_SMALL";
          case -0x7ffbefc3:
            return "WBEM_E_UNSUPPORTED_PUT_EXTENSION";
          case -0x7ffbefc2:
            return "WBEM_E_UNKNOWN_OBJECT_TYPE";
          case -0x7ffbefc1:
            return "WBEM_E_UNKNOWN_PACKET_TYPE";
          case -0x7ffbefc0:
            return "WBEM_E_MARSHAL_VERSION_MISMATCH";
          case -0x7ffbefbf:
            return "WBEM_E_MARSHAL_INVALID_SIGNATURE";
          case -0x7ffbefbe:
            return "WBEM_E_INVALID_QUALIFIER";
          case -0x7ffbefbd:
            return "WBEM_E_INVALID_DUPLICATE_PARAMETER";
          case -0x7ffbefbc:
            return "WBEM_E_TOO_MUCH_DATA";
          case -0x7ffbefbb:
            return "WBEM_E_SERVER_TOO_BUSY";
          case -0x7ffbefba:
            return "WBEM_E_INVALID_FLAVOR";
          case -0x7ffbefb9:
            return "WBEM_E_CIRCULAR_REFERENCE";
          case -0x7ffbefb8:
            return "WBEM_E_UNSUPPORTED_CLASS_UPDATE";
          case -0x7ffbefb7:
            return "WBEM_E_CANNOT_CHANGE_KEY_INHERITANCE";
          case -0x7ffbefb0:
            return "WBEM_E_CANNOT_CHANGE_INDEX_INHERITANCE";
          case -0x7ffbefaf:
            return "WBEM_E_TOO_MANY_PROPERTIES";
          case -0x7ffbefae:
            return "WBEM_E_UPDATE_TYPE_MISMATCH";
          case -0x7ffbefad:
            return "WBEM_E_UPDATE_OVERRIDE_NOT_ALLOWED";
          case -0x7ffbefac:
            return "WBEM_E_UPDATE_PROPAGATED_METHOD";
          case -0x7ffbefab:
            return "WBEM_E_METHOD_NOT_IMPLEMENTED";
          case -0x7ffbefaa:
            return "WBEM_E_METHOD_DISABLED";
          case -0x7ffbefa9:
            return "WBEM_E_REFRESHER_BUSY";
          case -0x7ffbefa8:
            return "WBEM_E_UNPARSABLE_QUERY";
          case -0x7ffbefa7:
            return "WBEM_E_NOT_EVENT_CLASS";
          case -0x7ffbefa6:
            return "WBEM_E_MISSING_GROUP_WITHIN";
          case -0x7ffbefa5:
            return "WBEM_E_MISSING_AGGREGATION_LIST";
          case -0x7ffbefa4:
            return "WBEM_E_PROPERTY_NOT_AN_OBJECT";
          case -0x7ffbefa3:
            return "WBEM_E_AGGREGATING_BY_OBJECT";
          case -0x7ffbefa1:
            return "WBEM_E_UNINTERPRETABLE_PROVIDER_QUERY";
          case -0x7ffbefa0:
            return "WBEM_E_BACKUP_RESTORE_WINMGMT_RUNNING";
          case -0x7ffbef9f:
            return "WBEM_E_QUEUE_OVERFLOW";
          case -0x7ffbef9e:
            return "WBEM_E_PRIVILEGE_NOT_HELD";
          case -0x7ffbef9d:
            return "WBEM_E_INVALID_OPERATOR";
          case -0x7ffbef9c:
            return "WBEM_E_LOCAL_CREDENTIALS";
          case -0x7ffbef9b:
            return "WBEM_E_CANNOT_BE_ABSTRACT";
          case -0x7ffbef9a:
            return "WBEM_E_AMENDED_OBJECT";
          case -0x7ffbef99:
            return "WBEM_E_CLIENT_TOO_SLOW";
          case -0x7ffbef98:
            return "WBEM_E_NULL_SECURITY_DESCRIPTOR";
          case -0x7ffbef97:
            return "WBEM_E_TIMED_OUT";
          case -0x7ffbef96:
            return "WBEM_E_INVALID_ASSOCIATION";
          case -0x7ffbef95:
            return "WBEM_E_AMBIGUOUS_OPERATION";
          case -0x7ffbef94:
            return "WBEM_E_QUOTA_VIOLATION";
          case -0x7ffbef93:
            return "WBEM_E_RESERVED_001";
          case -0x7ffbef92:
            return "WBEM_E_RESERVED_002";
          case -0x7ffbef91:
            return "WBEM_E_UNSUPPORTED_LOCALE";
          case -0x7ffbef90:
            return "WBEM_E_HANDLE_OUT_OF_DATE";
          case -0x7ffbef8f:
            return "WBEM_E_CONNECTION_FAILED";
          case -0x7ffbef8e:
            return "WBEM_E_INVALID_HANDLE_REQUEST";
          case -0x7ffbef8d:
            return "WBEM_E_PROPERTY_NAME_TOO_WIDE";
          case -0x7ffbef8c:
            return "WBEM_E_CLASS_NAME_TOO_WIDE";
          case -0x7ffbef8b:
            return "WBEM_E_METHOD_NAME_TOO_WIDE";
          case -0x7ffbef8a:
            return "WBEM_E_QUALIFIER_NAME_TOO_WIDE";
          case -0x7ffbef89:
            return "WBEM_E_RERUN_COMMAND";
          case -0x7ffbef88:
            return "WBEM_E_DATABASE_VER_MISMATCH";
          case -0x7ffbef87:
            return "WBEM_E_VETO_DELETE";
          case -0x7ffbef86:
            return "WBEM_E_VETO_PUT";
          case -0x7ffbef80:
            return "WBEM_E_INVALID_LOCALE";
          case -0x7ffbef7f:
            return "WBEM_E_PROVIDER_SUSPENDED";
          case -0x7ffbef7e:
            return "WBEM_E_SYNCHRONIZATION_REQUIRED";
          case -0x7ffbef7d:
            return "WBEM_E_NO_SCHEMA";
          case -0x7ffbef7c:
            return "WBEM_E_PROVIDER_ALREADY_REGISTERED";
          case -0x7ffbef7b:
            return "WBEM_E_PROVIDER_NOT_REGISTERED";
          case -0x7ffbef7a:
            return "WBEM_E_FATAL_TRANSPORT_ERROR";
          case -0x7ffbef79:
            return "WBEM_E_ENCRYPTED_CONNECTION_REQUIRED";
          case -0x7ffbef78:
            return "WBEM_E_PROVIDER_TIMED_OUT";
          case -0x7ffbef77:
            return "WBEM_E_NO_KEY";
          case -0x7ffbef76:
            return "WBEM_E_PROVIDER_DISABLED";
          }
        }
        else if (param_1 < -0x7ffbdffe) {
          if (param_1 == -0x7ffbdfff) {
            return "WBEMESS_E_REGISTRATION_TOO_BROAD";
          }
          switch(param_1) {
          case -0x7ffbecf6:
            return "SCHED_E_TASK_NOT_READY";
          case -0x7ffbecf5:
            return "SCHED_E_TASK_NOT_RUNNING";
          case -0x7ffbecf4:
            return "SCHED_E_SERVICE_NOT_INSTALLED";
          case -0x7ffbecf3:
            return "SCHED_E_CANNOT_OPEN_TASK";
          case -0x7ffbecf2:
            return "SCHED_E_INVALID_TASK";
          case -0x7ffbecf1:
            return "SCHED_E_ACCOUNT_INFORMATION_NOT_SET";
          case -0x7ffbecf0:
            return "SCHED_E_ACCOUNT_NAME_NOT_FOUND";
          case -0x7ffbecef:
            return "SCHED_E_ACCOUNT_DBASE_CORRUPT";
          case -0x7ffbecee:
            return "SCHED_E_NO_SECURITY_SERVICES";
          case -0x7ffbeced:
            return "SCHED_E_UNKNOWN_OBJECT_VERSION";
          case -0x7ffbecec:
            return "SCHED_E_UNSUPPORTED_ACCOUNT_OPTION";
          case -0x7ffbeceb:
            return "SCHED_E_SERVICE_NOT_RUNNING";
          }
        }
        else if (param_1 < -0x7ffbbfe1) {
          if (param_1 == -0x7ffbbfe2) {
            return "WBEMMOF_E_INVALID_FILE";
          }
          if (param_1 < -0x7ffbbff0) {
            if (param_1 == -0x7ffbbff1) {
              return "WBEMMOF_E_UNEXPECTED_ARRAY_INIT";
            }
            if (param_1 < -0x7ffbbff8) {
              if (param_1 == -0x7ffbbff9) {
                return "WBEMMOF_E_ILLEGAL_CONSTANT_VALUE";
              }
              if (param_1 == -0x7ffbdffe) {
                return "WBEMESS_E_REGISTRATION_TOO_PRECISE";
              }
              if (param_1 == -0x7ffbbfff) {
                return "WBEMMOF_E_EXPECTED_QUALIFIER_NAME";
              }
              if (param_1 == -0x7ffbbffe) {
                return "WBEMMOF_E_EXPECTED_SEMI";
              }
              if (param_1 == -0x7ffbbffd) {
                return "WBEMMOF_E_EXPECTED_OPEN_BRACE";
              }
              if (param_1 == -0x7ffbbffc) {
                return "WBEMMOF_E_EXPECTED_CLOSE_BRACE";
              }
              if (param_1 == -0x7ffbbffb) {
                return "WBEMMOF_E_EXPECTED_CLOSE_BRACKET";
              }
              if (param_1 == -0x7ffbbffa) {
                return "WBEMMOF_E_EXPECTED_CLOSE_PAREN";
              }
            }
            else {
              if (param_1 == -0x7ffbbff8) {
                return "WBEMMOF_E_EXPECTED_TYPE_IDENTIFIER";
              }
              if (param_1 == -0x7ffbbff7) {
                return "WBEMMOF_E_EXPECTED_OPEN_PAREN";
              }
              if (param_1 == -0x7ffbbff6) {
                return "WBEMMOF_E_UNRECOGNIZED_TOKEN";
              }
              if (param_1 == -0x7ffbbff5) {
                return "WBEMMOF_E_UNRECOGNIZED_TYPE";
              }
              if (param_1 == -0x7ffbbff4) {
                return "WBEMMOF_E_EXPECTED_PROPERTY_NAME";
              }
              if (param_1 == -0x7ffbbff3) {
                return "WBEMMOF_E_TYPEDEF_NOT_SUPPORTED";
              }
              if (param_1 == -0x7ffbbff2) {
                return "WBEMMOF_E_UNEXPECTED_ALIAS";
              }
            }
          }
          else {
            switch(param_1) {
            case -0x7ffbbff0:
              return "WBEMMOF_E_INVALID_AMENDMENT_SYNTAX";
            case -0x7ffbbfef:
              return "WBEMMOF_E_INVALID_DUPLICATE_AMENDMENT";
            case -0x7ffbbfee:
              return "WBEMMOF_E_INVALID_PRAGMA";
            case -0x7ffbbfed:
              return "WBEMMOF_E_INVALID_NAMESPACE_SYNTAX";
            case -0x7ffbbfec:
              return "WBEMMOF_E_EXPECTED_CLASS_NAME";
            case -0x7ffbbfeb:
              return "WBEMMOF_E_TYPE_MISMATCH";
            case -0x7ffbbfea:
              return "WBEMMOF_E_EXPECTED_ALIAS_NAME";
            case -0x7ffbbfe9:
              return "WBEMMOF_E_INVALID_CLASS_DECLARATION";
            case -0x7ffbbfe8:
              return "WBEMMOF_E_INVALID_INSTANCE_DECLARATION";
            case -0x7ffbbfe7:
              return "WBEMMOF_E_EXPECTED_DOLLAR";
            case -0x7ffbbfe6:
              return "WBEMMOF_E_CIMTYPE_QUALIFIER";
            case -0x7ffbbfe5:
              return "WBEMMOF_E_DUPLICATE_PROPERTY";
            case -0x7ffbbfe4:
              return "WBEMMOF_E_INVALID_NAMESPACE_SPECIFICATION";
            case -0x7ffbbfe3:
              return "WBEMMOF_E_OUT_OF_RANGE";
            }
          }
        }
        else if (param_1 < -0x7ffb2fff) {
          if (param_1 == -0x7ffb3000) {
            return "XACT_E_FIRST";
          }
          switch(param_1) {
          case -0x7ffbbfe1:
            return "WBEMMOF_E_ALIASES_IN_EMBEDDED";
          case -0x7ffbbfe0:
            return "WBEMMOF_E_NULL_ARRAY_ELEM";
          case -0x7ffbbfdf:
            return "WBEMMOF_E_DUPLICATE_QUALIFIER";
          case -0x7ffbbfde:
            return "WBEMMOF_E_EXPECTED_FLAVOR_TYPE";
          case -0x7ffbbfdd:
            return "WBEMMOF_E_INCOMPATIBLE_FLAVOR_TYPES";
          case -0x7ffbbfdc:
            return "WBEMMOF_E_MULTIPLE_ALIASES";
          case -0x7ffbbfdb:
            return "WBEMMOF_E_INCOMPATIBLE_FLAVOR_TYPES2";
          case -0x7ffbbfda:
            return "WBEMMOF_E_NO_ARRAYS_RETURNED";
          case -0x7ffbbfd9:
            return "WBEMMOF_E_MUST_BE_IN_OR_OUT";
          case -0x7ffbbfd8:
            return "WBEMMOF_E_INVALID_FLAGS_SYNTAX";
          case -0x7ffbbfd7:
            return "WBEMMOF_E_EXPECTED_BRACE_OR_BAD_TYPE";
          case -0x7ffbbfd6:
            return "WBEMMOF_E_UNSUPPORTED_CIMV22_QUAL_VALUE";
          case -0x7ffbbfd5:
            return "WBEMMOF_E_UNSUPPORTED_CIMV22_DATA_TYPE";
          case -0x7ffbbfd4:
            return "WBEMMOF_E_INVALID_DELETEINSTANCE_SYNTAX";
          case -0x7ffbbfd3:
            return "WBEMMOF_E_INVALID_QUALIFIER_SYNTAX";
          case -0x7ffbbfd2:
            return "WBEMMOF_E_QUALIFIER_USED_OUTSIDE_SCOPE";
          case -0x7ffbbfd1:
            return "WBEMMOF_E_ERROR_CREATING_TEMP_FILE";
          case -0x7ffbbfd0:
            return "WBEMMOF_E_ERROR_INVALID_INCLUDE_FILE";
          case -0x7ffbbfcf:
            return "WBEMMOF_E_INVALID_DELETECLASS_SYNTAX";
          }
        }
        else {
          switch(param_1) {
          case -0x7ffb2fff:
            return "XACT_E_CANTRETAIN";
          case -0x7ffb2ffe:
            return "XACT_E_COMMITFAILED";
          case -0x7ffb2ffd:
            return "XACT_E_COMMITPREVENTED";
          case -0x7ffb2ffc:
            return "XACT_E_HEURISTICABORT";
          case -0x7ffb2ffb:
            return "XACT_E_HEURISTICCOMMIT";
          case -0x7ffb2ffa:
            return "XACT_E_HEURISTICDAMAGE";
          case -0x7ffb2ff9:
            return "XACT_E_HEURISTICDANGER";
          case -0x7ffb2ff8:
            return "XACT_E_ISOLATIONLEVEL";
          case -0x7ffb2ff7:
            return "XACT_E_NOASYNC";
          case -0x7ffb2ff6:
            return "XACT_E_NOENLIST";
          }
        }
      }
      else if (param_1 < -0x7ffb2f7f) {
        if (param_1 == -0x7ffb2f80) {
          return "XACT_E_CLERKNOTFOUND";
        }
        switch(param_1) {
        case -0x7ffb2ff4:
          return "XACT_E_NORESOURCE";
        case -0x7ffb2ff3:
          return "XACT_E_NOTCURRENT";
        case -0x7ffb2ff2:
          return "XACT_E_NOTRANSACTION";
        case -0x7ffb2ff1:
          return "XACT_E_NOTSUPPORTED";
        case -0x7ffb2ff0:
          return "XACT_E_UNKNOWNRMGRID";
        case -0x7ffb2fef:
          return "XACT_E_WRONGSTATE";
        case -0x7ffb2fee:
          return "XACT_E_WRONGUOW";
        case -0x7ffb2fed:
          return "XACT_E_XTIONEXISTS";
        case -0x7ffb2fec:
          return "XACT_E_NOIMPORTOBJECT";
        case -0x7ffb2feb:
          return "XACT_E_INVALIDCOOKIE";
        case -0x7ffb2fea:
          return "XACT_E_INDOUBT";
        case -0x7ffb2fe9:
          return "XACT_E_NOTIMEOUT";
        case -0x7ffb2fe8:
          return "XACT_E_ALREADYINPROGRESS";
        case -0x7ffb2fe7:
          return "XACT_E_ABORTED";
        case -0x7ffb2fe6:
          return "XACT_E_LOGFULL";
        case -0x7ffb2fe5:
          return "XACT_E_TMNOTAVAILABLE";
        case -0x7ffb2fe4:
          return "XACT_E_CONNECTION_DOWN";
        case -0x7ffb2fe3:
          return "XACT_E_CONNECTION_DENIED";
        case -0x7ffb2fe2:
          return "XACT_E_REENLISTTIMEOUT";
        case -0x7ffb2fe1:
          return "XACT_E_TIP_CONNECT_FAILED";
        case -0x7ffb2fe0:
          return "XACT_E_TIP_PROTOCOL_ERROR";
        case -0x7ffb2fdf:
          return "XACT_E_TIP_PULL_FAILED";
        case -0x7ffb2fde:
          return "XACT_E_DEST_TMNOTAVAILABLE";
        case -0x7ffb2fdd:
          return "XACT_E_TIP_DISABLED";
        case -0x7ffb2fdc:
          return "XACT_E_NETWORK_TX_DISABLED";
        case -0x7ffb2fdb:
          return "XACT_E_PARTNER_NETWORK_TX_DISABLED";
        case -0x7ffb2fda:
          return "XACT_E_XA_TX_DISABLED";
        case -0x7ffb2fd9:
          return "XACT_E_UNABLE_TO_READ_DTC_CONFIG";
        case -0x7ffb2fd8:
          return "XACT_E_UNABLE_TO_LOAD_DTC_PROXY";
        case -0x7ffb2fd7:
          return "XACT_E_LAST";
        }
      }
      else if (param_1 < -0x7ff8fb7b) {
        if (param_1 == -0x7ff8fb7c) {
LAB_0071ce85:
          return "ERROR_DDE_FAIL";
        }
        if (param_1 < -0x7ff8ff51) {
          if (param_1 == -0x7ff8ff52) {
LAB_0071c762:
            return "ERROR_ATOMIC_LOCKS_NOT_SUPPORTED";
          }
          if (param_1 < -0x7ff8ffbd) {
            if (param_1 == -0x7ff8ffbe) {
LAB_0071c3a9:
              return "ERROR_BAD_DEV_TYPE";
            }
            if (param_1 < -0x7ff8fff2) {
              if (param_1 == -0x7ff8fff3) {
LAB_0071c1da:
                return "ERROR_INVALID_DATA";
              }
              if (param_1 < -0x7ffb1fd7) {
                if (param_1 == -0x7ffb1fd8) {
                  return "CO_E_THREADINGMODEL_CHANGED";
                }
                if (param_1 < -0x7ffb1ff8) {
                  if (param_1 == -0x7ffb1ff9) {
                    return "CONTEXT_E_OLDREF";
                  }
                  if (param_1 < -0x7ffb1fff) {
                    if (param_1 == -0x7ffb2000) {
                      return "CONTEXT_E_FIRST";
                    }
                    if (param_1 == -0x7ffb2f7f) {
                      return "XACT_E_CLERKEXISTS";
                    }
                    if (param_1 == -0x7ffb2f7e) {
                      return "XACT_E_RECOVERYINPROGRESS";
                    }
                    if (param_1 == -0x7ffb2f7d) {
                      return "XACT_E_TRANSACTIONCLOSED";
                    }
                    if (param_1 == -0x7ffb2f7c) {
                      return "XACT_E_INVALIDLSN";
                    }
                    if (param_1 == -0x7ffb2f7b) {
                      return "XACT_E_REPLAYREQUEST";
                    }
                  }
                  else {
                    if (param_1 == -0x7ffb1ffe) {
                      return "CONTEXT_E_ABORTED";
                    }
                    if (param_1 == -0x7ffb1ffd) {
                      return "CONTEXT_E_ABORTING";
                    }
                    if (param_1 == -0x7ffb1ffc) {
                      return "CONTEXT_E_NOCONTEXT";
                    }
                    if (param_1 == -0x7ffb1ffa) {
                      return "CONTEXT_E_SYNCH_TIMEOUT";
                    }
                  }
                }
                else if (param_1 < -0x7ffb1fdc) {
                  if (param_1 == -0x7ffb1fdd) {
                    return "CO_E_ACTIVATIONFAILED_CATALOGERROR";
                  }
                  if (param_1 == -0x7ffb1ff4) {
                    return "CONTEXT_E_ROLENOTFOUND";
                  }
                  if (param_1 == -0x7ffb1ff1) {
                    return "CONTEXT_E_TMNOTAVAILABLE";
                  }
                  if (param_1 == -0x7ffb1fdf) {
                    return "CO_E_ACTIVATIONFAILED";
                  }
                  if (param_1 == -0x7ffb1fde) {
                    return "CO_E_ACTIVATIONFAILED_EVENTLOGGED";
                  }
                }
                else {
                  if (param_1 == -0x7ffb1fdc) {
                    return "CO_E_ACTIVATIONFAILED_TIMEOUT";
                  }
                  if (param_1 == -0x7ffb1fdb) {
                    return "CO_E_INITIALIZATIONFAILED";
                  }
                  if (param_1 == -0x7ffb1fda) {
                    return "CONTEXT_E_NOJIT";
                  }
                  if (param_1 == -0x7ffb1fd9) {
                    return "CONTEXT_E_NOTRANSACTION";
                  }
                }
              }
              else if (param_1 < -0x7ff8fffc) {
                if (param_1 == -0x7ff8fffd) {
LAB_0071c181:
                  return "ERROR_PATH_NOT_FOUND";
                }
                if (param_1 < -0x7ffb1fd2) {
                  if (param_1 == -0x7ffb1fd3) {
                    return "CO_E_NOTCONSTRUCTED";
                  }
                  if (param_1 == -0x7ffb1fd7) {
                    return "CO_E_NOIISINTRINSICS";
                  }
                  if (param_1 == -0x7ffb1fd6) {
                    return "CO_E_NOCOOKIES";
                  }
                  if (param_1 == -0x7ffb1fd5) {
                    return "CO_E_DBERROR";
                  }
                  if (param_1 == -0x7ffb1fd4) {
                    return "CO_E_NOTPOOLED";
                  }
                }
                else {
                  if (param_1 == -0x7ffb1fd2) {
                    return "CO_E_NOSYNCHRONIZATION";
                  }
                  if (param_1 == -0x7ffb1fd1) {
                    return "CONTEXT_E_LAST";
                  }
                  if (param_1 == -0x7ff8ffff) {
                    return "ERROR_INVALID_FUNCTION";
                  }
                  if (param_1 == -0x7ff8fffe) {
LAB_00717ec4:
                    return "ERROR_FILE_NOT_FOUND";
                  }
                }
              }
              else {
                switch(param_1) {
                case -0x7ff8fffc:
LAB_0071c177:
                  return "ERROR_TOO_MANY_OPEN_FILES";
                case -0x7ff8fffb:
                  return "E_ACCESSDENIED";
                case -0x7ff8fffa:
                  return "E_HANDLE";
                case -0x7ff8fff9:
LAB_0071c18b:
                  return "ERROR_ARENA_TRASHED";
                case -0x7ff8fff8:
LAB_0071c1a8:
                  return "ERROR_NOT_ENOUGH_MEMORY";
                case -0x7ff8fff7:
LAB_0071c1b2:
                  return "ERROR_INVALID_BLOCK";
                case -0x7ff8fff6:
LAB_0071c1bc:
                  return "ERROR_BAD_ENVIRONMENT";
                case -0x7ff8fff5:
LAB_0071c1c6:
                  return "ERROR_BAD_FORMAT";
                case -0x7ff8fff4:
LAB_0071c1d0:
                  return "ERROR_INVALID_ACCESS & DIERR_NOTACQUIRED";
                }
              }
            }
            else {
              switch(param_1) {
              case -0x7ff8fff2:
                return "E_OUTOFMEMORY";
              case -0x7ff8fff1:
LAB_0071c1ee:
                return "ERROR_INVALID_DRIVE";
              case -0x7ff8fff0:
LAB_0071c1f8:
                return "ERROR_CURRENT_DIRECTORY";
              case -0x7ff8ffef:
LAB_0071c202:
                return "ERROR_NOT_SAME_DEVICE";
              case -0x7ff8ffee:
LAB_0071c21f:
                return "ERROR_NO_MORE_FILES";
              case -0x7ff8ffed:
LAB_0071c229:
                return "ERROR_WRITE_PROTECT";
              case -0x7ff8ffec:
LAB_0071c233:
                return "ERROR_BAD_UNIT";
              case -0x7ff8ffeb:
LAB_0071c23d:
                return "ERROR_NOT_READY & DIERR_NOTINITIALIZED";
              case -0x7ff8ffea:
LAB_0071c247:
                return "ERROR_BAD_COMMAND";
              case -0x7ff8ffe9:
LAB_0071c251:
                return "ERROR_CRC";
              case -0x7ff8ffe8:
LAB_0071c25b:
                return "ERROR_BAD_LENGTH";
              case -0x7ff8ffe7:
LAB_0071c265:
                return "ERROR_SEEK";
              case -0x7ff8ffe6:
LAB_0071c26f:
                return "ERROR_NOT_DOS_DISK";
              case -0x7ff8ffe5:
LAB_0071c279:
                return "ERROR_SECTOR_NOT_FOUND";
              case -0x7ff8ffe4:
LAB_0071c283:
                return "ERROR_OUT_OF_PAPER";
              case -0x7ff8ffe3:
LAB_0071c28d:
                return "ERROR_WRITE_FAULT";
              case -0x7ff8ffe2:
LAB_0071c297:
                return "ERROR_READ_FAULT & DIERR_INPUTLOST";
              case -0x7ff8ffe1:
LAB_0071c2a1:
                return "ERROR_GEN_FAILURE";
              case -0x7ff8ffe0:
LAB_0071c2ab:
                return "ERROR_SHARING_VIOLATION";
              case -0x7ff8ffdf:
LAB_0071c2b5:
                return "ERROR_LOCK_VIOLATION";
              case -0x7ff8ffde:
LAB_0071c2bf:
                return "ERROR_WRONG_DISK";
              case -0x7ff8ffdc:
code_r0x0071c2c9:
                return "ERROR_SHARING_BUFFER_EXCEEDED";
              case -0x7ff8ffda:
code_r0x0071c2d3:
                return "ERROR_HANDLE_EOF";
              case -0x7ff8ffd9:
LAB_0071c2dd:
                return "ERROR_HANDLE_DISK_FULL";
              case -0x7ff8ffce:
LAB_0071c309:
                return "ERROR_NOT_SUPPORTED";
              case -0x7ff8ffcd:
LAB_0071c313:
                return "ERROR_REM_NOT_LIST";
              case -0x7ff8ffcc:
LAB_0071c31d:
                return "ERROR_DUP_NAME";
              case -0x7ff8ffcb:
LAB_0071c327:
                return "ERROR_BAD_NETPATH";
              case -0x7ff8ffca:
LAB_0071c331:
                return "ERROR_NETWORK_BUSY";
              case -0x7ff8ffc9:
LAB_0071c33b:
                return "ERROR_DEV_NOT_EXIST";
              case -0x7ff8ffc8:
LAB_0071c345:
                return "ERROR_TOO_MANY_CMDS";
              case -0x7ff8ffc7:
LAB_0071c34f:
                return "ERROR_ADAP_HDW_ERR";
              case -0x7ff8ffc6:
LAB_0071c359:
                return "ERROR_BAD_NET_RESP";
              case -0x7ff8ffc5:
LAB_0071c363:
                return "ERROR_UNEXP_NET_ERR";
              case -0x7ff8ffc4:
LAB_0071c36d:
                return "ERROR_BAD_REM_ADAP";
              case -0x7ff8ffc3:
LAB_0071c377:
                return "ERROR_PRINTQ_FULL";
              case -0x7ff8ffc2:
LAB_0071c381:
                return "ERROR_NO_SPOOL_SPACE";
              case -0x7ff8ffc1:
LAB_0071c38b:
                return "ERROR_PRINT_CANCELLED";
              case -0x7ff8ffc0:
LAB_0071c395:
                return "ERROR_NETNAME_DELETED";
              case -0x7ff8ffbf:
LAB_0071c39f:
                return "ERROR_NETWORK_ACCESS_DENIED";
              }
            }
          }
          else {
            switch(param_1) {
            case -0x7ff8ffbd:
LAB_0071c3b3:
              return "ERROR_BAD_NET_NAME";
            case -0x7ff8ffbc:
LAB_0071c3bd:
              return "ERROR_TOO_MANY_NAMES";
            case -0x7ff8ffbb:
LAB_0071c3c7:
              return "ERROR_TOO_MANY_SESS";
            case -0x7ff8ffba:
LAB_0071c419:
              return "ERROR_SHARING_PAUSED";
            case -0x7ff8ffb9:
LAB_0071c40f:
              return "ERROR_REQ_NOT_ACCEP";
            case -0x7ff8ffb8:
LAB_0071c405:
              return "ERROR_REDIR_PAUSED";
            case -0x7ff8ffb0:
code_r0x0071c3fb:
              return "ERROR_FILE_EXISTS";
            case -0x7ff8ffae:
LAB_0071c423:
              return "ERROR_CANNOT_MAKE";
            case -0x7ff8ffad:
LAB_0071c45d:
              return "ERROR_FAIL_I24";
            case -0x7ff8ffac:
LAB_0071c453:
              return "ERROR_OUT_OF_STRUCTURES";
            case -0x7ff8ffab:
LAB_0071c449:
              return "ERROR_ALREADY_ASSIGNED";
            case -0x7ff8ffaa:
code_r0x0071c43f:
              return "ERROR_INVALID_PASSWORD";
            case -0x7ff8ffa9:
              return "E_INVALIDARG";
            case -0x7ff8ffa8:
LAB_0071c4aa:
              return "ERROR_NET_WRITE_FAULT";
            case -0x7ff8ffa7:
LAB_0071c4a0:
              return "ERROR_NO_PROC_SLOTS";
            case -0x7ff8ff9c:
LAB_0071c496:
              return "ERROR_TOO_MANY_SEMAPHORES";
            case -0x7ff8ff9b:
code_r0x0071c48c:
              return "ERROR_EXCL_SEM_ALREADY_OWNED";
            case -0x7ff8ff9a:
LAB_0071c4b4:
              return "ERROR_SEM_IS_SET";
            case -0x7ff8ff99:
LAB_0071c4ee:
              return "ERROR_TOO_MANY_SEM_REQUESTS";
            case -0x7ff8ff98:
LAB_0071c4e4:
              return "ERROR_INVALID_AT_INTERRUPT_TIME";
            case -0x7ff8ff97:
LAB_0071c4da:
              return "ERROR_SEM_OWNER_DIED";
            case -0x7ff8ff96:
code_r0x0071c4d0:
              return "ERROR_SEM_USER_LIMIT";
            case -0x7ff8ff95:
              goto LAB_0071c4f8;
            case -0x7ff8ff94:
LAB_0071c528:
              return "ERROR_DRIVE_LOCKED";
            case -0x7ff8ff93:
LAB_0071c532:
              return "ERROR_BROKEN_PIPE";
            case -0x7ff8ff92:
LAB_0071c53c:
              return "ERROR_OPEN_FAILED";
            case -0x7ff8ff91:
LAB_0071c546:
              return "ERROR_BUFFER_OVERFLOW";
            case -0x7ff8ff90:
LAB_0071c550:
              return "ERROR_DISK_FULL";
            case -0x7ff8ff8f:
LAB_0071c55a:
              return "ERROR_NO_MORE_SEARCH_HANDLES";
            case -0x7ff8ff8e:
LAB_0071c564:
              return "ERROR_INVALID_TARGET_HANDLE";
            case -0x7ff8ff8b:
LAB_0071c56e:
              return "ERROR_INVALID_CATEGORY";
            case -0x7ff8ff8a:
LAB_0071c578:
              return "ERROR_INVALID_VERIFY_SWITCH";
            case -0x7ff8ff89:
LAB_0071c582:
              return "ERROR_BAD_DRIVER_LEVEL & DIERR_BADDRIVERVER";
            case -0x7ff8ff88:
LAB_0071c58c:
              return "ERROR_CALL_NOT_IMPLEMENTED";
            case -0x7ff8ff87:
LAB_0071c596:
              return "ERROR_SEM_TIMEOUT";
            case -0x7ff8ff86:
LAB_0071c5a0:
              return "ERROR_INSUFFICIENT_BUFFER";
            case -0x7ff8ff85:
LAB_0071c5aa:
              return "ERROR_INVALID_NAME";
            case -0x7ff8ff84:
LAB_0071c5b4:
              return "ERROR_INVALID_LEVEL";
            case -0x7ff8ff83:
LAB_0071c5be:
              return "ERROR_NO_VOLUME_LABEL";
            case -0x7ff8ff82:
LAB_0071c5c8:
              return "ERROR_MOD_NOT_FOUND";
            case -0x7ff8ff81:
LAB_0071c5d2:
              return "ERROR_PROC_NOT_FOUND";
            case -0x7ff8ff80:
LAB_0071c5dc:
              return "ERROR_WAIT_NO_CHILDREN";
            case -0x7ff8ff7f:
LAB_0071c5e6:
              return "ERROR_CHILD_NOT_COMPLETE";
            case -0x7ff8ff7e:
LAB_0071c5f0:
              return "ERROR_DIRECT_ACCESS_HANDLE";
            case -0x7ff8ff7d:
LAB_0071c5fa:
              return "ERROR_NEGATIVE_SEEK";
            case -0x7ff8ff7c:
LAB_0071c604:
              return "ERROR_SEEK_ON_DEVICE";
            case -0x7ff8ff7b:
LAB_0071c60e:
              return "ERROR_IS_JOIN_TARGET";
            case -0x7ff8ff7a:
LAB_0071c618:
              return "ERROR_IS_JOINED";
            case -0x7ff8ff79:
LAB_0071c622:
              return "ERROR_IS_SUBSTED";
            case -0x7ff8ff78:
LAB_0071c62c:
              return "ERROR_NOT_JOINED";
            case -0x7ff8ff77:
LAB_0071c636:
              return "ERROR_NOT_SUBSTED";
            case -0x7ff8ff76:
LAB_0071c640:
              return "ERROR_JOIN_TO_JOIN";
            case -0x7ff8ff75:
LAB_0071c64a:
              return "ERROR_SUBST_TO_SUBST";
            case -0x7ff8ff74:
LAB_0071c654:
              return "ERROR_JOIN_TO_SUBST";
            case -0x7ff8ff73:
LAB_0071c65e:
              return "ERROR_SUBST_TO_JOIN";
            case -0x7ff8ff72:
LAB_0071c668:
              return "ERROR_BUSY_DRIVE";
            case -0x7ff8ff71:
LAB_0071c672:
              return "ERROR_SAME_DRIVE";
            case -0x7ff8ff70:
LAB_0071c67c:
              return "ERROR_DIR_NOT_ROOT";
            case -0x7ff8ff6f:
LAB_0071c686:
              return "ERROR_DIR_NOT_EMPTY";
            case -0x7ff8ff6e:
LAB_0071c690:
              return "ERROR_IS_SUBST_PATH";
            case -0x7ff8ff6d:
LAB_0071c69a:
              return "ERROR_IS_JOIN_PATH";
            case -0x7ff8ff6c:
LAB_0071c6a4:
              return "ERROR_PATH_BUSY";
            case -0x7ff8ff6b:
LAB_0071c6ae:
              return "ERROR_IS_SUBST_TARGET";
            case -0x7ff8ff6a:
LAB_0071c6b8:
              return "ERROR_SYSTEM_TRACE";
            case -0x7ff8ff69:
LAB_0071c6c2:
              return "ERROR_INVALID_EVENT_COUNT";
            case -0x7ff8ff68:
LAB_0071c6cc:
              return "ERROR_TOO_MANY_MUXWAITERS";
            case -0x7ff8ff67:
LAB_0071c6d6:
              return "ERROR_INVALID_LIST_FORMAT";
            case -0x7ff8ff66:
LAB_0071c6e0:
              return "ERROR_LABEL_TOO_LONG";
            case -0x7ff8ff65:
LAB_0071c6ea:
              return "ERROR_TOO_MANY_TCBS";
            case -0x7ff8ff64:
LAB_0071c6f4:
              return "ERROR_SIGNAL_REFUSED";
            case -0x7ff8ff63:
LAB_0071c6fe:
              return "ERROR_DISCARDED";
            case -0x7ff8ff62:
LAB_0071c708:
              return "ERROR_NOT_LOCKED";
            case -0x7ff8ff61:
LAB_0071c712:
              return "ERROR_BAD_THREADID_ADDR";
            case -0x7ff8ff60:
LAB_0071c71c:
              return "ERROR_BAD_ARGUMENTS";
            case -0x7ff8ff5f:
LAB_0071c726:
              return "ERROR_BAD_PATHNAME";
            case -0x7ff8ff5e:
LAB_0071c730:
              return "ERROR_SIGNAL_PENDING";
            case -0x7ff8ff5c:
code_r0x0071c73a:
              return "ERROR_MAX_THRDS_REACHED";
            case -0x7ff8ff59:
code_r0x0071c744:
              return "ERROR_LOCK_FAILED";
            case -0x7ff8ff56:
code_r0x0071c74e:
              return "ERROR_BUSY & DIERR_ACQUIRED";
            case -0x7ff8ff53:
code_r0x0071c758:
              return "ERROR_CANCEL_VIOLATION";
            }
          }
        }
        else if (param_1 < -0x7ff8ff0f) {
          if (param_1 == -0x7ff8ff10) {
LAB_0071c8d4:
            return "ERROR_VC_DISCONNECTED";
          }
          switch(param_1) {
          case -0x7ff8ff4c:
code_r0x0071c76c:
            return "ERROR_INVALID_SEGMENT_NUMBER";
          case -0x7ff8ff4a:
code_r0x0071c776:
            return "ERROR_INVALID_ORDINAL";
          case -0x7ff8ff49:
code_r0x0071c780:
            return "ERROR_ALREADY_EXISTS";
          case -0x7ff8ff46:
code_r0x0071c78a:
            return "ERROR_INVALID_FLAG_NUMBER";
          case -0x7ff8ff45:
code_r0x0071c794:
            return "ERROR_SEM_NOT_FOUND";
          case -0x7ff8ff44:
code_r0x0071c79e:
            return "ERROR_INVALID_STARTING_CODESEG";
          case -0x7ff8ff43:
LAB_0071c7a8:
            return "ERROR_INVALID_STACKSEG";
          case -0x7ff8ff42:
LAB_0071c7b2:
            return "ERROR_INVALID_MODULETYPE";
          case -0x7ff8ff41:
LAB_0071c7bc:
            return "ERROR_INVALID_EXE_SIGNATURE";
          case -0x7ff8ff40:
LAB_0071c7c6:
            return "ERROR_EXE_MARKED_INVALID";
          case -0x7ff8ff3f:
LAB_0071c7d0:
            return "ERROR_BAD_EXE_FORMAT";
          case -0x7ff8ff3e:
LAB_0071c7da:
            return "ERROR_ITERATED_DATA_EXCEEDS_64k";
          case -0x7ff8ff3d:
LAB_0071c7e4:
            return "ERROR_INVALID_MINALLOCSIZE";
          case -0x7ff8ff3c:
LAB_0071c7ee:
            return "ERROR_DYNLINK_FROM_INVALID_RING";
          case -0x7ff8ff3b:
LAB_0071c7f8:
            return "ERROR_IOPL_NOT_ENABLED";
          case -0x7ff8ff3a:
LAB_0071c802:
            return "ERROR_INVALID_SEGDPL";
          case -0x7ff8ff39:
LAB_0071c80c:
            return "ERROR_AUTODATASEG_EXCEEDS_64k";
          case -0x7ff8ff36:
LAB_0071c82a:
            return "ERROR_INFLOOP_IN_RELOC_CHAIN";
          case -0x7ff8ff35:
LAB_0071c834:
            return "ERROR_ENVVAR_NOT_FOUND";
          case -0x7ff8ff33:
LAB_0071c83e:
            return "ERROR_NO_SIGNAL_SENT";
          case -0x7ff8ff32:
LAB_0071c848:
            return "ERROR_FILENAME_EXCED_RANGE";
          case -0x7ff8ff31:
LAB_0071c852:
            return "ERROR_RING2_STACK_IN_USE";
          case -0x7ff8ff30:
LAB_0071c85c:
            return "ERROR_META_EXPANSION_TOO_LONG";
          case -0x7ff8ff2f:
LAB_0071c866:
            return "ERROR_INVALID_SIGNAL_NUMBER";
          case -0x7ff8ff2e:
LAB_0071c870:
            return "ERROR_THREAD_1_INACTIVE";
          case -0x7ff8ff2c:
code_r0x0071c87a:
            return "ERROR_LOCKED";
          case -0x7ff8ff2a:
code_r0x0071c884:
            return "ERROR_TOO_MANY_MODULES";
          case -0x7ff8ff29:
code_r0x0071c88e:
            return "ERROR_NESTING_NOT_ALLOWED";
          case -0x7ff8ff28:
code_r0x0071c898:
            return "ERROR_EXE_MACHINE_TYPE_MISMATCH";
          case -0x7ff8ff1a:
LAB_0071c8a2:
            return "ERROR_BAD_PIPE";
          case -0x7ff8ff19:
LAB_0071c8ac:
            return "ERROR_PIPE_BUSY";
          case -0x7ff8ff18:
LAB_0071c8b6:
            return "ERROR_NO_DATA";
          case -0x7ff8ff17:
LAB_0071c8c0:
            return "ERROR_PIPE_NOT_CONNECTED";
          case -0x7ff8ff16:
LAB_0071c8ca:
            return "ERROR_MORE_DATA";
          }
        }
        else if (param_1 < -0x7ff8fbd8) {
          if (param_1 == -0x7ff8fbd9) {
LAB_0071cbf8:
            return "ERROR_FAILED_SERVICE_CONTROLLER_CONNECT";
          }
          if (param_1 < -0x7ff8fc14) {
            if (param_1 == -0x7ff8fc15) {
LAB_0071ca6a:
              return "ERROR_CAN_NOT_COMPLETE";
            }
            if (param_1 < -0x7ff8fed2) {
              if (param_1 == -0x7ff8fed3) {
LAB_0071c9b6:
                return "ERROR_INVALID_OPLOCK_PROTOCOL";
              }
              switch(param_1) {
              case -0x7ff8ff02:
                goto LAB_0071c920;
              case -0x7ff8ff01:
                goto LAB_0071c92a;
              case -0x7ff8fefe:
                goto LAB_0071c934;
              case -0x7ff8fefd:
                goto LAB_0071c93e;
              case -0x7ff8fef6:
                goto LAB_0071c948;
              case -0x7ff8fef5:
                goto LAB_0071c952;
              case -0x7ff8feed:
                goto LAB_0071c95c;
              case -0x7ff8feec:
                goto LAB_0071c966;
              case -0x7ff8feeb:
                goto LAB_0071c970;
              case -0x7ff8feea:
                goto LAB_0071c97a;
              case -0x7ff8fee6:
                goto LAB_0071c984;
              case -0x7ff8fee0:
                goto LAB_0071c98e;
              case -0x7ff8fed6:
                goto LAB_0071c998;
              case -0x7ff8fed5:
                goto LAB_0071c9a2;
              case -0x7ff8fed4:
                goto LAB_0071c9ac;
              }
            }
            else if (param_1 < -0x7ff8fc1d) {
              if (param_1 == -0x7ff8fc1e) {
LAB_0071ca02:
                return "ERROR_EA_ACCESS_DENIED";
              }
              if (param_1 == -0x7ff8fed2) goto LAB_0071c9c0;
              if (param_1 == -0x7ff8fed1) goto LAB_0071ca34;
              if (param_1 == -0x7ff8fec3) goto LAB_0071ca2a;
              if (param_1 == -0x7ff8fe19) goto LAB_0071ca20;
              if (param_1 == -0x7ff8fdea) goto LAB_0071ca16;
              if (param_1 == -0x7ff8fde9) goto LAB_0071ca0c;
              if (param_1 == -0x7ff8fde8) goto LAB_00718029;
            }
            else {
              if (param_1 == -0x7ff8fc1d) goto LAB_0071ca3e;
              if (param_1 == -0x7ff8fc1c) goto LAB_0071ca9c;
              if (param_1 == -0x7ff8fc1b) goto LAB_0071ca92;
              if (param_1 == -0x7ff8fc1a) goto LAB_0071ca88;
              if (param_1 == -0x7ff8fc19) goto LAB_0071ca7e;
              if (param_1 == -0x7ff8fc17) goto LAB_0071ca74;
              if (param_1 == -0x7ff8fc16) goto LAB_00718080;
            }
          }
          else {
            switch(param_1) {
            case -0x7ff8fc14:
              goto LAB_0071caa6;
            case -0x7ff8fc13:
              goto LAB_0071cacc;
            case -0x7ff8fc12:
              goto LAB_0071cad6;
            case -0x7ff8fc11:
              goto LAB_0071cae0;
            case -0x7ff8fc10:
              goto LAB_0071caea;
            case -0x7ff8fc0f:
              goto LAB_0071caf4;
            case -0x7ff8fc0e:
              goto LAB_0071cafe;
            case -0x7ff8fc0d:
              goto LAB_0071cb08;
            case -0x7ff8fc0c:
              goto LAB_0071cb12;
            case -0x7ff8fc0b:
              goto LAB_0071cb1c;
            case -0x7ff8fc0a:
              goto LAB_0071cb26;
            case -0x7ff8fc09:
              goto LAB_0071cb30;
            case -0x7ff8fc08:
              goto LAB_0071cb3a;
            case -0x7ff8fc07:
              goto LAB_0071cb44;
            case -0x7ff8fc06:
              goto LAB_0071cb4e;
            case -0x7ff8fc05:
              goto LAB_0071cb58;
            case -0x7ff8fc04:
              goto LAB_0071cb62;
            case -0x7ff8fc03:
              goto LAB_0071cb6c;
            case -0x7ff8fc02:
              goto LAB_0071cb76;
            case -0x7ff8fbe5:
              goto LAB_0071cb80;
            case -0x7ff8fbe4:
              goto LAB_0071cb8a;
            case -0x7ff8fbe3:
              goto LAB_0071cb94;
            case -0x7ff8fbe2:
              goto LAB_0071cb9e;
            case -0x7ff8fbe1:
              goto LAB_0071cba8;
            case -0x7ff8fbe0:
              goto LAB_0071cbb2;
            case -0x7ff8fbdf:
              goto LAB_0071cbbc;
            case -0x7ff8fbde:
              goto LAB_0071cbc6;
            case -0x7ff8fbdd:
              goto LAB_0071cbd0;
            case -0x7ff8fbdc:
              goto LAB_0071cbda;
            case -0x7ff8fbdb:
              goto LAB_0071cbe4;
            case -0x7ff8fbda:
              goto LAB_0071cbee;
            }
          }
        }
        else {
          switch(param_1) {
          case -0x7ff8fbd8:
            goto LAB_0071cc02;
          case -0x7ff8fbd7:
            goto LAB_0071cc23;
          case -0x7ff8fbd6:
            goto LAB_0071cc2d;
          case -0x7ff8fbd5:
            goto LAB_0071cc37;
          case -0x7ff8fbd4:
            goto LAB_0071cc41;
          case -0x7ff8fbd3:
            goto LAB_0071cc4b;
          case -0x7ff8fbd2:
            goto LAB_0071cc55;
          case -0x7ff8fbd1:
            goto LAB_0071cc5f;
          case -0x7ff8fbd0:
            goto LAB_0071cc69;
          case -0x7ff8fbcf:
            goto LAB_0071cc73;
          case -0x7ff8fbce:
            goto LAB_0071cc7d;
          case -0x7ff8fbcd:
            goto LAB_0071cc87;
          case -0x7ff8fbcc:
            goto LAB_0071cc91;
          case -0x7ff8fbcb:
            goto LAB_0071cc9b;
          case -0x7ff8fbca:
            goto LAB_0071cca5;
          case -0x7ff8fbc9:
            goto LAB_0071ccaf;
          case -0x7ff8fbc8:
            goto LAB_0071ccb9;
          case -0x7ff8fbc7:
            goto LAB_0071ccc3;
          case -0x7ff8fbc6:
            goto LAB_0071cccd;
          case -0x7ff8fbc5:
            goto LAB_0071ccd7;
          case -0x7ff8fbc4:
            goto LAB_0071d7bd;
          case -0x7ff8fbb4:
            goto LAB_0071cce1;
          case -0x7ff8fbb3:
            goto LAB_0071cceb;
          case -0x7ff8fbb2:
            goto LAB_0071ccf5;
          case -0x7ff8fbb1:
            goto LAB_0071ccff;
          case -0x7ff8fbb0:
            goto LAB_0071cd09;
          case -0x7ff8fbaf:
            goto LAB_0071cd13;
          case -0x7ff8fbae:
            goto LAB_0071cd1d;
          case -0x7ff8fbad:
            goto LAB_0071cd27;
          case -0x7ff8fbac:
            goto LAB_0071cd31;
          case -0x7ff8fbab:
            goto LAB_0071cd3b;
          case -0x7ff8fbaa:
            goto LAB_0071cd45;
          case -0x7ff8fba9:
            goto LAB_0071cd4f;
          case -0x7ff8fba8:
            goto LAB_0071cd59;
          case -0x7ff8fba7:
            goto LAB_0071cd63;
          case -0x7ff8fba6:
            goto LAB_0071cd6d;
          case -0x7ff8fba5:
            goto LAB_0071cd77;
          case -0x7ff8fba4:
            goto LAB_0071cd81;
          case -0x7ff8fba3:
            goto LAB_0071cd8b;
          case -0x7ff8fba2:
            goto LAB_0071cd95;
          case -0x7ff8fba1:
            goto LAB_0071cd9f;
          case -0x7ff8fba0:
            goto LAB_0071cda9;
          case -0x7ff8fb9f:
            goto LAB_0071cdb3;
          case -0x7ff8fb9e:
            goto LAB_0071cdbd;
          case -0x7ff8fb9d:
            goto LAB_0071cdc7;
          case -0x7ff8fb9c:
            goto LAB_0071cdd1;
          case -0x7ff8fb9b:
            goto LAB_0071cddb;
          case -0x7ff8fb9a:
            goto LAB_0071cde5;
          case -0x7ff8fb99:
            goto LAB_0071cdef;
          case -0x7ff8fb98:
            goto LAB_0071cdf9;
          case -0x7ff8fb97:
            goto LAB_0071ce03;
          case -0x7ff8fb96:
            goto LAB_0071ce0d;
          case -0x7ff8fb95:
            goto LAB_0071ce17;
          case -0x7ff8fb94:
            goto LAB_0071ce21;
          case -0x7ff8fb8c:
            goto LAB_0071ce2b;
          case -0x7ff8fb8b:
            goto LAB_0071ce35;
          case -0x7ff8fb8a:
            goto LAB_0071ce3f;
          case -0x7ff8fb82:
            goto LAB_0071ce49;
          case -0x7ff8fb81:
            goto LAB_0071ce53;
          case -0x7ff8fb80:
            goto LAB_0071ce5d;
          case -0x7ff8fb7f:
            goto LAB_0071ce67;
          case -0x7ff8fb7e:
            goto LAB_0071ce71;
          case -0x7ff8fb7d:
            goto LAB_0071ce7b;
          }
        }
      }
      else {
        switch(param_1) {
        case -0x7ff8fb7b:
LAB_0071ce8f:
          return "ERROR_DLL_NOT_FOUND";
        case -0x7ff8fb7a:
LAB_0071ce99:
          return "ERROR_NO_MORE_USER_HANDLES";
        case -0x7ff8fb79:
LAB_0071cea3:
          return "ERROR_MESSAGE_SYNC_ONLY";
        case -0x7ff8fb78:
LAB_0071cead:
          return "ERROR_SOURCE_ELEMENT_EMPTY";
        case -0x7ff8fb77:
LAB_0071ceb7:
          return "ERROR_DESTINATION_ELEMENT_FULL";
        case -0x7ff8fb76:
LAB_0071cec1:
          return "ERROR_ILLEGAL_ELEMENT_ADDRESS";
        case -0x7ff8fb75:
LAB_0071cecb:
          return "ERROR_MAGAZINE_NOT_PRESENT";
        case -0x7ff8fb74:
LAB_0071ced5:
          return "ERROR_DEVICE_REINITIALIZATION_NEEDED";
        case -0x7ff8fb73:
LAB_0071cedf:
          return "ERROR_DEVICE_REQUIRES_CLEANING";
        case -0x7ff8fb72:
LAB_0071cee9:
          return "ERROR_DEVICE_DOOR_OPEN";
        case -0x7ff8fb71:
LAB_0071cef3:
          return "ERROR_DEVICE_NOT_CONNECTED";
        case -0x7ff8fb70:
LAB_0071cefd:
          return "ERROR_NOT_FOUND & E_PROP_ID_UNSUPPORTED";
        case -0x7ff8fb6f:
LAB_0071cf07:
          return "ERROR_NO_MATCH";
        case -0x7ff8fb6e:
LAB_0071cf11:
          return "ERROR_SET_NOT_FOUND & E_PROP_SET_UNSUPPORTED";
        case -0x7ff8fb6d:
LAB_0071cf1b:
          return "ERROR_POINT_NOT_FOUND";
        case -0x7ff8fb6c:
LAB_0071cf25:
          return "ERROR_NO_TRACKING_SERVICE";
        case -0x7ff8fb6b:
LAB_0071cf2f:
          return "ERROR_NO_VOLUME_ID";
        case -0x7ff8fb69:
LAB_0071cf39:
          return "ERROR_UNABLE_TO_REMOVE_REPLACED";
        case -0x7ff8fb68:
LAB_0071cf43:
          return "ERROR_UNABLE_TO_MOVE_REPLACEMENT";
        case -0x7ff8fb67:
LAB_0071cf4d:
          return "ERROR_UNABLE_TO_MOVE_REPLACEMENT_2";
        case -0x7ff8fb66:
LAB_0071cf57:
          return "ERROR_JOURNAL_DELETE_IN_PROGRESS";
        case -0x7ff8fb65:
LAB_0071cf61:
          return "ERROR_JOURNAL_NOT_ACTIVE";
        case -0x7ff8fb64:
LAB_0071cf6b:
          return "ERROR_POTENTIAL_FILE_FOUND";
        case -0x7ff8fb63:
LAB_0071d7c7:
          return "ERROR_JOURNAL_ENTRY_DELETED";
        case -0x7ff8fb50:
LAB_0071cf75:
          return "ERROR_BAD_DEVICE";
        case -0x7ff8fb4f:
LAB_0071cf7f:
          return "ERROR_CONNECTION_UNAVAIL";
        case -0x7ff8fb4e:
LAB_0071cf89:
          return "ERROR_DEVICE_ALREADY_REMEMBERED";
        case -0x7ff8fb4d:
LAB_0071cf93:
          return "ERROR_NO_NET_OR_BAD_PATH";
        case -0x7ff8fb4c:
LAB_0071cf9d:
          return "ERROR_BAD_PROVIDER";
        case -0x7ff8fb4b:
LAB_0071cfa7:
          return "ERROR_CANNOT_OPEN_PROFILE";
        case -0x7ff8fb4a:
LAB_0071cfb1:
          return "ERROR_BAD_PROFILE";
        case -0x7ff8fb49:
LAB_0071cfbb:
          return "ERROR_NOT_CONTAINER";
        case -0x7ff8fb48:
LAB_0071cfc5:
          return "ERROR_EXTENDED_ERROR";
        case -0x7ff8fb47:
LAB_0071cfcf:
          return "ERROR_INVALID_GROUPNAME";
        case -0x7ff8fb46:
LAB_0071cfd9:
          return "ERROR_INVALID_COMPUTERNAME";
        case -0x7ff8fb45:
LAB_0071cfe3:
          return "ERROR_INVALID_EVENTNAME";
        case -0x7ff8fb44:
LAB_0071cfed:
          return "ERROR_INVALID_DOMAINNAME";
        case -0x7ff8fb43:
LAB_0071cff7:
          return "ERROR_INVALID_SERVICENAME";
        case -0x7ff8fb42:
LAB_0071d001:
          return "ERROR_INVALID_NETNAME";
        case -0x7ff8fb41:
LAB_0071d00b:
          return "ERROR_INVALID_SHARENAME";
        case -0x7ff8fb40:
LAB_0071d015:
          return "ERROR_INVALID_PASSWORDNAME";
        case -0x7ff8fb3f:
LAB_0071d01f:
          return "ERROR_INVALID_MESSAGENAME";
        case -0x7ff8fb3e:
LAB_0071d029:
          return "ERROR_INVALID_MESSAGEDEST";
        case -0x7ff8fb3d:
LAB_0071d033:
          return "ERROR_SESSION_CREDENTIAL_CONFLICT";
        case -0x7ff8fb3c:
LAB_0071d03d:
          return "ERROR_REMOTE_SESSION_LIMIT_EXCEEDED";
        case -0x7ff8fb3b:
LAB_0071d047:
          return "ERROR_DUP_DOMAINNAME";
        case -0x7ff8fb3a:
LAB_0071d051:
          return "ERROR_NO_NETWORK";
        case -0x7ff8fb39:
LAB_0071d05b:
          return "ERROR_CANCELLED";
        case -0x7ff8fb38:
LAB_0071d065:
          return "ERROR_USER_MAPPED_FILE";
        case -0x7ff8fb37:
LAB_0071d06f:
          return "ERROR_CONNECTION_REFUSED";
        case -0x7ff8fb36:
LAB_0071d079:
          return "ERROR_GRACEFUL_DISCONNECT";
        case -0x7ff8fb35:
LAB_0071d083:
          return "ERROR_ADDRESS_ALREADY_ASSOCIATED";
        case -0x7ff8fb34:
LAB_0071d08d:
          return "ERROR_ADDRESS_NOT_ASSOCIATED";
        case -0x7ff8fb33:
LAB_0071d097:
          return "ERROR_CONNECTION_INVALID";
        case -0x7ff8fb32:
LAB_0071d0a1:
          return "ERROR_CONNECTION_ACTIVE";
        case -0x7ff8fb31:
LAB_0071d0ab:
          return "ERROR_NETWORK_UNREACHABLE";
        case -0x7ff8fb30:
LAB_0071d0b5:
          return "ERROR_HOST_UNREACHABLE";
        case -0x7ff8fb2f:
LAB_0071d0bf:
          return "ERROR_PROTOCOL_UNREACHABLE";
        case -0x7ff8fb2e:
LAB_0071d0c9:
          return "ERROR_PORT_UNREACHABLE";
        case -0x7ff8fb2d:
LAB_0071d0d3:
          return "ERROR_REQUEST_ABORTED";
        case -0x7ff8fb2c:
LAB_0071d0dd:
          return "ERROR_CONNECTION_ABORTED";
        case -0x7ff8fb2b:
LAB_0071d0e7:
          return "ERROR_RETRY";
        case -0x7ff8fb2a:
LAB_0071d0f1:
          return "ERROR_CONNECTION_COUNT_LIMIT";
        case -0x7ff8fb29:
LAB_0071d0fb:
          return "ERROR_LOGIN_TIME_RESTRICTION";
        case -0x7ff8fb28:
LAB_0071d105:
          return "ERROR_LOGIN_WKSTA_RESTRICTION";
        case -0x7ff8fb27:
LAB_0071d10f:
          return "ERROR_INCORRECT_ADDRESS";
        case -0x7ff8fb26:
LAB_0071d119:
          return "ERROR_ALREADY_REGISTERED";
        case -0x7ff8fb25:
LAB_0071d123:
          return "ERROR_SERVICE_NOT_FOUND";
        case -0x7ff8fb24:
LAB_0071d12d:
          return "ERROR_NOT_AUTHENTICATED";
        case -0x7ff8fb23:
LAB_0071d137:
          return "ERROR_NOT_LOGGED_ON";
        case -0x7ff8fb22:
LAB_0071d141:
          return "ERROR_CONTINUE";
        case -0x7ff8fb21:
LAB_0071d14b:
          return "ERROR_ALREADY_INITIALIZED & DIERR_ALREADYINITIALIZED";
        case -0x7ff8fb20:
LAB_0071d155:
          return "ERROR_NO_MORE_DEVICES";
        case -0x7ff8fb1f:
LAB_0071d15f:
          return "ERROR_NO_SUCH_SITE";
        case -0x7ff8fb1e:
LAB_0071d169:
          return "ERROR_DOMAIN_CONTROLLER_EXISTS";
        case -0x7ff8fb1d:
LAB_0071d7d1:
          return "ERROR_ONLY_IF_CONNECTED";
        case -0x7ff8fb1c:
LAB_0071d7db:
          return "ERROR_OVERRIDE_NOCHANGES";
        case -0x7ff8fb1b:
LAB_0071d7e5:
          return "ERROR_BAD_USER_PROFILE";
        case -0x7ff8fb1a:
LAB_0071d7ef:
          return "ERROR_NOT_SUPPORTED_ON_SBS";
        case -0x7ff8fb19:
LAB_0071d7f9:
          return "ERROR_SERVER_SHUTDOWN_IN_PROGRESS";
        case -0x7ff8fb18:
LAB_0071d803:
          return "ERROR_HOST_DOWN";
        case -0x7ff8fb17:
LAB_0071d80d:
          return "ERROR_NON_ACCOUNT_SID";
        case -0x7ff8fb16:
LAB_0071d817:
          return "ERROR_NON_DOMAIN_SID";
        case -0x7ff8fb15:
LAB_0071d821:
          return "ERROR_APPHELP_BLOCK";
        case -0x7ff8fb14:
LAB_0071d82b:
          return "ERROR_ACCESS_DISABLED_BY_POLICY";
        case -0x7ff8fb13:
LAB_0071d835:
          return "ERROR_REG_NAT_CONSUMPTION";
        case -0x7ff8fb12:
LAB_0071d83f:
          return "ERROR_CSCSHARE_OFFLINE";
        case -0x7ff8fb11:
LAB_0071d849:
          return "ERROR_PKINIT_FAILURE";
        case -0x7ff8fb10:
LAB_0071d853:
          return "ERROR_SMARTCARD_SUBSYSTEM_FAILURE";
        case -0x7ff8fb0f:
LAB_0071d85d:
          return "ERROR_DOWNGRADE_DETECTED";
        case -0x7ff8fb09:
code_r0x0071d867:
          return "ERROR_MACHINE_LOCKED";
        case -0x7ff8fb07:
code_r0x0071d871:
          return "ERROR_CALLBACK_SUPPLIED_INVALID_DATA";
        case -0x7ff8fb06:
code_r0x0071d87b:
          return "ERROR_SYNC_FOREGROUND_REFRESH_REQUIRED";
        case -0x7ff8fb05:
code_r0x0071d885:
          return "ERROR_DRIVER_BLOCKED";
        case -0x7ff8fb04:
code_r0x0071d88f:
          return "ERROR_INVALID_IMPORT_OF_NON_DLL";
        case -0x7ff8faec:
LAB_0071d173:
          return "ERROR_NOT_ALL_ASSIGNED";
        case -0x7ff8faeb:
LAB_0071d17d:
          return "ERROR_SOME_NOT_MAPPED";
        case -0x7ff8faea:
LAB_0071d187:
          return "ERROR_NO_QUOTAS_FOR_ACCOUNT";
        case -0x7ff8fae9:
LAB_0071d191:
          return "ERROR_LOCAL_USER_SESSION_KEY";
        case -0x7ff8fae8:
LAB_0071d19b:
          return "ERROR_NULL_LM_PASSWORD";
        case -0x7ff8fae7:
LAB_0071d1a5:
          return "ERROR_UNKNOWN_REVISION";
        case -0x7ff8fae6:
LAB_0071d1af:
          return "ERROR_REVISION_MISMATCH";
        case -0x7ff8fae5:
LAB_0071d1b9:
          return "ERROR_INVALID_OWNER";
        case -0x7ff8fae4:
LAB_0071d1c3:
          return "ERROR_INVALID_PRIMARY_GROUP";
        case -0x7ff8fae3:
LAB_0071d1cd:
          return "ERROR_NO_IMPERSONATION_TOKEN";
        case -0x7ff8fae2:
LAB_0071d1d7:
          return "ERROR_CANT_DISABLE_MANDATORY";
        case -0x7ff8fae1:
LAB_0071d1e1:
          return "ERROR_NO_LOGON_SERVERS";
        case -0x7ff8fae0:
LAB_0071d1eb:
          return "ERROR_NO_SUCH_LOGON_SESSION";
        case -0x7ff8fadf:
LAB_0071d1f5:
          return "ERROR_NO_SUCH_PRIVILEGE";
        case -0x7ff8fade:
LAB_0071d1ff:
          return "ERROR_PRIVILEGE_NOT_HELD";
        case -0x7ff8fadd:
LAB_0071d209:
          return "ERROR_INVALID_ACCOUNT_NAME";
        case -0x7ff8fadc:
LAB_0071d213:
          return "ERROR_USER_EXISTS";
        case -0x7ff8fadb:
LAB_0071d21d:
          return "ERROR_NO_SUCH_USER";
        case -0x7ff8fada:
LAB_0071d227:
          return "ERROR_GROUP_EXISTS";
        case -0x7ff8fad9:
LAB_0071d231:
          return "ERROR_NO_SUCH_GROUP";
        case -0x7ff8fad8:
LAB_0071d23b:
          return "ERROR_MEMBER_IN_GROUP";
        case -0x7ff8fad7:
LAB_0071d245:
          return "ERROR_MEMBER_NOT_IN_GROUP";
        case -0x7ff8fad6:
LAB_0071d24f:
          return "ERROR_LAST_ADMIN";
        case -0x7ff8fad5:
LAB_0071d259:
          return "ERROR_WRONG_PASSWORD";
        case -0x7ff8fad4:
LAB_0071d263:
          return "ERROR_ILL_FORMED_PASSWORD";
        case -0x7ff8fad3:
LAB_0071d26d:
          return "ERROR_PASSWORD_RESTRICTION";
        case -0x7ff8fad2:
LAB_0071d277:
          return "ERROR_LOGON_FAILURE";
        case -0x7ff8fad1:
LAB_0071d281:
          return "ERROR_ACCOUNT_RESTRICTION";
        case -0x7ff8fad0:
LAB_0071d28b:
          return "ERROR_INVALID_LOGON_HOURS";
        case -0x7ff8facf:
LAB_0071d295:
          return "ERROR_INVALID_WORKSTATION";
        case -0x7ff8face:
LAB_0071d29f:
          return "ERROR_PASSWORD_EXPIRED";
        case -0x7ff8facd:
LAB_0071d2a9:
          return "ERROR_ACCOUNT_DISABLED";
        case -0x7ff8facc:
LAB_0071d2b3:
          return "ERROR_NONE_MAPPED";
        case -0x7ff8facb:
LAB_0071d2bd:
          return "ERROR_TOO_MANY_LUIDS_REQUESTED";
        case -0x7ff8faca:
LAB_0071d2c7:
          return "ERROR_LUIDS_EXHAUSTED";
        case -0x7ff8fac9:
LAB_0071d2d1:
          return "ERROR_INVALID_SUB_AUTHORITY";
        case -0x7ff8fac8:
LAB_0071d2db:
          return "ERROR_INVALID_ACL";
        case -0x7ff8fac7:
LAB_0071d2e5:
          return "ERROR_INVALID_SID";
        case -0x7ff8fac6:
LAB_0071d2ef:
          return "ERROR_INVALID_SECURITY_DESCR";
        case -0x7ff8fac4:
LAB_0071d2f9:
          return "ERROR_BAD_INHERITANCE_ACL";
        case -0x7ff8fac3:
LAB_0071d303:
          return "ERROR_SERVER_DISABLED";
        case -0x7ff8fac2:
LAB_0071d30d:
          return "ERROR_SERVER_NOT_DISABLED";
        case -0x7ff8fac1:
LAB_0071d317:
          return "ERROR_INVALID_ID_AUTHORITY";
        case -0x7ff8fac0:
LAB_0071d321:
          return "ERROR_ALLOTTED_SPACE_EXCEEDED";
        case -0x7ff8fabf:
LAB_0071d32b:
          return "ERROR_INVALID_GROUP_ATTRIBUTES";
        case -0x7ff8fabe:
LAB_0071d335:
          return "ERROR_BAD_IMPERSONATION_LEVEL";
        case -0x7ff8fabd:
LAB_0071d33f:
          return "ERROR_CANT_OPEN_ANONYMOUS";
        case -0x7ff8fabc:
LAB_0071d349:
          return "ERROR_BAD_VALIDATION_CLASS";
        case -0x7ff8fabb:
LAB_0071d353:
          return "ERROR_BAD_TOKEN_TYPE";
        case -0x7ff8faba:
LAB_0071d35d:
          return "ERROR_NO_SECURITY_ON_OBJECT";
        case -0x7ff8fab9:
LAB_0071d367:
          return "ERROR_CANT_ACCESS_DOMAIN_INFO";
        case -0x7ff8fab8:
LAB_0071d371:
          return "ERROR_INVALID_SERVER_STATE";
        case -0x7ff8fab7:
LAB_0071d37b:
          return "ERROR_INVALID_DOMAIN_STATE";
        case -0x7ff8fab6:
LAB_0071d385:
          return "ERROR_INVALID_DOMAIN_ROLE";
        case -0x7ff8fab5:
LAB_0071d38f:
          return "ERROR_NO_SUCH_DOMAIN";
        case -0x7ff8fab4:
LAB_0071d399:
          return "ERROR_DOMAIN_EXISTS";
        case -0x7ff8fab3:
LAB_0071d3a3:
          return "ERROR_DOMAIN_LIMIT_EXCEEDED";
        case -0x7ff8fab2:
LAB_0071d3ad:
          return "ERROR_INTERNAL_DB_CORRUPTION";
        case -0x7ff8fab1:
LAB_0071d3b7:
          return "ERROR_INTERNAL_ERROR";
        case -0x7ff8fab0:
LAB_0071d3c1:
          return "ERROR_GENERIC_NOT_MAPPED";
        case -0x7ff8faaf:
LAB_0071d3cb:
          return "ERROR_BAD_DESCRIPTOR_FORMAT";
        case -0x7ff8faae:
LAB_0071d3d5:
          return "ERROR_NOT_LOGON_PROCESS";
        case -0x7ff8faad:
LAB_0071d3df:
          return "ERROR_LOGON_SESSION_EXISTS";
        case -0x7ff8faac:
LAB_0071d3e9:
          return "ERROR_NO_SUCH_PACKAGE";
        case -0x7ff8faab:
LAB_0071d3f3:
          return "ERROR_BAD_LOGON_SESSION_STATE";
        case -0x7ff8faaa:
LAB_0071d3fd:
          return "ERROR_LOGON_SESSION_COLLISION";
        case -0x7ff8faa9:
LAB_0071d407:
          return "ERROR_INVALID_LOGON_TYPE";
        case -0x7ff8faa8:
LAB_0071d411:
          return "ERROR_CANNOT_IMPERSONATE";
        case -0x7ff8faa7:
LAB_0071d41b:
          return "ERROR_RXACT_INVALID_STATE";
        case -0x7ff8faa6:
LAB_0071d425:
          return "ERROR_RXACT_COMMIT_FAILURE";
        case -0x7ff8faa5:
LAB_0071d42f:
          return "ERROR_SPECIAL_ACCOUNT";
        case -0x7ff8faa4:
LAB_0071d439:
          return "ERROR_SPECIAL_GROUP";
        case -0x7ff8faa3:
LAB_0071d443:
          return "ERROR_SPECIAL_USER";
        case -0x7ff8faa2:
LAB_0071d44d:
          return "ERROR_MEMBERS_PRIMARY_GROUP";
        case -0x7ff8faa1:
LAB_0071d457:
          return "ERROR_TOKEN_ALREADY_IN_USE";
        case -0x7ff8faa0:
LAB_0071d461:
          return "ERROR_NO_SUCH_ALIAS";
        case -0x7ff8fa9f:
LAB_0071d46b:
          return "ERROR_MEMBER_NOT_IN_ALIAS";
        case -0x7ff8fa9e:
LAB_0071d475:
          return "ERROR_MEMBER_IN_ALIAS";
        case -0x7ff8fa9d:
LAB_0071d47f:
          return "ERROR_ALIAS_EXISTS";
        case -0x7ff8fa9c:
LAB_0071d489:
          return "ERROR_LOGON_NOT_GRANTED";
        case -0x7ff8fa9b:
LAB_0071d493:
          return "ERROR_TOO_MANY_SECRETS";
        case -0x7ff8fa9a:
LAB_0071d49d:
          return "ERROR_SECRET_TOO_LONG";
        case -0x7ff8fa99:
LAB_0071d4a7:
          return "ERROR_INTERNAL_DB_ERROR";
        case -0x7ff8fa98:
LAB_0071d4b1:
          return "ERROR_TOO_MANY_CONTEXT_IDS";
        case -0x7ff8fa97:
LAB_0071d4bb:
          return "ERROR_LOGON_TYPE_NOT_GRANTED";
        case -0x7ff8fa96:
LAB_0071d4c5:
          return "ERROR_NT_CROSS_ENCRYPTION_REQUIRED";
        case -0x7ff8fa95:
LAB_0071d4cf:
          return "ERROR_NO_SUCH_MEMBER";
        case -0x7ff8fa94:
LAB_0071d4d9:
          return "ERROR_INVALID_MEMBER";
        case -0x7ff8fa93:
LAB_0071d4e3:
          return "ERROR_TOO_MANY_SIDS";
        case -0x7ff8fa92:
LAB_0071d4ed:
          return "ERROR_LM_CROSS_ENCRYPTION_REQUIRED";
        case -0x7ff8fa91:
LAB_0071d4f7:
          return "ERROR_NO_INHERITANCE";
        case -0x7ff8fa90:
LAB_0071d501:
          return "ERROR_FILE_CORRUPT";
        case -0x7ff8fa8f:
LAB_0071d50b:
          return "ERROR_DISK_CORRUPT";
        case -0x7ff8fa8e:
LAB_0071d515:
          return "ERROR_NO_USER_SESSION_KEY";
        case -0x7ff8fa8d:
LAB_0071d51f:
          return "ERROR_LICENSE_QUOTA_EXCEEDED";
        case -0x7ff8fa8c:
LAB_0071d529:
          return "ERROR_WRONG_TARGET_NAME";
        case -0x7ff8fa8b:
LAB_0071d533:
          return "ERROR_MUTUAL_AUTH_FAILED";
        case -0x7ff8fa8a:
LAB_0071d53d:
          return "ERROR_TIME_SKEW";
        case -0x7ff8fa89:
LAB_0071d899:
          return "ERROR_CURRENT_DOMAIN_NOT_ALLOWED";
        case -0x7ff8fa88:
LAB_0071d547:
          return "ERROR_INVALID_WINDOW_HANDLE";
        case -0x7ff8fa87:
LAB_0071d551:
          return "ERROR_INVALID_MENU_HANDLE";
        case -0x7ff8fa86:
LAB_0071d55b:
          return "ERROR_INVALID_CURSOR_HANDLE";
        case -0x7ff8fa85:
LAB_0071d565:
          return "ERROR_INVALID_ACCEL_HANDLE";
        case -0x7ff8fa84:
LAB_0071d56f:
          return "ERROR_INVALID_HOOK_HANDLE";
        case -0x7ff8fa83:
LAB_0071d579:
          return "ERROR_INVALID_DWP_HANDLE";
        case -0x7ff8fa82:
LAB_0071d583:
          return "ERROR_TLW_WITH_WSCHILD";
        case -0x7ff8fa81:
LAB_0071d58d:
          return "ERROR_CANNOT_FIND_WND_CLASS";
        case -0x7ff8fa80:
LAB_0071d597:
          return "ERROR_WINDOW_OF_OTHER_THREAD";
        case -0x7ff8fa7f:
LAB_0071d5a1:
          return "ERROR_HOTKEY_ALREADY_REGISTERED";
        case -0x7ff8fa7e:
LAB_0071d5ab:
          return "ERROR_CLASS_ALREADY_EXISTS";
        case -0x7ff8fa7d:
LAB_0071d5b5:
          return "ERROR_CLASS_DOES_NOT_EXIST";
        case -0x7ff8fa7c:
LAB_0071d5bf:
          return "ERROR_CLASS_HAS_WINDOWS";
        case -0x7ff8fa7b:
LAB_0071d5c9:
          return "ERROR_INVALID_INDEX";
        case -0x7ff8fa7a:
LAB_0071d5d3:
          return "ERROR_INVALID_ICON_HANDLE";
        case -0x7ff8fa79:
LAB_0071d5dd:
          return "ERROR_PRIVATE_DIALOG_INDEX";
        case -0x7ff8fa78:
LAB_0071d5e7:
          return "ERROR_LISTBOX_ID_NOT_FOUND";
        case -0x7ff8fa77:
LAB_0071d5f1:
          return "ERROR_NO_WILDCARD_CHARACTERS";
        case -0x7ff8fa76:
LAB_0071d5fb:
          return "ERROR_CLIPBOARD_NOT_OPEN";
        case -0x7ff8fa75:
LAB_0071d605:
          return "ERROR_HOTKEY_NOT_REGISTERED";
        case -0x7ff8fa74:
LAB_0071d60f:
          return "ERROR_WINDOW_NOT_DIALOG";
        case -0x7ff8fa73:
LAB_0071d619:
          return "ERROR_CONTROL_ID_NOT_FOUND";
        case -0x7ff8fa72:
LAB_0071d623:
          return "ERROR_INVALID_COMBOBOX_MESSAGE";
        case -0x7ff8fa71:
LAB_0071d62d:
          return "ERROR_WINDOW_NOT_COMBOBOX";
        case -0x7ff8fa70:
LAB_0071d637:
          return "ERROR_INVALID_EDIT_HEIGHT";
        case -0x7ff8fa6f:
LAB_0071d641:
          return "ERROR_DC_NOT_FOUND";
        case -0x7ff8fa6e:
LAB_0071d64b:
          return "ERROR_INVALID_HOOK_FILTER";
        case -0x7ff8fa6d:
LAB_0071d655:
          return "ERROR_INVALID_FILTER_PROC";
        case -0x7ff8fa6c:
LAB_0071d65f:
          return "ERROR_HOOK_NEEDS_HMOD";
        case -0x7ff8fa6b:
LAB_0071d669:
          return "ERROR_GLOBAL_ONLY_HOOK";
        case -0x7ff8fa6a:
LAB_0071d673:
          return "ERROR_JOURNAL_HOOK_SET";
        case -0x7ff8fa69:
LAB_0071d67d:
          return "ERROR_HOOK_NOT_INSTALLED";
        case -0x7ff8fa68:
LAB_0071d687:
          return "ERROR_INVALID_LB_MESSAGE";
        case -0x7ff8fa67:
LAB_0071d691:
          return "ERROR_SETCOUNT_ON_BAD_LB";
        case -0x7ff8fa66:
LAB_0071d69b:
          return "ERROR_LB_WITHOUT_TABSTOPS";
        case -0x7ff8fa65:
LAB_0071d6a5:
          return "ERROR_DESTROY_OBJECT_OF_OTHER_THREAD";
        case -0x7ff8fa64:
LAB_0071d6af:
          return "ERROR_CHILD_WINDOW_MENU";
        case -0x7ff8fa63:
LAB_0071d6b9:
          return "ERROR_NO_SYSTEM_MENU";
        case -0x7ff8fa62:
LAB_0071d6c3:
          return "ERROR_INVALID_MSGBOX_STYLE";
        case -0x7ff8fa61:
LAB_0071d6cd:
          return "ERROR_INVALID_SPI_VALUE";
        case -0x7ff8fa60:
LAB_0071d6d7:
          return "ERROR_SCREEN_ALREADY_LOCKED";
        case -0x7ff8fa5f:
LAB_0071d6e1:
          return "ERROR_HWNDS_HAVE_DIFF_PARENT";
        case -0x7ff8fa5e:
LAB_0071d6eb:
          return "ERROR_NOT_CHILD_WINDOW";
        case -0x7ff8fa5d:
LAB_0071d6f5:
          return "ERROR_INVALID_GW_COMMAND";
        case -0x7ff8fa5c:
LAB_0071d6ff:
          return "ERROR_INVALID_THREAD_ID";
        case -0x7ff8fa5b:
LAB_0071d709:
          return "ERROR_NON_MDICHILD_WINDOW";
        case -0x7ff8fa5a:
LAB_0071d713:
          return "ERROR_POPUP_ALREADY_ACTIVE";
        case -0x7ff8fa59:
LAB_0071d71d:
          return "ERROR_NO_SCROLLBARS";
        case -0x7ff8fa58:
LAB_0071d727:
          return "ERROR_INVALID_SCROLLBAR_RANGE";
        case -0x7ff8fa57:
LAB_0071d731:
          return "ERROR_INVALID_SHOWWIN_COMMAND";
        case -0x7ff8fa56:
LAB_0071d73b:
          return "ERROR_NO_SYSTEM_RESOURCES";
        case -0x7ff8fa55:
LAB_0071d745:
          return "ERROR_NONPAGED_SYSTEM_RESOURCES";
        case -0x7ff8fa54:
LAB_0071d74f:
          return "ERROR_PAGED_SYSTEM_RESOURCES";
        case -0x7ff8fa53:
LAB_0071d759:
          return "ERROR_WORKING_SET_QUOTA";
        case -0x7ff8fa52:
LAB_0071d763:
          return "ERROR_PAGEFILE_QUOTA";
        case -0x7ff8fa51:
LAB_0071d76d:
          return "ERROR_COMMITMENT_LIMIT";
        case -0x7ff8fa50:
LAB_0071d777:
          return "ERROR_MENU_ITEM_NOT_FOUND";
        case -0x7ff8fa4f:
LAB_0071d781:
          return "ERROR_INVALID_KEYBOARD_HANDLE";
        case -0x7ff8fa4e:
LAB_0071d78b:
          return "ERROR_HOOK_TYPE_NOT_ALLOWED";
        case -0x7ff8fa4d:
LAB_0071d795:
          return "ERROR_REQUIRES_INTERACTIVE_WINDOWSTATION";
        case -0x7ff8fa4c:
LAB_0071d79f:
          return "ERROR_TIMEOUT";
        case -0x7ff8fa4b:
LAB_0071d7a9:
          return "ERROR_INVALID_MONITOR_HANDLE";
        case -0x7ff8fa24:
code_r0x0071d7b3:
          return "ERROR_EVENTLOG_FILE_CORRUPT";
        case -0x7ff8fa23:
          goto LAB_0071d8a3;
        case -0x7ff8fa22:
code_r0x0071d904:
          return "ERROR_LOG_FILE_FULL";
        case -0x7ff8fa21:
code_r0x0071d90e:
          return "ERROR_EVENTLOG_FILE_CHANGED";
        case -0x7ff8f9bf:
LAB_0071de7c:
          return "ERROR_INSTALL_SERVICE_FAILURE";
        case -0x7ff8f9be:
LAB_0071d918:
          return "ERROR_INSTALL_USEREXIT";
        case -0x7ff8f9bd:
LAB_0071d922:
          return "ERROR_INSTALL_FAILURE";
        case -0x7ff8f9bc:
LAB_0071d92c:
          return "ERROR_INSTALL_SUSPEND";
        case -0x7ff8f9bb:
LAB_0071d936:
          return "ERROR_UNKNOWN_PRODUCT";
        case -0x7ff8f9ba:
LAB_0071d940:
          return "ERROR_UNKNOWN_FEATURE";
        case -0x7ff8f9b9:
LAB_0071d94a:
          return "ERROR_UNKNOWN_COMPONENT";
        case -0x7ff8f9b8:
LAB_0071d954:
          return "ERROR_UNKNOWN_PROPERTY";
        case -0x7ff8f9b7:
LAB_0071d95e:
          return "ERROR_INVALID_HANDLE_STATE";
        case -0x7ff8f9b6:
LAB_0071d968:
          return "ERROR_BAD_CONFIGURATION";
        case -0x7ff8f9b5:
LAB_0071d972:
          return "ERROR_INDEX_ABSENT";
        case -0x7ff8f9b4:
LAB_0071d97c:
          return "ERROR_INSTALL_SOURCE_ABSENT";
        case -0x7ff8f9b3:
LAB_0071de86:
          return "ERROR_INSTALL_PACKAGE_VERSION";
        case -0x7ff8f9b2:
LAB_0071d986:
          return "ERROR_PRODUCT_UNINSTALLED";
        case -0x7ff8f9b1:
LAB_0071d990:
          return "ERROR_BAD_QUERY_SYNTAX";
        case -0x7ff8f9b0:
LAB_0071d99a:
          return "ERROR_INVALID_FIELD";
        case -0x7ff8f9af:
LAB_0071d9a4:
          return "ERROR_DEVICE_REMOVED";
        case -0x7ff8f9ae:
LAB_0071de90:
          return "ERROR_INSTALL_ALREADY_RUNNING";
        case -0x7ff8f9ad:
LAB_0071de9a:
          return "ERROR_INSTALL_PACKAGE_OPEN_FAILED";
        case -0x7ff8f9ac:
LAB_0071dea4:
          return "ERROR_INSTALL_PACKAGE_INVALID";
        case -0x7ff8f9ab:
LAB_0071deae:
          return "ERROR_INSTALL_UI_FAILURE";
        case -0x7ff8f9aa:
LAB_0071deb8:
          return "ERROR_INSTALL_LOG_FAILURE";
        case -0x7ff8f9a9:
LAB_0071dec2:
          return "ERROR_INSTALL_LANGUAGE_UNSUPPORTED";
        case -0x7ff8f9a8:
LAB_0071decc:
          return "ERROR_INSTALL_TRANSFORM_FAILURE";
        case -0x7ff8f9a7:
LAB_0071ded6:
          return "ERROR_INSTALL_PACKAGE_REJECTED";
        case -0x7ff8f9a6:
LAB_0071dee0:
          return "ERROR_FUNCTION_NOT_CALLED";
        case -0x7ff8f9a5:
LAB_0071deea:
          return "ERROR_FUNCTION_FAILED";
        case -0x7ff8f9a4:
LAB_0071def4:
          return "ERROR_INVALID_TABLE";
        case -0x7ff8f9a3:
LAB_0071defe:
          return "ERROR_DATATYPE_MISMATCH";
        case -0x7ff8f9a2:
LAB_0071df08:
          return "ERROR_UNSUPPORTED_TYPE";
        case -0x7ff8f9a1:
LAB_0071df12:
          return "ERROR_CREATE_FAILED";
        case -0x7ff8f9a0:
LAB_0071df1c:
          return "ERROR_INSTALL_TEMP_UNWRITABLE";
        case -0x7ff8f99f:
LAB_0071df26:
          return "ERROR_INSTALL_PLATFORM_UNSUPPORTED";
        case -0x7ff8f99e:
LAB_0071df30:
          return "ERROR_INSTALL_NOTUSED";
        case -0x7ff8f99d:
LAB_0071df3a:
          return "ERROR_PATCH_PACKAGE_OPEN_FAILED";
        case -0x7ff8f99c:
LAB_0071df44:
          return "ERROR_PATCH_PACKAGE_INVALID";
        case -0x7ff8f99b:
LAB_0071df4e:
          return "ERROR_PATCH_PACKAGE_UNSUPPORTED";
        case -0x7ff8f99a:
LAB_0071df58:
          return "ERROR_PRODUCT_VERSION";
        case -0x7ff8f999:
LAB_0071df62:
          return "ERROR_INVALID_COMMAND_LINE";
        case -0x7ff8f998:
LAB_0071df6c:
          return "ERROR_INSTALL_REMOTE_DISALLOWED";
        case -0x7ff8f997:
LAB_0071df76:
          return "ERROR_SUCCESS_REBOOT_INITIATED";
        case -0x7ff8f996:
LAB_0071df80:
          return "ERROR_PATCH_TARGET_NOT_FOUND";
        case -0x7ff8f995:
LAB_0071df8a:
          return "ERROR_PATCH_PACKAGE_REJECTED";
        case -0x7ff8f994:
LAB_0071df94:
          return "ERROR_INSTALL_TRANSFORM_REJECTED";
        case -0x7ff8f95c:
LAB_0071d9ae:
          return "RPC_S_INVALID_STRING_BINDING";
        case -0x7ff8f95b:
LAB_0071d9b8:
          return "RPC_S_WRONG_KIND_OF_BINDING";
        case -0x7ff8f95a:
LAB_0071d9c2:
          return "RPC_S_INVALID_BINDING";
        case -0x7ff8f959:
LAB_0071d9cc:
          return "RPC_S_PROTSEQ_NOT_SUPPORTED";
        case -0x7ff8f958:
LAB_0071d9d6:
          return "RPC_S_INVALID_RPC_PROTSEQ";
        case -0x7ff8f957:
LAB_0071d9e0:
          return "RPC_S_INVALID_STRING_UUID";
        case -0x7ff8f956:
LAB_0071d9ea:
          return "RPC_S_INVALID_ENDPOINT_FORMAT";
        case -0x7ff8f955:
LAB_0071d9f4:
          return "RPC_S_INVALID_NET_ADDR";
        case -0x7ff8f954:
LAB_0071d9fe:
          return "RPC_S_NO_ENDPOINT_FOUND";
        case -0x7ff8f953:
LAB_0071da08:
          return "RPC_S_INVALID_TIMEOUT";
        case -0x7ff8f952:
LAB_0071da12:
          return "RPC_S_OBJECT_NOT_FOUND";
        case -0x7ff8f951:
LAB_0071da1c:
          return "RPC_S_ALREADY_REGISTERED";
        case -0x7ff8f950:
LAB_0071da26:
          return "RPC_S_TYPE_ALREADY_REGISTERED";
        case -0x7ff8f94f:
LAB_0071da30:
          return "RPC_S_ALREADY_LISTENING";
        case -0x7ff8f94e:
LAB_0071da3a:
          return "RPC_S_NO_PROTSEQS_REGISTERED";
        case -0x7ff8f94d:
LAB_0071da44:
          return "RPC_S_NOT_LISTENING";
        case -0x7ff8f94c:
LAB_0071da4e:
          return "RPC_S_UNKNOWN_MGR_TYPE";
        case -0x7ff8f94b:
LAB_0071da58:
          return "RPC_S_UNKNOWN_IF";
        case -0x7ff8f94a:
LAB_0071da62:
          return "RPC_S_NO_BINDINGS";
        case -0x7ff8f949:
LAB_0071da6c:
          return "RPC_S_NO_PROTSEQS";
        case -0x7ff8f948:
LAB_0071da76:
          return "RPC_S_CANT_CREATE_ENDPOINT";
        }
      }
    }
    else if (param_1 < -0x7ff8f735) {
      if (param_1 == -0x7ff8f736) {
LAB_0071e2b6:
        return "ERROR_NOT_CONNECTED";
      }
      if (param_1 + 0x7ff8f946U < 0x1e1) {
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
        switch(*(undefined1 *)(param_1 + -0x7f94d302)) {
        case 0:
LAB_0071da8a:
          return "RPC_S_SERVER_UNAVAILABLE";
        case 1:
LAB_0071da94:
          return "RPC_S_SERVER_TOO_BUSY";
        case 2:
LAB_0071da9e:
          return "RPC_S_INVALID_NETWORK_OPTIONS";
        case 3:
LAB_0071daa8:
          return "RPC_S_NO_CALL_ACTIVE";
        case 4:
LAB_0071dab2:
          return "RPC_S_CALL_FAILED";
        case 5:
LAB_0071dabc:
          return "RPC_S_CALL_FAILED_DNE";
        case 6:
LAB_0071dac6:
          return "RPC_S_PROTOCOL_ERROR";
        case 7:
LAB_0071dad0:
          return "RPC_S_UNSUPPORTED_TRANS_SYN";
        case 8:
LAB_0071dada:
          return "RPC_S_UNSUPPORTED_TYPE";
        case 9:
LAB_0071dae4:
          return "RPC_S_INVALID_TAG";
        case 10:
LAB_0071daee:
          return "RPC_S_INVALID_BOUND";
        case 0xb:
LAB_0071daf8:
          return "RPC_S_NO_ENTRY_NAME";
        case 0xc:
LAB_0071db02:
          return "RPC_S_INVALID_NAME_SYNTAX";
        case 0xd:
LAB_0071db0c:
          return "RPC_S_UNSUPPORTED_NAME_SYNTAX";
        case 0xe:
LAB_0071db16:
          return "RPC_S_UUID_NO_ADDRESS";
        case 0xf:
LAB_0071db20:
          return "RPC_S_DUPLICATE_ENDPOINT";
        case 0x10:
LAB_0071db2a:
          return "RPC_S_UNKNOWN_AUTHN_TYPE";
        case 0x11:
LAB_0071db34:
          return "RPC_S_MAX_CALLS_TOO_SMALL";
        case 0x12:
LAB_0071db3e:
          return "RPC_S_STRING_TOO_LONG";
        case 0x13:
LAB_0071db48:
          return "RPC_S_PROTSEQ_NOT_FOUND";
        case 0x14:
LAB_0071db52:
          return "RPC_S_PROCNUM_OUT_OF_RANGE";
        case 0x15:
LAB_0071db5c:
          return "RPC_S_BINDING_HAS_NO_AUTH";
        case 0x16:
LAB_0071db66:
          return "RPC_S_UNKNOWN_AUTHN_SERVICE";
        case 0x17:
LAB_0071db70:
          return "RPC_S_UNKNOWN_AUTHN_LEVEL";
        case 0x18:
LAB_0071db7a:
          return "RPC_S_INVALID_AUTH_IDENTITY";
        case 0x19:
LAB_0071db84:
          return "RPC_S_UNKNOWN_AUTHZ_SERVICE";
        case 0x1a:
LAB_0071db8e:
          return "EPT_S_INVALID_ENTRY";
        case 0x1b:
LAB_0071db98:
          return "EPT_S_CANT_PERFORM_OP";
        case 0x1c:
LAB_0071dba2:
          return "EPT_S_NOT_REGISTERED";
        case 0x1d:
LAB_0071dbac:
          return "RPC_S_NOTHING_TO_EXPORT";
        case 0x1e:
LAB_0071dbb6:
          return "RPC_S_INCOMPLETE_NAME";
        case 0x1f:
LAB_0071dbc0:
          return "RPC_S_INVALID_VERS_OPTION";
        case 0x20:
LAB_0071dbca:
          return "RPC_S_NO_MORE_MEMBERS";
        case 0x21:
LAB_0071dbd4:
          return "RPC_S_NOT_ALL_OBJS_UNEXPORTED";
        case 0x22:
LAB_0071dbde:
          return "RPC_S_INTERFACE_NOT_FOUND";
        case 0x23:
LAB_0071dbe8:
          return "RPC_S_ENTRY_ALREADY_EXISTS";
        case 0x24:
LAB_0071dbf2:
          return "RPC_S_ENTRY_NOT_FOUND";
        case 0x25:
LAB_0071dbfc:
          return "RPC_S_NAME_SERVICE_UNAVAILABLE";
        case 0x26:
LAB_0071dc06:
          return "RPC_S_INVALID_NAF_ID";
        case 0x27:
LAB_0071dc10:
          return "RPC_S_CANNOT_SUPPORT";
        case 0x28:
LAB_0071dc1a:
          return "RPC_S_NO_CONTEXT_AVAILABLE";
        case 0x29:
LAB_0071dc24:
          return "RPC_S_INTERNAL_ERROR";
        case 0x2a:
LAB_0071dc2e:
          return "RPC_S_ZERO_DIVIDE";
        case 0x2b:
LAB_0071dc38:
          return "RPC_S_ADDRESS_ERROR";
        case 0x2c:
LAB_0071dc42:
          return "RPC_S_FP_DIV_ZERO";
        case 0x2d:
LAB_0071dc4c:
          return "RPC_S_FP_UNDERFLOW";
        case 0x2e:
LAB_0071dc56:
          return "RPC_S_FP_OVERFLOW";
        case 0x2f:
LAB_0071dc60:
          return "RPC_X_NO_MORE_ENTRIES";
        case 0x30:
LAB_0071dc6a:
          return "RPC_X_SS_CHAR_TRANS_OPEN_FAIL";
        case 0x31:
LAB_0071dc74:
          return "RPC_X_SS_CHAR_TRANS_SHORT_FILE";
        case 0x32:
LAB_0071dc7e:
          return "RPC_X_SS_IN_NULL_CONTEXT";
        case 0x33:
LAB_0071dc88:
          return "RPC_X_SS_CONTEXT_DAMAGED";
        case 0x34:
LAB_0071dc92:
          return "RPC_X_SS_HANDLES_MISMATCH";
        case 0x35:
LAB_0071dc9c:
          return "RPC_X_SS_CANNOT_GET_CALL_HANDLE";
        case 0x36:
LAB_0071dca6:
          return "RPC_X_NULL_REF_POINTER";
        case 0x37:
LAB_0071dcb0:
          return "RPC_X_ENUM_VALUE_OUT_OF_RANGE";
        case 0x38:
LAB_0071dcba:
          return "RPC_X_BYTE_COUNT_TOO_SMALL";
        case 0x39:
LAB_0071dcc4:
          return "RPC_X_BAD_STUB_DATA";
        case 0x3a:
LAB_0071dcce:
          return "ERROR_INVALID_USER_BUFFER";
        case 0x3b:
LAB_0071dcd8:
          return "ERROR_UNRECOGNIZED_MEDIA";
        case 0x3c:
LAB_0071dce2:
          return "ERROR_NO_TRUST_LSA_SECRET";
        case 0x3d:
LAB_0071dcec:
          return "ERROR_NO_TRUST_SAM_ACCOUNT";
        case 0x3e:
LAB_0071dcf6:
          return "ERROR_TRUSTED_DOMAIN_FAILURE";
        case 0x3f:
LAB_0071dd00:
          return "ERROR_TRUSTED_RELATIONSHIP_FAILURE";
        case 0x40:
LAB_0071dd0a:
          return "ERROR_TRUST_FAILURE";
        case 0x41:
LAB_0071dd14:
          return "RPC_S_CALL_IN_PROGRESS";
        case 0x42:
LAB_0071dd1e:
          return "ERROR_NETLOGON_NOT_STARTED";
        case 0x43:
LAB_0071dd28:
          return "ERROR_ACCOUNT_EXPIRED";
        case 0x44:
LAB_0071dd32:
          return "ERROR_REDIRECTOR_HAS_OPEN_HANDLES";
        case 0x45:
LAB_0071dd3c:
          return "ERROR_PRINTER_DRIVER_ALREADY_INSTALLED";
        case 0x46:
LAB_0071dd46:
          return "ERROR_UNKNOWN_PORT";
        case 0x47:
LAB_0071dd50:
          return "ERROR_UNKNOWN_PRINTER_DRIVER";
        case 0x48:
LAB_0071dd5a:
          return "ERROR_UNKNOWN_PRINTPROCESSOR";
        case 0x49:
LAB_0071dd64:
          return "ERROR_INVALID_SEPARATOR_FILE";
        case 0x4a:
LAB_0071dd6e:
          return "ERROR_INVALID_PRIORITY";
        case 0x4b:
LAB_0071dd78:
          return "ERROR_INVALID_PRINTER_NAME";
        case 0x4c:
LAB_0071dd82:
          return "ERROR_PRINTER_ALREADY_EXISTS";
        case 0x4d:
LAB_0071dd8c:
          return "ERROR_INVALID_PRINTER_COMMAND";
        case 0x4e:
LAB_0071dd96:
          return "ERROR_INVALID_DATATYPE";
        case 0x4f:
LAB_0071dda0:
          return "ERROR_INVALID_ENVIRONMENT";
        case 0x50:
LAB_0071ddaa:
          return "RPC_S_NO_MORE_BINDINGS";
        case 0x51:
LAB_0071ddb4:
          return "ERROR_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT";
        case 0x52:
LAB_0071ddbe:
          return "ERROR_NOLOGON_WORKSTATION_TRUST_ACCOUNT";
        case 0x53:
LAB_0071ddc8:
          return "ERROR_NOLOGON_SERVER_TRUST_ACCOUNT";
        case 0x54:
LAB_0071ddd2:
          return "ERROR_DOMAIN_TRUST_INCONSISTENT";
        case 0x55:
LAB_0071dddc:
          return "ERROR_SERVER_HAS_OPEN_HANDLES";
        case 0x56:
LAB_0071dde6:
          return "ERROR_RESOURCE_DATA_NOT_FOUND";
        case 0x57:
LAB_0071ddf0:
          return "ERROR_RESOURCE_TYPE_NOT_FOUND";
        case 0x58:
LAB_0071ddfa:
          return "ERROR_RESOURCE_NAME_NOT_FOUND";
        case 0x59:
LAB_0071de04:
          return "ERROR_RESOURCE_LANG_NOT_FOUND";
        case 0x5a:
LAB_0071de0e:
          return "ERROR_NOT_ENOUGH_QUOTA";
        case 0x5b:
LAB_0071de18:
          return "RPC_S_NO_INTERFACES";
        case 0x5c:
LAB_0071de22:
          return "RPC_S_CALL_CANCELLED";
        case 0x5d:
LAB_0071de2c:
          return "RPC_S_BINDING_INCOMPLETE";
        case 0x5e:
LAB_0071de36:
          return "RPC_S_COMM_FAILURE";
        case 0x5f:
LAB_0071de40:
          return "RPC_S_UNSUPPORTED_AUTHN_LEVEL";
        case 0x60:
LAB_0071de4a:
          return "RPC_S_NO_PRINC_NAME";
        case 0x61:
LAB_0071de54:
          return "RPC_S_NOT_RPC_ERROR";
        case 0x62:
LAB_0071de5e:
          return "RPC_S_UUID_LOCAL_ONLY";
        case 99:
LAB_0071de68:
          return "RPC_S_SEC_PKG_ERROR";
        case 100:
LAB_0071de72:
          return "RPC_S_NOT_CANCELLED";
        case 0x65:
LAB_0071df9e:
          return "RPC_X_INVALID_ES_ACTION";
        case 0x66:
LAB_0071dfec:
          return "RPC_X_WRONG_ES_VERSION";
        case 0x67:
LAB_0071dff6:
          return "RPC_X_WRONG_STUB_VERSION";
        case 0x68:
LAB_0071e000:
          return "RPC_X_INVALID_PIPE_OBJECT";
        case 0x69:
LAB_0071e00a:
          return "RPC_X_WRONG_PIPE_ORDER";
        case 0x6a:
LAB_0071e014:
          return "RPC_X_WRONG_PIPE_VERSION";
        case 0x6b:
LAB_0071e01e:
          return "RPC_S_GROUP_MEMBER_NOT_FOUND";
        case 0x6c:
LAB_0071e028:
          return "EPT_S_CANT_CREATE";
        case 0x6d:
LAB_0071e032:
          return "RPC_S_INVALID_OBJECT";
        case 0x6e:
LAB_0071e03c:
          return "ERROR_INVALID_TIME";
        case 0x6f:
LAB_0071e046:
          return "ERROR_INVALID_FORM_NAME";
        case 0x70:
LAB_0071e050:
          return "ERROR_INVALID_FORM_SIZE";
        case 0x71:
LAB_0071e05a:
          return "ERROR_ALREADY_WAITING";
        case 0x72:
LAB_0071e064:
          return "ERROR_PRINTER_DELETED";
        case 0x73:
LAB_0071e06e:
          return "ERROR_INVALID_PRINTER_STATE";
        case 0x74:
LAB_0071e078:
          return "ERROR_PASSWORD_MUST_CHANGE";
        case 0x75:
LAB_0071e082:
          return "ERROR_DOMAIN_CONTROLLER_NOT_FOUND";
        case 0x76:
LAB_0071e08c:
          return "ERROR_ACCOUNT_LOCKED_OUT";
        case 0x77:
LAB_0071e096:
          return "OR_INVALID_OXID";
        case 0x78:
LAB_0071e0a0:
          return "OR_INVALID_OID";
        case 0x79:
LAB_0071e0aa:
          return "OR_INVALID_SET";
        case 0x7a:
LAB_0071e0b4:
          return "RPC_S_SEND_INCOMPLETE";
        case 0x7b:
LAB_0071e0be:
          return "RPC_S_INVALID_ASYNC_HANDLE";
        case 0x7c:
LAB_0071e0c8:
          return "RPC_S_INVALID_ASYNC_CALL";
        case 0x7d:
LAB_0071e0d2:
          return "RPC_X_PIPE_CLOSED";
        case 0x7e:
LAB_0071e0dc:
          return "RPC_X_PIPE_DISCIPLINE_ERROR";
        case 0x7f:
LAB_0071e0e6:
          return "RPC_X_PIPE_EMPTY";
        case 0x80:
LAB_0071e0f0:
          return "ERROR_NO_SITENAME";
        case 0x81:
LAB_0071e0fa:
          return "ERROR_CANT_ACCESS_FILE";
        case 0x82:
LAB_0071e104:
          return "ERROR_CANT_RESOLVE_FILENAME";
        case 0x83:
LAB_0071e12c:
          return "RPC_S_ENTRY_TYPE_MISMATCH";
        case 0x84:
LAB_0071e136:
          return "RPC_S_NOT_ALL_OBJS_EXPORTED";
        case 0x85:
LAB_0071e140:
          return "RPC_S_INTERFACE_NOT_EXPORTED";
        case 0x86:
LAB_0071e14a:
          return "RPC_S_PROFILE_NOT_ADDED";
        case 0x87:
LAB_0071e154:
          return "RPC_S_PRF_ELT_NOT_ADDED";
        case 0x88:
LAB_0071e15e:
          return "RPC_S_PRF_ELT_NOT_REMOVED";
        case 0x89:
LAB_0071e168:
          return "RPC_S_GRP_ELT_NOT_ADDED";
        case 0x8a:
LAB_0071e172:
          return "RPC_S_GRP_ELT_NOT_REMOVED";
        case 0x8b:
LAB_0071e17c:
          return "ERROR_KM_DRIVER_BLOCKED";
        case 0x8c:
LAB_0071e186:
          return "ERROR_CONTEXT_EXPIRED";
        case 0x8d:
LAB_0071e10e:
          return "ERROR_INVALID_PIXEL_FORMAT";
        case 0x8e:
LAB_0071e118:
          return "ERROR_BAD_DRIVER";
        case 0x8f:
LAB_0071e122:
          return "ERROR_INVALID_WINDOW_STYLE";
        case 0x90:
LAB_0071e190:
          return "ERROR_METAFILE_NOT_SUPPORTED";
        case 0x91:
LAB_0071e1d1:
          return "ERROR_TRANSFORM_NOT_SUPPORTED";
        case 0x92:
LAB_0071e1db:
          return "ERROR_CLIPPING_NOT_SUPPORTED";
        case 0x93:
LAB_0071e1e5:
          return "ERROR_INVALID_CMM";
        case 0x94:
LAB_0071e1ef:
          return "ERROR_INVALID_PROFILE";
        case 0x95:
LAB_0071e1f9:
          return "ERROR_TAG_NOT_FOUND";
        case 0x96:
LAB_0071e203:
          return "ERROR_TAG_NOT_PRESENT";
        case 0x97:
LAB_0071e20d:
          return "ERROR_DUPLICATE_TAG";
        case 0x98:
LAB_0071e217:
          return "ERROR_PROFILE_NOT_ASSOCIATED_WITH_DEVICE";
        case 0x99:
LAB_0071e221:
          return "ERROR_PROFILE_NOT_FOUND";
        case 0x9a:
LAB_0071e22b:
          return "ERROR_INVALID_COLORSPACE";
        case 0x9b:
LAB_0071e235:
          return "ERROR_ICM_NOT_ENABLED";
        case 0x9c:
LAB_0071e27c:
          return "ERROR_DELETING_ICM_XFORM";
        case 0x9d:
LAB_0071e272:
          return "ERROR_INVALID_TRANSFORM";
        case 0x9e:
LAB_0071e268:
          return "ERROR_COLORSPACE_MISMATCH";
        case 0x9f:
code_r0x0071e25e:
          return "ERROR_INVALID_COLORINDEX";
        case 0xa0:
LAB_0071e286:
          return "ERROR_CONNECTED_OTHER_PASSWORD";
        case 0xa1:
LAB_0071e2ca:
          return "ERROR_CONNECTED_OTHER_PASSWORD_DEFAULT";
        case 0xa2:
LAB_0071e2c0:
          return "ERROR_BAD_USERNAME";
        }
      }
    }
    else if (param_1 < -0x7ff8de7f) {
      if (param_1 == -0x7ff8de80) {
LAB_0071fd8b:
        return "ERROR_DS_RESERVED_LINK_ID";
      }
      if (param_1 < -0x7ff8dfd3) {
        if (param_1 == -0x7ff8dfd4) {
LAB_0071f18a:
          return "ERROR_DS_UNAVAILABLE_CRIT_EXTENSION";
        }
        if (param_1 < -0x7ff8ec3a) {
          if (param_1 == -0x7ff8ec3b) {
LAB_0071ea62:
            return "ERROR_CLUSTER_NODE_ALREADY_UP";
          }
          if (param_1 < -0x7ff8ef11) {
            if (param_1 == -0x7ff8ef12) {
LAB_0071e704:
              return "ERROR_UNEXPECTED_OMID";
            }
            if (param_1 < -0x7ff8ef8c) {
              if (param_1 == -0x7ff8ef8d) {
LAB_0071e521:
                return "ERROR_WMI_INVALID_REGINFO";
              }
              if (param_1 < -0x7ff8f05f) {
                if (param_1 == -0x7ff8f060) {
LAB_0071e40e:
                  return "ERROR_WINS_INTERNAL";
                }
                if (param_1 < -0x7ff8f441) {
                  if (param_1 == -0x7ff8f442) {
LAB_0071e377:
                    return "ERROR_PRINT_MONITOR_ALREADY_INSTALLED";
                  }
                  if (param_1 < -0x7ff8f446) {
                    if (param_1 == -0x7ff8f447) {
LAB_0071e32d:
                      return "ERROR_PRINTER_DRIVER_IN_USE";
                    }
                    if (param_1 == -0x7ff8f69f) goto LAB_0071e2ac;
                    if (param_1 == -0x7ff8f69e) goto LAB_0071e2d4;
                    if (param_1 == -0x7ff8f69c) goto LAB_0071e337;
                    if (param_1 == -0x7ff8f448) goto LAB_007181be;
                  }
                  else {
                    if (param_1 == -0x7ff8f446) {
LAB_0071e323:
                      return "ERROR_SPOOL_FILE_NOT_FOUND";
                    }
                    if (param_1 == -0x7ff8f445) {
LAB_0071e319:
                      return "ERROR_SPL_NO_STARTDOC";
                    }
                    if (param_1 == -0x7ff8f444) goto LAB_0071e341;
                    if (param_1 == -0x7ff8f443) goto LAB_007181f4;
                  }
                }
                else {
                  switch(param_1) {
                  case -0x7ff8f441:
LAB_0071e36d:
                    return "ERROR_INVALID_PRINT_MONITOR";
                  case -0x7ff8f440:
code_r0x0071e363:
                    return "ERROR_PRINT_MONITOR_IN_USE";
                  case -0x7ff8f43f:
                    goto LAB_0071e381;
                  case -0x7ff8f43e:
                    goto LAB_0071e3c8;
                  case -0x7ff8f43d:
LAB_0071e3be:
                    return "ERROR_SUCCESS_RESTART_REQUIRED";
                  case -0x7ff8f43c:
LAB_0071e3b4:
                    return "ERROR_PRINTER_NOT_FOUND";
                  case -0x7ff8f43b:
code_r0x0071e3aa:
                    return "ERROR_PRINTER_DRIVER_WARNED";
                  case -0x7ff8f43a:
                    goto LAB_0071e3d2;
                  }
                }
              }
              else if (param_1 < -0x7ff8ef95) {
                if (param_1 == -0x7ff8ef96) {
LAB_0071e4a5:
                  return "ERROR_WMI_ITEMID_NOT_FOUND";
                }
                if (param_1 < -0x7ff8f05a) {
                  if (param_1 == -0x7ff8f05b) {
LAB_0071e49b:
                    return "ERROR_REC_NON_EXISTENT";
                  }
                  if (param_1 == -0x7ff8f05f) goto LAB_0071e404;
                  if (param_1 == -0x7ff8f05e) goto LAB_0071e3fa;
                  if (param_1 == -0x7ff8f05d) goto LAB_0071e3f0;
                  if (param_1 == -0x7ff8f05c) goto LAB_0071825d;
                }
                else {
                  if (param_1 == -0x7ff8f05a) {
LAB_0071e491:
                    return "ERROR_RPL_NOT_ALLOWED";
                  }
                  if (param_1 == -0x7ff8effc) {
LAB_0071e487:
                    return "ERROR_DHCP_ADDRESS_CONFLICT";
                  }
                  if (param_1 == -0x7ff8ef98) {
LAB_0071e47d:
                    return "ERROR_WMI_GUID_NOT_FOUND";
                  }
                  if (param_1 == -0x7ff8ef97) {
LAB_0071e473:
                    return "ERROR_WMI_INSTANCE_NOT_FOUND";
                  }
                }
              }
              else {
                switch(param_1) {
                case -0x7ff8ef95:
LAB_0071e4e1:
                  return "ERROR_WMI_TRY_AGAIN";
                case -0x7ff8ef94:
LAB_0071e4d7:
                  return "ERROR_WMI_DP_NOT_FOUND";
                case -0x7ff8ef93:
LAB_0071e4cd:
                  return "ERROR_WMI_UNRESOLVED_INSTANCE_REF";
                case -0x7ff8ef92:
code_r0x0071e4c3:
                  return "ERROR_WMI_ALREADY_ENABLED";
                case -0x7ff8ef91:
                  goto LAB_0071e4eb;
                case -0x7ff8ef90:
LAB_0071e53f:
                  return "ERROR_WMI_SERVER_UNAVAILABLE";
                case -0x7ff8ef8f:
LAB_0071e535:
                  return "ERROR_WMI_DP_FAILED";
                case -0x7ff8ef8e:
LAB_0071e52b:
                  return "ERROR_WMI_INVALID_MOF";
                }
              }
            }
            else {
              switch(param_1) {
              case -0x7ff8ef8c:
code_r0x0071e517:
                return "ERROR_WMI_ALREADY_DISABLED";
              case -0x7ff8ef8b:
LAB_0071e549:
                return "ERROR_WMI_READ_ONLY";
              case -0x7ff8ef8a:
LAB_0071e587:
                return "ERROR_WMI_SET_FAILURE";
              case -0x7ff8ef34:
LAB_0071e57d:
                return "ERROR_INVALID_MEDIA";
              case -0x7ff8ef33:
LAB_0071e573:
                return "ERROR_INVALID_LIBRARY";
              case -0x7ff8ef32:
code_r0x0071e569:
                return "ERROR_INVALID_MEDIA_POOL";
              case -0x7ff8ef31:
LAB_0071e591:
                return "ERROR_DRIVE_MEDIA_MISMATCH";
              case -0x7ff8ef30:
code_r0x0071e5b0:
                return "ERROR_MEDIA_OFFLINE";
              case -0x7ff8ef2f:
code_r0x0071e5ba:
                return "ERROR_LIBRARY_OFFLINE";
              case -0x7ff8ef2e:
code_r0x0071e5c4:
                return "ERROR_EMPTY";
              case -0x7ff8ef2d:
code_r0x0071e5ce:
                return "ERROR_NOT_EMPTY";
              case -0x7ff8ef2c:
code_r0x0071e5d8:
                return "ERROR_MEDIA_UNAVAILABLE";
              case -0x7ff8ef2b:
code_r0x0071e5e2:
                return "ERROR_RESOURCE_DISABLED";
              case -0x7ff8ef2a:
code_r0x0071e5ec:
                return "ERROR_INVALID_CLEANER";
              case -0x7ff8ef29:
code_r0x0071e5f6:
                return "ERROR_UNABLE_TO_CLEAN";
              case -0x7ff8ef28:
code_r0x0071e600:
                return "ERROR_OBJECT_NOT_FOUND";
              case -0x7ff8ef27:
code_r0x0071e60a:
                return "ERROR_DATABASE_FAILURE";
              case -0x7ff8ef26:
code_r0x0071e614:
                return "ERROR_DATABASE_FULL";
              case -0x7ff8ef25:
code_r0x0071e61e:
                return "ERROR_MEDIA_INCOMPATIBLE";
              case -0x7ff8ef24:
code_r0x0071e628:
                return "ERROR_RESOURCE_NOT_PRESENT";
              case -0x7ff8ef23:
code_r0x0071e632:
                return "ERROR_INVALID_OPERATION";
              case -0x7ff8ef22:
code_r0x0071e63c:
                return "ERROR_MEDIA_NOT_AVAILABLE";
              case -0x7ff8ef21:
code_r0x0071e646:
                return "ERROR_DEVICE_NOT_AVAILABLE";
              case -0x7ff8ef20:
code_r0x0071e650:
                return "ERROR_REQUEST_REFUSED";
              case -0x7ff8ef1f:
code_r0x0071e65a:
                return "ERROR_INVALID_DRIVE_OBJECT";
              case -0x7ff8ef1e:
code_r0x0071e664:
                return "ERROR_LIBRARY_FULL";
              case -0x7ff8ef1d:
code_r0x0071e66e:
                return "ERROR_MEDIUM_NOT_ACCESSIBLE";
              case -0x7ff8ef1c:
                goto LAB_0071e678;
              case -0x7ff8ef1b:
code_r0x0071e6aa:
                return "ERROR_UNABLE_TO_INVENTORY_DRIVE";
              case -0x7ff8ef1a:
code_r0x0071e6b4:
                return "ERROR_UNABLE_TO_INVENTORY_SLOT";
              case -0x7ff8ef19:
code_r0x0071e6be:
                return "ERROR_UNABLE_TO_INVENTORY_TRANSPORT";
              case -0x7ff8ef18:
code_r0x0071e6c8:
                return "ERROR_TRANSPORT_FULL";
              case -0x7ff8ef17:
code_r0x0071e6d2:
                return "ERROR_CONTROLLING_IEPORT";
              case -0x7ff8ef16:
code_r0x0071e6dc:
                return "ERROR_UNABLE_TO_EJECT_MOUNTED_MEDIA";
              case -0x7ff8ef15:
code_r0x0071e6e6:
                return "ERROR_CLEANER_SLOT_SET";
              case -0x7ff8ef14:
code_r0x0071e6f0:
                return "ERROR_CLEANER_SLOT_NOT_SET";
              case -0x7ff8ef13:
code_r0x0071e6fa:
                return "ERROR_CLEANER_CARTRIDGE_SPENT";
              }
            }
          }
          else if (param_1 < -0x7ff8eed9) {
            if (param_1 == -0x7ff8eeda) {
LAB_0071e768:
              return "ERROR_NOT_A_REPARSE_POINT";
            }
            switch(param_1) {
            case -0x7ff8ef11:
code_r0x0071e70e:
              return "ERROR_CANT_DELETE_LAST_ITEM";
            case -0x7ff8ef10:
code_r0x0071e718:
              return "ERROR_MESSAGE_EXCEEDS_MAX_SIZE";
            case -0x7ff8ef0f:
code_r0x0071e740:
              return "ERROR_VOLUME_CONTAINS_SYS_FILES";
            case -0x7ff8ef0e:
code_r0x0071e74a:
              return "ERROR_INDIGENOUS_TYPE";
            case -0x7ff8ef0d:
code_r0x0071e754:
              return "ERROR_NO_SUPPORTING_DRIVES";
            case -0x7ff8ef0c:
code_r0x0071e75e:
              return "ERROR_CLEANER_CARTRIDGE_INSTALLED";
            case -0x7ff8ef02:
code_r0x0071e722:
              return "ERROR_FILE_OFFLINE";
            case -0x7ff8ef01:
code_r0x0071e72c:
              return "ERROR_REMOTE_STORAGE_NOT_ACTIVE";
            case -0x7ff8ef00:
code_r0x0071e736:
              return "ERROR_REMOTE_STORAGE_MEDIA_ERROR";
            }
          }
          else if (param_1 < -0x7ff8ec5b) {
            if (param_1 == -0x7ff8ec5c) goto LAB_0071e922;
            if (param_1 < -0x7ff8ec6b) {
              if (param_1 == -0x7ff8ec6c) goto LAB_0071e85a;
              if (param_1 < -0x7ff8ec73) {
                if (param_1 == -0x7ff8ec74) {
LAB_0071e7ff:
                  return "ERROR_RESOURCE_NOT_ONLINE";
                }
                if (param_1 < -0x7ff8ee6b) {
                  if (param_1 == -0x7ff8ee6c) {
LAB_0071e7ab:
                    return "ERROR_VOLUME_NOT_SIS_ENABLED";
                  }
                  if (param_1 == -0x7ff8eed9) goto LAB_0071e7c9;
                  if (param_1 == -0x7ff8eed8) goto LAB_0071e7bf;
                  if (param_1 == -0x7ff8eed7) goto LAB_0071e7b5;
                  if (param_1 == -0x7ff8eed6) goto LAB_00718362;
                }
                else {
                  if (param_1 == -0x7ff8ec77) goto LAB_0071e7d3;
                  if (param_1 == -0x7ff8ec76) goto LAB_0071e809;
                  if (param_1 == -0x7ff8ec75) goto LAB_0071838d;
                }
              }
              else {
                if (param_1 == -0x7ff8ec73) {
LAB_0071e7f5:
                  return "ERROR_HOST_NODE_NOT_AVAILABLE";
                }
                if (param_1 == -0x7ff8ec72) goto LAB_0071e813;
                if (param_1 == -0x7ff8ec71) goto LAB_0071e832;
                if (param_1 == -0x7ff8ec70) goto LAB_0071e83c;
                if (param_1 == -0x7ff8ec6f) goto LAB_0071e846;
                if (param_1 == -0x7ff8ec6e) goto LAB_0071e850;
                if (param_1 == -0x7ff8ec6d) goto code_r0x007183e4;
              }
            }
            else {
              switch(param_1) {
              case -0x7ff8ec6b:
                goto code_r0x0071e864;
              case -0x7ff8ec6a:
                goto code_r0x0071e86e;
              case -0x7ff8ec69:
                goto code_r0x0071e878;
              case -0x7ff8ec68:
                goto code_r0x0071e882;
              case -0x7ff8ec67:
                goto LAB_0071e88c;
              case -0x7ff8ec66:
                goto code_r0x0071e8be;
              case -0x7ff8ec65:
                goto code_r0x0071e8c8;
              case -0x7ff8ec64:
                goto code_r0x0071e8d2;
              case -0x7ff8ec63:
                goto code_r0x0071e8dc;
              case -0x7ff8ec62:
                goto code_r0x0071e8e6;
              case -0x7ff8ec61:
                goto code_r0x0071e8f0;
              case -0x7ff8ec60:
                goto code_r0x0071e8fa;
              case -0x7ff8ec5f:
                goto code_r0x0071e904;
              case -0x7ff8ec5e:
                goto code_r0x0071e90e;
              case -0x7ff8ec5d:
                goto code_r0x0071e918;
              }
            }
          }
          else {
            switch(param_1) {
            case -0x7ff8ec5b:
              goto code_r0x0071e92c;
            case -0x7ff8ec5a:
              goto code_r0x0071e936;
            case -0x7ff8ec59:
              goto code_r0x0071e940;
            case -0x7ff8ec58:
              goto code_r0x0071e94a;
            case -0x7ff8ec57:
              goto code_r0x0071e954;
            case -0x7ff8ec56:
              goto code_r0x0071e95e;
            case -0x7ff8ec55:
              goto code_r0x0071e968;
            case -0x7ff8ec54:
              goto code_r0x0071e972;
            case -0x7ff8ec53:
              goto code_r0x0071e97c;
            case -0x7ff8ec52:
              goto code_r0x0071e986;
            case -0x7ff8ec51:
              goto code_r0x0071e990;
            case -0x7ff8ec50:
              goto code_r0x0071e99a;
            case -0x7ff8ec4f:
              goto code_r0x0071e9a4;
            case -0x7ff8ec4e:
              goto code_r0x0071e9ae;
            case -0x7ff8ec4d:
              goto code_r0x0071e9b8;
            case -0x7ff8ec4c:
              goto code_r0x0071e9c2;
            case -0x7ff8ec4b:
              goto code_r0x0071e9cc;
            case -0x7ff8ec4a:
              goto code_r0x0071e9d6;
            case -0x7ff8ec49:
              goto code_r0x0071e9e0;
            case -0x7ff8ec48:
              goto code_r0x0071e9ea;
            case -0x7ff8ec47:
              goto code_r0x0071e9f4;
            case -0x7ff8ec46:
              goto code_r0x0071e9fe;
            case -0x7ff8ec45:
              goto code_r0x0071ea08;
            case -0x7ff8ec44:
              goto code_r0x0071ea12;
            case -0x7ff8ec43:
              goto code_r0x0071ea1c;
            case -0x7ff8ec42:
              goto code_r0x0071ea26;
            case -0x7ff8ec40:
              goto code_r0x0071ea30;
            case -0x7ff8ec3f:
              goto code_r0x0071ea3a;
            case -0x7ff8ec3e:
              goto code_r0x0071ea44;
            case -0x7ff8ec3d:
              goto code_r0x0071ea4e;
            case -0x7ff8ec3c:
              goto code_r0x0071ea58;
            }
          }
        }
        else if (param_1 < -0x7ff8e8fd) {
          if (param_1 == -0x7ff8e8fe) goto LAB_0071eb84;
          switch(param_1) {
          case -0x7ff8ec3a:
            goto code_r0x0071ea6c;
          case -0x7ff8ec39:
            goto code_r0x0071ea76;
          case -0x7ff8ec38:
            goto code_r0x0071ea80;
          case -0x7ff8ec37:
            goto code_r0x0071ea8a;
          case -0x7ff8ec36:
            goto code_r0x0071ea94;
          case -0x7ff8ec35:
            goto code_r0x0071ea9e;
          case -0x7ff8ec34:
            goto code_r0x0071eaa8;
          case -0x7ff8ec33:
            goto code_r0x0071eab2;
          case -0x7ff8ec32:
            goto code_r0x0071eabc;
          case -0x7ff8ec31:
            goto code_r0x0071eac6;
          case -0x7ff8ec30:
            goto code_r0x0071ead0;
          case -0x7ff8ec2f:
            goto code_r0x0071eada;
          case -0x7ff8ec2e:
            goto code_r0x0071eae4;
          case -0x7ff8ec2d:
            goto code_r0x0071eaee;
          case -0x7ff8ec2c:
            goto code_r0x0071eaf8;
          case -0x7ff8ec2b:
            goto code_r0x0071eb02;
          case -0x7ff8ec2a:
            goto code_r0x0071eb0c;
          case -0x7ff8ec29:
            goto code_r0x0071eb16;
          case -0x7ff8ec28:
            goto code_r0x0071eb20;
          case -0x7ff8ec27:
            goto code_r0x0071eb2a;
          case -0x7ff8ec26:
            goto code_r0x0071eb34;
          case -0x7ff8ec25:
            goto code_r0x0071eb3e;
          case -0x7ff8ec24:
            goto code_r0x0071eb48;
          case -0x7ff8ec23:
            goto code_r0x0071eb52;
          case -0x7ff8ec22:
            goto code_r0x0071eb5c;
          case -0x7ff8ec21:
            goto code_r0x0071eb66;
          case -0x7ff8ec20:
            goto code_r0x0071eb70;
          case -0x7ff8ec1f:
            goto code_r0x0071eb7a;
          }
        }
        else if (param_1 < -0x7ff8e88f) {
          if (param_1 == -0x7ff8e890) goto LAB_0071ec16;
          switch(param_1) {
          case -0x7ff8e8fd:
            goto code_r0x0071ebb2;
          case -0x7ff8e8fc:
            goto code_r0x0071ebbc;
          case -0x7ff8e8fb:
            goto code_r0x0071ebc6;
          case -0x7ff8e8fa:
            goto code_r0x0071ebd0;
          case -0x7ff8e8f9:
            goto code_r0x0071ebda;
          case -0x7ff8e8f8:
            goto code_r0x0071ebe4;
          case -0x7ff8e8f7:
            goto code_r0x0071ebee;
          case -0x7ff8e8f6:
            goto code_r0x0071ebf8;
          case -0x7ff8e8f5:
            goto code_r0x0071ec02;
          case -0x7ff8e8f4:
            goto code_r0x0071ec0c;
          }
        }
        else if (param_1 < -0x7ff8e819) {
          if (param_1 == -0x7ff8e81a) goto LAB_0071ece8;
          switch(param_1) {
          case -0x7ff8e88f:
            goto code_r0x0071ec48;
          case -0x7ff8e88e:
            goto code_r0x0071ec52;
          case -0x7ff8e88d:
            goto code_r0x0071ec5c;
          case -0x7ff8e88c:
            goto code_r0x0071ec66;
          case -0x7ff8e88b:
            goto code_r0x0071ec70;
          case -0x7ff8e88a:
            goto code_r0x0071ec7a;
          case -0x7ff8e889:
            goto code_r0x0071ec84;
          case -0x7ff8e888:
            goto code_r0x0071ec8e;
          case -0x7ff8e887:
            goto code_r0x0071ec98;
          case -0x7ff8e886:
            goto code_r0x0071eca2;
          case -0x7ff8e885:
            goto code_r0x0071ecac;
          case -0x7ff8e884:
            goto code_r0x0071ecb6;
          case -0x7ff8e883:
            goto code_r0x0071ecc0;
          case -0x7ff8e882:
            goto code_r0x0071ecca;
          case -0x7ff8e881:
            goto code_r0x0071ecd4;
          case -0x7ff8e880:
            goto code_r0x0071ecde;
          }
        }
        else if (param_1 < -0x7ff8e0b8) {
          if (param_1 == -0x7ff8e0b9) {
LAB_0071ef9e:
            return "FRS_ERR_INSUFFICIENT_PRIV";
          }
          if (param_1 < -0x7ff8e482) {
            if (param_1 == -0x7ff8e483) {
LAB_0071ee76:
              return "ERROR_CTX_LOGON_DISABLED";
            }
            if (param_1 < -0x7ff8e49c) {
              if (param_1 == -0x7ff8e49d) {
LAB_0071ede2:
                return "ERROR_CTX_MODEM_RESPONSE_ERROR";
              }
              if (param_1 < -0x7ff8e4a2) {
                if (param_1 == -0x7ff8e4a3) {
LAB_0071ed74:
                  return "ERROR_CTX_CANNOT_MAKE_EVENTLOG_ENTRY";
                }
                if (param_1 == -0x7ff8e7c8) {
LAB_0071ed9c:
                  return "SCHED_E_SERVICE_NOT_LOCALSYSTEM";
                }
                if (param_1 == -0x7ff8e4a7) {
LAB_0071ed92:
                  return "ERROR_CTX_WINSTATION_NAME_INVALID";
                }
                if (param_1 == -0x7ff8e4a6) {
LAB_0071ed88:
                  return "ERROR_CTX_INVALID_PD";
                }
                if (param_1 == -0x7ff8e4a5) {
LAB_0071ed7e:
                  return "ERROR_CTX_PD_NOT_FOUND";
                }
                if (param_1 == -0x7ff8e4a4) {
LAB_00718501:
                  return "ERROR_CTX_WD_NOT_FOUND";
                }
              }
              else {
                if (param_1 == -0x7ff8e4a2) {
LAB_0071ed6a:
                  return "ERROR_CTX_SERVICE_NAME_COLLISION";
                }
                if (param_1 == -0x7ff8e4a1) goto LAB_0071eda6;
                if (param_1 == -0x7ff8e4a0) goto LAB_0071edf6;
                if (param_1 == -0x7ff8e49f) goto LAB_0071edec;
                if (param_1 == -0x7ff8e49e) goto LAB_00718542;
              }
            }
            else {
              switch(param_1) {
              case -0x7ff8e49c:
LAB_0071edd8:
                return "ERROR_CTX_MODEM_RESPONSE_TIMEOUT";
              case -0x7ff8e49b:
code_r0x0071edce:
                return "ERROR_CTX_MODEM_RESPONSE_NO_CARRIER";
              case -0x7ff8e49a:
LAB_0071ee00:
                return "ERROR_CTX_MODEM_RESPONSE_NO_DIALTONE";
              case -0x7ff8e499:
code_r0x0071ee26:
                return "ERROR_CTX_MODEM_RESPONSE_BUSY";
              case -0x7ff8e498:
code_r0x0071ee30:
                return "ERROR_CTX_MODEM_RESPONSE_VOICE";
              case -0x7ff8e497:
code_r0x0071ee3a:
                return "ERROR_CTX_TD_ERROR";
              case -0x7ff8e492:
code_r0x0071ee44:
                return "ERROR_CTX_WINSTATION_NOT_FOUND";
              case -0x7ff8e491:
code_r0x0071ee4e:
                return "ERROR_CTX_WINSTATION_ALREADY_EXISTS";
              case -0x7ff8e490:
code_r0x0071ee58:
                return "ERROR_CTX_WINSTATION_BUSY";
              case -0x7ff8e48f:
code_r0x0071ee62:
                return "ERROR_CTX_BAD_VIDEO_MODE";
              case -0x7ff8e485:
code_r0x0071ee6c:
                return "ERROR_CTX_GRAPHICS_INVALID";
              }
            }
          }
          else if (param_1 < -0x7ff8e0be) {
            if (param_1 == -0x7ff8e0bf) {
LAB_0071ef44:
              return "FRS_ERR_INVALID_API_SEQUENCE";
            }
            switch(param_1) {
            case -0x7ff8e482:
code_r0x0071ee80:
              return "ERROR_CTX_NOT_CONSOLE";
            case -0x7ff8e480:
code_r0x0071ee8a:
              return "ERROR_CTX_CLIENT_QUERY_TIMEOUT";
            case -0x7ff8e47f:
code_r0x0071ee94:
              return "ERROR_CTX_CONSOLE_DISCONNECT";
            case -0x7ff8e47e:
code_r0x0071ee9e:
              return "ERROR_CTX_CONSOLE_CONNECT";
            case -0x7ff8e47c:
code_r0x0071eea8:
              return "ERROR_CTX_SHADOW_DENIED";
            case -0x7ff8e47b:
              goto LAB_0071eeb2;
            case -0x7ff8e477:
code_r0x0071eee0:
              return "ERROR_CTX_INVALID_WD";
            case -0x7ff8e476:
code_r0x0071eeea:
              return "ERROR_CTX_SHADOW_INVALID";
            case -0x7ff8e475:
code_r0x0071eef4:
              return "ERROR_CTX_SHADOW_DISABLED";
            case -0x7ff8e474:
code_r0x0071eefe:
              return "ERROR_CTX_CLIENT_LICENSE_IN_USE";
            case -0x7ff8e473:
code_r0x0071ef08:
              return "ERROR_CTX_CLIENT_LICENSE_NOT_SET";
            case -0x7ff8e472:
code_r0x0071ef12:
              return "ERROR_CTX_LICENSE_NOT_AVAILABLE";
            case -0x7ff8e471:
code_r0x0071ef1c:
              return "ERROR_CTX_LICENSE_CLIENT_INVALID";
            case -0x7ff8e470:
code_r0x0071ef26:
              return "ERROR_CTX_LICENSE_EXPIRED";
            case -0x7ff8e46f:
code_r0x0071ef30:
              return "ERROR_CTX_SHADOW_NOT_RUNNING";
            case -0x7ff8e46e:
code_r0x0071ef3a:
              return "ERROR_CTX_SHADOW_ENDED_BY_MODE_CHANGE";
            }
          }
          else {
            if (param_1 == -0x7ff8e0be) {
LAB_0071ef76:
              return "FRS_ERR_STARTING_SERVICE";
            }
            if (param_1 == -0x7ff8e0bd) {
LAB_0071ef80:
              return "FRS_ERR_STOPPING_SERVICE";
            }
            if (param_1 == -0x7ff8e0bc) {
LAB_0071ef8a:
              return "FRS_ERR_INTERNAL_API";
            }
            if (param_1 == -0x7ff8e0bb) goto LAB_0071ef94;
            if (param_1 == -0x7ff8e0ba) goto code_r0x007185c3;
          }
        }
        else if (param_1 < -0x7ff8dff7) {
          if (param_1 == -0x7ff8dff8) {
LAB_0071f00c:
            return "ERROR_DS_NOT_INSTALLED";
          }
          switch(param_1) {
          case -0x7ff8e0b8:
code_r0x0071efa8:
            return "FRS_ERR_AUTHENTICATION";
          case -0x7ff8e0b7:
code_r0x0071efb2:
            return "FRS_ERR_PARENT_INSUFFICIENT_PRIV";
          case -0x7ff8e0b6:
code_r0x0071efbc:
            return "FRS_ERR_PARENT_AUTHENTICATION";
          case -0x7ff8e0b5:
code_r0x0071efc6:
            return "FRS_ERR_CHILD_TO_PARENT_COMM";
          case -0x7ff8e0b4:
code_r0x0071efd0:
            return "FRS_ERR_PARENT_TO_CHILD_COMM";
          case -0x7ff8e0b3:
code_r0x0071efda:
            return "FRS_ERR_SYSVOL_POPULATE";
          case -0x7ff8e0b2:
code_r0x0071efe4:
            return "FRS_ERR_SYSVOL_POPULATE_TIMEOUT";
          case -0x7ff8e0b1:
code_r0x0071efee:
            return "FRS_ERR_SYSVOL_IS_BUSY";
          case -0x7ff8e0b0:
code_r0x0071eff8:
            return "FRS_ERR_SYSVOL_DEMOTE";
          case -0x7ff8e0af:
code_r0x0071f002:
            return "FRS_ERR_INVALID_SERVICE_PARAMETER";
          }
        }
        else {
          switch(param_1) {
          case -0x7ff8dff7:
code_r0x0071f021:
            return "ERROR_DS_MEMBERSHIP_EVALUATED_LOCALLY";
          case -0x7ff8dff6:
            goto LAB_0071f02b;
          case -0x7ff8dff5:
            goto code_r0x0071f04a;
          case -0x7ff8dff4:
            goto code_r0x0071f054;
          case -0x7ff8dff3:
            goto code_r0x0071f05e;
          case -0x7ff8dff2:
            goto code_r0x0071f068;
          case -0x7ff8dff1:
            goto code_r0x0071f072;
          case -0x7ff8dff0:
            goto code_r0x0071f07c;
          case -0x7ff8dfef:
            goto code_r0x0071f086;
          case -0x7ff8dfee:
            goto code_r0x0071f090;
          case -0x7ff8dfed:
            goto code_r0x0071f09a;
          case -0x7ff8dfec:
            goto code_r0x0071f0a4;
          case -0x7ff8dfeb:
            goto code_r0x0071f0ae;
          case -0x7ff8dfea:
            goto code_r0x0071f0b8;
          case -0x7ff8dfe9:
            goto code_r0x0071f0c2;
          case -0x7ff8dfe8:
            goto code_r0x0071f0cc;
          case -0x7ff8dfe7:
            goto code_r0x0071f0d6;
          case -0x7ff8dfe6:
            goto code_r0x0071f0e0;
          case -0x7ff8dfe5:
            goto code_r0x0071f0ea;
          case -0x7ff8dfe4:
            goto code_r0x0071f0f4;
          case -0x7ff8dfe3:
            goto code_r0x0071f0fe;
          case -0x7ff8dfe2:
            goto code_r0x0071f108;
          case -0x7ff8dfe0:
            goto code_r0x0071f112;
          case -0x7ff8dfdf:
            goto code_r0x0071f11c;
          case -0x7ff8dfde:
            goto code_r0x0071f126;
          case -0x7ff8dfdd:
            goto code_r0x0071f130;
          case -0x7ff8dfdc:
            goto code_r0x0071f13a;
          case -0x7ff8dfdb:
            goto code_r0x0071f144;
          case -0x7ff8dfda:
            goto code_r0x0071f14e;
          case -0x7ff8dfd9:
            goto code_r0x0071f158;
          case -0x7ff8dfd8:
            goto code_r0x0071f162;
          case -0x7ff8dfd7:
            goto code_r0x0071f16c;
          case -0x7ff8dfd6:
            goto code_r0x0071f176;
          case -0x7ff8dfd5:
            goto code_r0x0071f180;
          }
        }
      }
      else {
        switch(param_1) {
        case -0x7ff8dfd3:
code_r0x0071f194:
          return "ERROR_DS_CONFIDENTIALITY_REQUIRED";
        case -0x7ff8dfd2:
code_r0x0071f19e:
          return "ERROR_DS_INAPPROPRIATE_MATCHING";
        case -0x7ff8dfd1:
code_r0x0071f1a8:
          return "ERROR_DS_CONSTRAINT_VIOLATION";
        case -0x7ff8dfd0:
code_r0x0071f1b2:
          return "ERROR_DS_NO_SUCH_OBJECT";
        case -0x7ff8dfcf:
code_r0x0071f1bc:
          return "ERROR_DS_ALIAS_PROBLEM";
        case -0x7ff8dfce:
code_r0x0071f1c6:
          return "ERROR_DS_INVALID_DN_SYNTAX";
        case -0x7ff8dfcd:
code_r0x0071f1d0:
          return "ERROR_DS_IS_LEAF";
        case -0x7ff8dfcc:
code_r0x0071f1da:
          return "ERROR_DS_ALIAS_DEREF_PROBLEM";
        case -0x7ff8dfcb:
code_r0x0071f1e4:
          return "ERROR_DS_UNWILLING_TO_PERFORM";
        case -0x7ff8dfca:
code_r0x0071f1ee:
          return "ERROR_DS_LOOP_DETECT";
        case -0x7ff8dfc9:
code_r0x0071f1f8:
          return "ERROR_DS_NAMING_VIOLATION";
        case -0x7ff8dfc8:
code_r0x0071f202:
          return "ERROR_DS_OBJECT_RESULTS_TOO_LARGE";
        case -0x7ff8dfc7:
code_r0x0071f20c:
          return "ERROR_DS_AFFECTS_MULTIPLE_DSAS";
        case -0x7ff8dfc6:
code_r0x0071f216:
          return "ERROR_DS_SERVER_DOWN";
        case -0x7ff8dfc5:
code_r0x0071f220:
          return "ERROR_DS_LOCAL_ERROR";
        case -0x7ff8dfc4:
code_r0x0071f22a:
          return "ERROR_DS_ENCODING_ERROR";
        case -0x7ff8dfc3:
code_r0x0071f234:
          return "ERROR_DS_DECODING_ERROR";
        case -0x7ff8dfc2:
code_r0x0071f23e:
          return "ERROR_DS_FILTER_UNKNOWN";
        case -0x7ff8dfc1:
code_r0x0071f248:
          return "ERROR_DS_PARAM_ERROR";
        case -0x7ff8dfc0:
code_r0x0071f252:
          return "ERROR_DS_NOT_SUPPORTED";
        case -0x7ff8dfbf:
code_r0x0071f25c:
          return "ERROR_DS_NO_RESULTS_RETURNED";
        case -0x7ff8dfbe:
code_r0x0071f266:
          return "ERROR_DS_CONTROL_NOT_FOUND";
        case -0x7ff8dfbd:
code_r0x0071f270:
          return "ERROR_DS_CLIENT_LOOP";
        case -0x7ff8dfbc:
code_r0x0071f27a:
          return "ERROR_DS_REFERRAL_LIMIT_EXCEEDED";
        case -0x7ff8dfbb:
code_r0x0071f284:
          return "ERROR_DS_SORT_CONTROL_MISSING";
        case -0x7ff8dfba:
code_r0x0071f28e:
          return "ERROR_DS_OFFSET_RANGE_ERROR";
        case -0x7ff8df93:
LAB_0071f298:
          return "ERROR_DS_ROOT_MUST_BE_NC";
        case -0x7ff8df92:
code_r0x0071f2b7:
          return "ERROR_DS_ADD_REPLICA_INHIBITED";
        case -0x7ff8df91:
code_r0x0071f2c1:
          return "ERROR_DS_ATT_NOT_DEF_IN_SCHEMA";
        case -0x7ff8df90:
code_r0x0071f2cb:
          return "ERROR_DS_MAX_OBJ_SIZE_EXCEEDED";
        case -0x7ff8df8f:
code_r0x0071f2d5:
          return "ERROR_DS_OBJ_STRING_NAME_EXISTS";
        case -0x7ff8df8e:
code_r0x0071f2df:
          return "ERROR_DS_NO_RDN_DEFINED_IN_SCHEMA";
        case -0x7ff8df8d:
code_r0x0071f2e9:
          return "ERROR_DS_RDN_DOESNT_MATCH_SCHEMA";
        case -0x7ff8df8c:
code_r0x0071f2f3:
          return "ERROR_DS_NO_REQUESTED_ATTS_FOUND";
        case -0x7ff8df8b:
code_r0x0071f2fd:
          return "ERROR_DS_USER_BUFFER_TO_SMALL";
        case -0x7ff8df8a:
code_r0x0071f307:
          return "ERROR_DS_ATT_IS_NOT_ON_OBJ";
        case -0x7ff8df89:
code_r0x0071f311:
          return "ERROR_DS_ILLEGAL_MOD_OPERATION";
        case -0x7ff8df88:
code_r0x0071f31b:
          return "ERROR_DS_OBJ_TOO_LARGE";
        case -0x7ff8df87:
code_r0x0071f325:
          return "ERROR_DS_BAD_INSTANCE_TYPE";
        case -0x7ff8df86:
code_r0x0071f32f:
          return "ERROR_DS_MASTERDSA_REQUIRED";
        case -0x7ff8df85:
code_r0x0071f339:
          return "ERROR_DS_OBJECT_CLASS_REQUIRED";
        case -0x7ff8df84:
code_r0x0071f343:
          return "ERROR_DS_MISSING_REQUIRED_ATT";
        case -0x7ff8df83:
code_r0x0071f34d:
          return "ERROR_DS_ATT_NOT_DEF_FOR_CLASS";
        case -0x7ff8df82:
code_r0x0071f357:
          return "ERROR_DS_ATT_ALREADY_EXISTS";
        case -0x7ff8df80:
code_r0x0071f361:
          return "ERROR_DS_CANT_ADD_ATT_VALUES";
        case -0x7ff8df7f:
code_r0x0071f36b:
          return "ERROR_DS_SINGLE_VALUE_CONSTRAINT";
        case -0x7ff8df7e:
code_r0x0071f375:
          return "ERROR_DS_RANGE_CONSTRAINT";
        case -0x7ff8df7d:
code_r0x0071f37f:
          return "ERROR_DS_ATT_VAL_ALREADY_EXISTS";
        case -0x7ff8df7c:
code_r0x0071f389:
          return "ERROR_DS_CANT_REM_MISSING_ATT";
        case -0x7ff8df7b:
code_r0x0071f393:
          return "ERROR_DS_CANT_REM_MISSING_ATT_VAL";
        case -0x7ff8df7a:
code_r0x0071f39d:
          return "ERROR_DS_ROOT_CANT_BE_SUBREF";
        case -0x7ff8df79:
code_r0x0071f3a7:
          return "ERROR_DS_NO_CHAINING";
        case -0x7ff8df78:
code_r0x0071f3b1:
          return "ERROR_DS_NO_CHAINED_EVAL";
        case -0x7ff8df77:
code_r0x0071f3bb:
          return "ERROR_DS_NO_PARENT_OBJECT";
        case -0x7ff8df76:
code_r0x0071f3c5:
          return "ERROR_DS_PARENT_IS_AN_ALIAS";
        case -0x7ff8df75:
code_r0x0071f3cf:
          return "ERROR_DS_CANT_MIX_MASTER_AND_REPS";
        case -0x7ff8df74:
code_r0x0071f3d9:
          return "ERROR_DS_CHILDREN_EXIST";
        case -0x7ff8df73:
code_r0x0071f3e3:
          return "ERROR_DS_OBJ_NOT_FOUND";
        case -0x7ff8df72:
code_r0x0071f3ed:
          return "ERROR_DS_ALIASED_OBJ_MISSING";
        case -0x7ff8df71:
code_r0x0071f3f7:
          return "ERROR_DS_BAD_NAME_SYNTAX";
        case -0x7ff8df70:
code_r0x0071f401:
          return "ERROR_DS_ALIAS_POINTS_TO_ALIAS";
        case -0x7ff8df6f:
code_r0x0071f40b:
          return "ERROR_DS_CANT_DEREF_ALIAS";
        case -0x7ff8df6e:
code_r0x0071f415:
          return "ERROR_DS_OUT_OF_SCOPE";
        case -0x7ff8df6d:
code_r0x0071f753:
          return "ERROR_DS_OBJECT_BEING_REMOVED";
        case -0x7ff8df6c:
code_r0x0071f41f:
          return "ERROR_DS_CANT_DELETE_DSA_OBJ";
        case -0x7ff8df6b:
code_r0x0071f429:
          return "ERROR_DS_GENERIC_ERROR";
        case -0x7ff8df6a:
code_r0x0071f433:
          return "ERROR_DS_DSA_MUST_BE_INT_MASTER";
        case -0x7ff8df69:
code_r0x0071f43d:
          return "ERROR_DS_CLASS_NOT_DSA";
        case -0x7ff8df68:
code_r0x0071f447:
          return "ERROR_DS_INSUFF_ACCESS_RIGHTS";
        case -0x7ff8df67:
code_r0x0071f451:
          return "ERROR_DS_ILLEGAL_SUPERIOR";
        case -0x7ff8df66:
code_r0x0071f45b:
          return "ERROR_DS_ATTRIBUTE_OWNED_BY_SAM";
        case -0x7ff8df65:
code_r0x0071f465:
          return "ERROR_DS_NAME_TOO_MANY_PARTS";
        case -0x7ff8df64:
code_r0x0071f46f:
          return "ERROR_DS_NAME_TOO_LONG";
        case -0x7ff8df63:
code_r0x0071f479:
          return "ERROR_DS_NAME_VALUE_TOO_LONG";
        case -0x7ff8df62:
code_r0x0071f483:
          return "ERROR_DS_NAME_UNPARSEABLE";
        case -0x7ff8df61:
code_r0x0071f48d:
          return "ERROR_DS_NAME_TYPE_UNKNOWN";
        case -0x7ff8df60:
code_r0x0071f497:
          return "ERROR_DS_NOT_AN_OBJECT";
        case -0x7ff8df5f:
code_r0x0071f4a1:
          return "ERROR_DS_SEC_DESC_TOO_SHORT";
        case -0x7ff8df5e:
code_r0x0071f4ab:
          return "ERROR_DS_SEC_DESC_INVALID";
        case -0x7ff8df5d:
code_r0x0071f4b5:
          return "ERROR_DS_NO_DELETED_NAME";
        case -0x7ff8df5c:
code_r0x0071f4bf:
          return "ERROR_DS_SUBREF_MUST_HAVE_PARENT";
        case -0x7ff8df5b:
code_r0x0071f4c9:
          return "ERROR_DS_NCNAME_MUST_BE_NC";
        case -0x7ff8df5a:
code_r0x0071f4d3:
          return "ERROR_DS_CANT_ADD_SYSTEM_ONLY";
        case -0x7ff8df59:
code_r0x0071f4dd:
          return "ERROR_DS_CLASS_MUST_BE_CONCRETE";
        case -0x7ff8df58:
code_r0x0071f4e7:
          return "ERROR_DS_INVALID_DMD";
        case -0x7ff8df57:
code_r0x0071f4f1:
          return "ERROR_DS_OBJ_GUID_EXISTS";
        case -0x7ff8df56:
code_r0x0071f4fb:
          return "ERROR_DS_NOT_ON_BACKLINK";
        case -0x7ff8df55:
code_r0x0071f505:
          return "ERROR_DS_NO_CROSSREF_FOR_NC";
        case -0x7ff8df54:
code_r0x0071f50f:
          return "ERROR_DS_SHUTTING_DOWN";
        case -0x7ff8df53:
code_r0x0071f519:
          return "ERROR_DS_UNKNOWN_OPERATION";
        case -0x7ff8df52:
code_r0x0071f523:
          return "ERROR_DS_INVALID_ROLE_OWNER";
        case -0x7ff8df51:
code_r0x0071f52d:
          return "ERROR_DS_COULDNT_CONTACT_FSMO";
        case -0x7ff8df50:
code_r0x0071f537:
          return "ERROR_DS_CROSS_NC_DN_RENAME";
        case -0x7ff8df4f:
code_r0x0071f541:
          return "ERROR_DS_CANT_MOD_SYSTEM_ONLY";
        case -0x7ff8df4e:
code_r0x0071f54b:
          return "ERROR_DS_REPLICATOR_ONLY";
        case -0x7ff8df4d:
code_r0x0071f555:
          return "ERROR_DS_OBJ_CLASS_NOT_DEFINED";
        case -0x7ff8df4c:
code_r0x0071f55f:
          return "ERROR_DS_OBJ_CLASS_NOT_SUBCLASS";
        case -0x7ff8df4b:
code_r0x0071f569:
          return "ERROR_DS_NAME_REFERENCE_INVALID";
        case -0x7ff8df4a:
code_r0x0071f573:
          return "ERROR_DS_CROSS_REF_EXISTS";
        case -0x7ff8df49:
code_r0x0071f57d:
          return "ERROR_DS_CANT_DEL_MASTER_CROSSREF";
        case -0x7ff8df48:
code_r0x0071f587:
          return "ERROR_DS_SUBTREE_NOTIFY_NOT_NC_HEAD";
        case -0x7ff8df47:
code_r0x0071f591:
          return "ERROR_DS_NOTIFY_FILTER_TOO_COMPLEX";
        case -0x7ff8df46:
code_r0x0071f59b:
          return "ERROR_DS_DUP_RDN";
        case -0x7ff8df45:
code_r0x0071f5a5:
          return "ERROR_DS_DUP_OID";
        case -0x7ff8df44:
code_r0x0071f5af:
          return "ERROR_DS_DUP_MAPI_ID";
        case -0x7ff8df43:
code_r0x0071f5b9:
          return "ERROR_DS_DUP_SCHEMA_ID_GUID";
        case -0x7ff8df42:
code_r0x0071f5c3:
          return "ERROR_DS_DUP_LDAP_DISPLAY_NAME";
        case -0x7ff8df41:
code_r0x0071f5cd:
          return "ERROR_DS_SEMANTIC_ATT_TEST";
        case -0x7ff8df40:
code_r0x0071f5d7:
          return "ERROR_DS_SYNTAX_MISMATCH";
        case -0x7ff8df3f:
code_r0x0071f5e1:
          return "ERROR_DS_EXISTS_IN_MUST_HAVE";
        case -0x7ff8df3e:
code_r0x0071f5eb:
          return "ERROR_DS_EXISTS_IN_MAY_HAVE";
        case -0x7ff8df3d:
code_r0x0071f5f5:
          return "ERROR_DS_NONEXISTENT_MAY_HAVE";
        case -0x7ff8df3c:
code_r0x0071f5ff:
          return "ERROR_DS_NONEXISTENT_MUST_HAVE";
        case -0x7ff8df3b:
code_r0x0071f609:
          return "ERROR_DS_AUX_CLS_TEST_FAIL";
        case -0x7ff8df3a:
code_r0x0071f613:
          return "ERROR_DS_NONEXISTENT_POSS_SUP";
        case -0x7ff8df39:
code_r0x0071f61d:
          return "ERROR_DS_SUB_CLS_TEST_FAIL";
        case -0x7ff8df38:
code_r0x0071f627:
          return "ERROR_DS_BAD_RDN_ATT_ID_SYNTAX";
        case -0x7ff8df37:
code_r0x0071f631:
          return "ERROR_DS_EXISTS_IN_AUX_CLS";
        case -0x7ff8df36:
code_r0x0071f63b:
          return "ERROR_DS_EXISTS_IN_SUB_CLS";
        case -0x7ff8df35:
code_r0x0071f645:
          return "ERROR_DS_EXISTS_IN_POSS_SUP";
        case -0x7ff8df34:
code_r0x0071f64f:
          return "ERROR_DS_RECALCSCHEMA_FAILED";
        case -0x7ff8df33:
code_r0x0071f659:
          return "ERROR_DS_TREE_DELETE_NOT_FINISHED";
        case -0x7ff8df32:
code_r0x0071f663:
          return "ERROR_DS_CANT_DELETE";
        case -0x7ff8df31:
code_r0x0071f66d:
          return "ERROR_DS_ATT_SCHEMA_REQ_ID";
        case -0x7ff8df30:
code_r0x0071f677:
          return "ERROR_DS_BAD_ATT_SCHEMA_SYNTAX";
        case -0x7ff8df2f:
code_r0x0071f681:
          return "ERROR_DS_CANT_CACHE_ATT";
        case -0x7ff8df2e:
code_r0x0071f68b:
          return "ERROR_DS_CANT_CACHE_CLASS";
        case -0x7ff8df2d:
code_r0x0071f695:
          return "ERROR_DS_CANT_REMOVE_ATT_CACHE";
        case -0x7ff8df2c:
code_r0x0071f69f:
          return "ERROR_DS_CANT_REMOVE_CLASS_CACHE";
        case -0x7ff8df2b:
code_r0x0071f6a9:
          return "ERROR_DS_CANT_RETRIEVE_DN";
        case -0x7ff8df2a:
code_r0x0071f6b3:
          return "ERROR_DS_MISSING_SUPREF";
        case -0x7ff8df29:
code_r0x0071f6bd:
          return "ERROR_DS_CANT_RETRIEVE_INSTANCE";
        case -0x7ff8df28:
code_r0x0071f6c7:
          return "ERROR_DS_CODE_INCONSISTENCY";
        case -0x7ff8df27:
code_r0x0071f6d1:
          return "ERROR_DS_DATABASE_ERROR";
        case -0x7ff8df26:
code_r0x0071f6db:
          return "ERROR_DS_GOVERNSID_MISSING";
        case -0x7ff8df25:
code_r0x0071f6e5:
          return "ERROR_DS_MISSING_EXPECTED_ATT";
        case -0x7ff8df24:
code_r0x0071f6ef:
          return "ERROR_DS_NCNAME_MISSING_CR_REF";
        case -0x7ff8df23:
code_r0x0071f6f9:
          return "ERROR_DS_SECURITY_CHECKING_ERROR";
        case -0x7ff8df22:
code_r0x0071f703:
          return "ERROR_DS_SCHEMA_NOT_LOADED";
        case -0x7ff8df21:
code_r0x0071f70d:
          return "ERROR_DS_SCHEMA_ALLOC_FAILED";
        case -0x7ff8df20:
code_r0x0071f717:
          return "ERROR_DS_ATT_SCHEMA_REQ_SYNTAX";
        case -0x7ff8df1f:
code_r0x0071f721:
          return "ERROR_DS_GCVERIFY_ERROR";
        case -0x7ff8df1e:
code_r0x0071f72b:
          return "ERROR_DS_DRA_SCHEMA_MISMATCH";
        case -0x7ff8df1d:
code_r0x0071f735:
          return "ERROR_DS_CANT_FIND_DSA_OBJ";
        case -0x7ff8df1c:
code_r0x0071f73f:
          return "ERROR_DS_CANT_FIND_EXPECTED_NC";
        case -0x7ff8df1b:
code_r0x0071f749:
          return "ERROR_DS_CANT_FIND_NC_IN_CACHE";
        case -0x7ff8df1a:
          goto LAB_0071f75d;
        case -0x7ff8df19:
code_r0x0071f791:
          return "ERROR_DS_SECURITY_ILLEGAL_MODIFY";
        case -0x7ff8df18:
code_r0x0071f79b:
          return "ERROR_DS_CANT_REPLACE_HIDDEN_REC";
        case -0x7ff8df17:
code_r0x0071f7a5:
          return "ERROR_DS_BAD_HIERARCHY_FILE";
        case -0x7ff8df16:
code_r0x0071f7af:
          return "ERROR_DS_BUILD_HIERARCHY_TABLE_FAILED";
        case -0x7ff8df15:
code_r0x0071f7b9:
          return "ERROR_DS_CONFIG_PARAM_MISSING";
        case -0x7ff8df14:
code_r0x0071f7c3:
          return "ERROR_DS_COUNTING_AB_INDICES_FAILED";
        case -0x7ff8df13:
code_r0x0071f7cd:
          return "ERROR_DS_HIERARCHY_TABLE_MALLOC_FAILED";
        case -0x7ff8df12:
code_r0x0071f7d7:
          return "ERROR_DS_INTERNAL_FAILURE";
        case -0x7ff8df11:
code_r0x0071f7e1:
          return "ERROR_DS_UNKNOWN_ERROR";
        case -0x7ff8df10:
code_r0x0071f7eb:
          return "ERROR_DS_ROOT_REQUIRES_CLASS_TOP";
        case -0x7ff8df0f:
code_r0x0071f7f5:
          return "ERROR_DS_REFUSING_FSMO_ROLES";
        case -0x7ff8df0e:
code_r0x0071f7ff:
          return "ERROR_DS_MISSING_FSMO_SETTINGS";
        case -0x7ff8df0d:
code_r0x0071f809:
          return "ERROR_DS_UNABLE_TO_SURRENDER_ROLES";
        case -0x7ff8df0c:
code_r0x0071f813:
          return "ERROR_DS_DRA_GENERIC";
        case -0x7ff8df0b:
code_r0x0071f81d:
          return "ERROR_DS_DRA_INVALID_PARAMETER";
        case -0x7ff8df0a:
code_r0x0071f827:
          return "ERROR_DS_DRA_BUSY";
        case -0x7ff8df09:
code_r0x0071f831:
          return "ERROR_DS_DRA_BAD_DN";
        case -0x7ff8df08:
code_r0x0071f83b:
          return "ERROR_DS_DRA_BAD_NC";
        case -0x7ff8df07:
code_r0x0071f845:
          return "ERROR_DS_DRA_DN_EXISTS";
        case -0x7ff8df06:
code_r0x0071f84f:
          return "ERROR_DS_DRA_INTERNAL_ERROR";
        case -0x7ff8df05:
code_r0x0071f859:
          return "ERROR_DS_DRA_INCONSISTENT_DIT";
        case -0x7ff8df04:
code_r0x0071f863:
          return "ERROR_DS_DRA_CONNECTION_FAILED";
        case -0x7ff8df03:
code_r0x0071f86d:
          return "ERROR_DS_DRA_BAD_INSTANCE_TYPE";
        case -0x7ff8df02:
code_r0x0071f877:
          return "ERROR_DS_DRA_OUT_OF_MEM";
        case -0x7ff8df01:
code_r0x0071f881:
          return "ERROR_DS_DRA_MAIL_PROBLEM";
        case -0x7ff8df00:
code_r0x0071f88b:
          return "ERROR_DS_DRA_REF_ALREADY_EXISTS";
        case -0x7ff8deff:
code_r0x0071f895:
          return "ERROR_DS_DRA_REF_NOT_FOUND";
        case -0x7ff8defe:
code_r0x0071f89f:
          return "ERROR_DS_DRA_OBJ_IS_REP_SOURCE";
        case -0x7ff8defd:
code_r0x0071f8a9:
          return "ERROR_DS_DRA_DB_ERROR";
        case -0x7ff8defc:
code_r0x0071f8b3:
          return "ERROR_DS_DRA_NO_REPLICA";
        case -0x7ff8defb:
code_r0x0071f8bd:
          return "ERROR_DS_DRA_ACCESS_DENIED";
        case -0x7ff8defa:
code_r0x0071f8c7:
          return "ERROR_DS_DRA_NOT_SUPPORTED";
        case -0x7ff8def9:
code_r0x0071f8d1:
          return "ERROR_DS_DRA_RPC_CANCELLED";
        case -0x7ff8def8:
code_r0x0071f8db:
          return "ERROR_DS_DRA_SOURCE_DISABLED";
        case -0x7ff8def7:
code_r0x0071f8e5:
          return "ERROR_DS_DRA_SINK_DISABLED";
        case -0x7ff8def6:
code_r0x0071f8ef:
          return "ERROR_DS_DRA_NAME_COLLISION";
        case -0x7ff8def5:
code_r0x0071f8f9:
          return "ERROR_DS_DRA_SOURCE_REINSTALLED";
        case -0x7ff8def4:
code_r0x0071f903:
          return "ERROR_DS_DRA_MISSING_PARENT";
        case -0x7ff8def3:
code_r0x0071f90d:
          return "ERROR_DS_DRA_PREEMPTED";
        case -0x7ff8def2:
code_r0x0071f917:
          return "ERROR_DS_DRA_ABANDON_SYNC";
        case -0x7ff8def1:
code_r0x0071f921:
          return "ERROR_DS_DRA_SHUTDOWN";
        case -0x7ff8def0:
code_r0x0071f92b:
          return "ERROR_DS_DRA_INCOMPATIBLE_PARTIAL_SET";
        case -0x7ff8deef:
code_r0x0071f935:
          return "ERROR_DS_DRA_SOURCE_IS_PARTIAL_REPLICA";
        case -0x7ff8deee:
code_r0x0071f93f:
          return "ERROR_DS_DRA_EXTN_CONNECTION_FAILED";
        case -0x7ff8deed:
code_r0x0071f949:
          return "ERROR_DS_INSTALL_SCHEMA_MISMATCH";
        case -0x7ff8deec:
code_r0x0071f953:
          return "ERROR_DS_DUP_LINK_ID";
        case -0x7ff8deeb:
code_r0x0071f95d:
          return "ERROR_DS_NAME_ERROR_RESOLVING";
        case -0x7ff8deea:
code_r0x0071f967:
          return "ERROR_DS_NAME_ERROR_NOT_FOUND";
        case -0x7ff8dee9:
code_r0x0071f971:
          return "ERROR_DS_NAME_ERROR_NOT_UNIQUE";
        case -0x7ff8dee8:
code_r0x0071f97b:
          return "ERROR_DS_NAME_ERROR_NO_MAPPING";
        case -0x7ff8dee7:
code_r0x0071f985:
          return "ERROR_DS_NAME_ERROR_DOMAIN_ONLY";
        case -0x7ff8dee6:
code_r0x0071f98f:
          return "ERROR_DS_NAME_ERROR_NO_SYNTACTICAL_MAPPING";
        case -0x7ff8dee5:
code_r0x0071f999:
          return "ERROR_DS_CONSTRUCTED_ATT_MOD";
        case -0x7ff8dee4:
code_r0x0071f9a3:
          return "ERROR_DS_WRONG_OM_OBJ_CLASS";
        case -0x7ff8dee3:
code_r0x0071f9ad:
          return "ERROR_DS_DRA_REPL_PENDING";
        case -0x7ff8dee2:
code_r0x0071f9b7:
          return "ERROR_DS_DS_REQUIRED";
        case -0x7ff8dee1:
code_r0x0071f9c1:
          return "ERROR_DS_INVALID_LDAP_DISPLAY_NAME";
        case -0x7ff8dee0:
code_r0x0071f9cb:
          return "ERROR_DS_NON_BASE_SEARCH";
        case -0x7ff8dedf:
code_r0x0071f9d5:
          return "ERROR_DS_CANT_RETRIEVE_ATTS";
        case -0x7ff8dede:
code_r0x0071f9df:
          return "ERROR_DS_BACKLINK_WITHOUT_LINK";
        case -0x7ff8dedd:
code_r0x0071f9e9:
          return "ERROR_DS_EPOCH_MISMATCH";
        case -0x7ff8dedc:
code_r0x0071f9f3:
          return "ERROR_DS_SRC_NAME_MISMATCH";
        case -0x7ff8dedb:
code_r0x0071f9fd:
          return "ERROR_DS_SRC_AND_DST_NC_IDENTICAL";
        case -0x7ff8deda:
code_r0x0071fa07:
          return "ERROR_DS_DST_NC_MISMATCH";
        case -0x7ff8ded9:
code_r0x0071fa11:
          return "ERROR_DS_NOT_AUTHORITIVE_FOR_DST_NC";
        case -0x7ff8ded8:
code_r0x0071fa1b:
          return "ERROR_DS_SRC_GUID_MISMATCH";
        case -0x7ff8ded7:
code_r0x0071fa25:
          return "ERROR_DS_CANT_MOVE_DELETED_OBJECT";
        case -0x7ff8ded6:
code_r0x0071fa2f:
          return "ERROR_DS_PDC_OPERATION_IN_PROGRESS";
        case -0x7ff8ded5:
code_r0x0071fa39:
          return "ERROR_DS_CROSS_DOMAIN_CLEANUP_REQD";
        case -0x7ff8ded4:
code_r0x0071fa43:
          return "ERROR_DS_ILLEGAL_XDOM_MOVE_OPERATION";
        case -0x7ff8ded3:
code_r0x0071fa4d:
          return "ERROR_DS_CANT_WITH_ACCT_GROUP_MEMBERSHPS";
        case -0x7ff8ded2:
code_r0x0071fa57:
          return "ERROR_DS_NC_MUST_HAVE_NC_PARENT";
        case -0x7ff8ded1:
code_r0x0071fa61:
          return "ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE";
        case -0x7ff8ded0:
code_r0x0071fa6b:
          return "ERROR_DS_DST_DOMAIN_NOT_NATIVE";
        case -0x7ff8decf:
code_r0x0071fa75:
          return "ERROR_DS_MISSING_INFRASTRUCTURE_CONTAINER";
        case -0x7ff8dece:
code_r0x0071fa7f:
          return "ERROR_DS_CANT_MOVE_ACCOUNT_GROUP";
        case -0x7ff8decd:
code_r0x0071fa89:
          return "ERROR_DS_CANT_MOVE_RESOURCE_GROUP";
        case -0x7ff8decc:
code_r0x0071fa93:
          return "ERROR_DS_INVALID_SEARCH_FLAG";
        case -0x7ff8decb:
code_r0x0071fa9d:
          return "ERROR_DS_NO_TREE_DELETE_ABOVE_NC";
        case -0x7ff8deca:
code_r0x0071faa7:
          return "ERROR_DS_COULDNT_LOCK_TREE_FOR_DELETE";
        case -0x7ff8dec9:
code_r0x0071fab1:
          return "ERROR_DS_COULDNT_IDENTIFY_OBJECTS_FOR_TREE_DELETE";
        case -0x7ff8dec8:
code_r0x0071fabb:
          return "ERROR_DS_SAM_INIT_FAILURE";
        case -0x7ff8dec7:
code_r0x0071fac5:
          return "ERROR_DS_SENSITIVE_GROUP_VIOLATION";
        case -0x7ff8dec6:
code_r0x0071facf:
          return "ERROR_DS_CANT_MOD_PRIMARYGROUPID";
        case -0x7ff8dec5:
code_r0x0071fad9:
          return "ERROR_DS_ILLEGAL_BASE_SCHEMA_MOD";
        case -0x7ff8dec4:
code_r0x0071fae3:
          return "ERROR_DS_NONSAFE_SCHEMA_CHANGE";
        case -0x7ff8dec3:
code_r0x0071faed:
          return "ERROR_DS_SCHEMA_UPDATE_DISALLOWED";
        case -0x7ff8dec2:
code_r0x0071faf7:
          return "ERROR_DS_CANT_CREATE_UNDER_SCHEMA";
        case -0x7ff8dec1:
code_r0x0071fb01:
          return "ERROR_DS_INSTALL_NO_SRC_SCH_VERSION";
        case -0x7ff8dec0:
code_r0x0071fb0b:
          return "ERROR_DS_INSTALL_NO_SCH_VERSION_IN_INIFILE";
        case -0x7ff8debf:
code_r0x0071fb15:
          return "ERROR_DS_INVALID_GROUP_TYPE";
        case -0x7ff8debe:
code_r0x0071fb1f:
          return "ERROR_DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN";
        case -0x7ff8debd:
code_r0x0071fb29:
          return "ERROR_DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN";
        case -0x7ff8debc:
code_r0x0071fb33:
          return "ERROR_DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER";
        case -0x7ff8debb:
code_r0x0071fb3d:
          return "ERROR_DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER";
        case -0x7ff8deba:
code_r0x0071fb47:
          return "ERROR_DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER";
        case -0x7ff8deb9:
code_r0x0071fb51:
          return "ERROR_DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER";
        case -0x7ff8deb8:
code_r0x0071fb5b:
          return "ERROR_DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER";
        case -0x7ff8deb7:
code_r0x0071fb65:
          return "ERROR_DS_HAVE_PRIMARY_MEMBERS";
        case -0x7ff8deb6:
code_r0x0071fb6f:
          return "ERROR_DS_STRING_SD_CONVERSION_FAILED";
        case -0x7ff8deb5:
code_r0x0071fb79:
          return "ERROR_DS_NAMING_MASTER_GC";
        case -0x7ff8deb4:
code_r0x0071fb83:
          return "ERROR_DS_DNS_LOOKUP_FAILURE";
        case -0x7ff8deb3:
code_r0x0071fb8d:
          return "ERROR_DS_COULDNT_UPDATE_SPNS";
        case -0x7ff8deb2:
code_r0x0071fb97:
          return "ERROR_DS_CANT_RETRIEVE_SD";
        case -0x7ff8deb1:
code_r0x0071fba1:
          return "ERROR_DS_KEY_NOT_UNIQUE";
        case -0x7ff8deb0:
code_r0x0071fbab:
          return "ERROR_DS_WRONG_LINKED_ATT_SYNTAX";
        case -0x7ff8deaf:
code_r0x0071fbb5:
          return "ERROR_DS_SAM_NEED_BOOTKEY_PASSWORD";
        case -0x7ff8deae:
code_r0x0071fbbf:
          return "ERROR_DS_SAM_NEED_BOOTKEY_FLOPPY";
        case -0x7ff8dead:
code_r0x0071fbc9:
          return "ERROR_DS_CANT_START";
        case -0x7ff8deac:
code_r0x0071fbd3:
          return "ERROR_DS_INIT_FAILURE";
        case -0x7ff8deab:
code_r0x0071fbdd:
          return "ERROR_DS_NO_PKT_PRIVACY_ON_CONNECTION";
        case -0x7ff8deaa:
code_r0x0071fbe7:
          return "ERROR_DS_SOURCE_DOMAIN_IN_FOREST";
        case -0x7ff8dea9:
code_r0x0071fbf1:
          return "ERROR_DS_DESTINATION_DOMAIN_NOT_IN_FOREST";
        case -0x7ff8dea8:
code_r0x0071fbfb:
          return "ERROR_DS_DESTINATION_AUDITING_NOT_ENABLED";
        case -0x7ff8dea7:
code_r0x0071fc05:
          return "ERROR_DS_CANT_FIND_DC_FOR_SRC_DOMAIN";
        case -0x7ff8dea6:
code_r0x0071fc0f:
          return "ERROR_DS_SRC_OBJ_NOT_GROUP_OR_USER";
        case -0x7ff8dea5:
code_r0x0071fc19:
          return "ERROR_DS_SRC_SID_EXISTS_IN_FOREST";
        case -0x7ff8dea4:
code_r0x0071fc23:
          return "ERROR_DS_SRC_AND_DST_OBJECT_CLASS_MISMATCH";
        case -0x7ff8dea3:
code_r0x0071fc2d:
          return "ERROR_SAM_INIT_FAILURE";
        case -0x7ff8dea2:
code_r0x0071fc37:
          return "ERROR_DS_DRA_SCHEMA_INFO_SHIP";
        case -0x7ff8dea1:
code_r0x0071fc41:
          return "ERROR_DS_DRA_SCHEMA_CONFLICT";
        case -0x7ff8dea0:
code_r0x0071fc4b:
          return "ERROR_DS_DRA_EARLIER_SCHEMA_CONFLICT";
        case -0x7ff8de9f:
code_r0x0071fc55:
          return "ERROR_DS_DRA_OBJ_NC_MISMATCH";
        case -0x7ff8de9e:
code_r0x0071fc5f:
          return "ERROR_DS_NC_STILL_HAS_DSAS";
        case -0x7ff8de9d:
code_r0x0071fc69:
          return "ERROR_DS_GC_REQUIRED";
        case -0x7ff8de9c:
code_r0x0071fc73:
          return "ERROR_DS_LOCAL_MEMBER_OF_LOCAL_ONLY";
        case -0x7ff8de9b:
code_r0x0071fc7d:
          return "ERROR_DS_NO_FPO_IN_UNIVERSAL_GROUPS";
        case -0x7ff8de9a:
code_r0x0071fc87:
          return "ERROR_DS_CANT_ADD_TO_GC";
        case -0x7ff8de99:
code_r0x0071fc91:
          return "ERROR_DS_NO_CHECKPOINT_WITH_PDC";
        case -0x7ff8de98:
code_r0x0071fc9b:
          return "ERROR_DS_SOURCE_AUDITING_NOT_ENABLED";
        case -0x7ff8de97:
code_r0x0071fca5:
          return "ERROR_DS_CANT_CREATE_IN_NONDOMAIN_NC";
        case -0x7ff8de96:
code_r0x0071fcaf:
          return "ERROR_DS_INVALID_NAME_FOR_SPN";
        case -0x7ff8de95:
code_r0x0071fcb9:
          return "ERROR_DS_FILTER_USES_CONTRUCTED_ATTRS";
        case -0x7ff8de94:
code_r0x0071fcc3:
          return "ERROR_DS_UNICODEPWD_NOT_IN_QUOTES";
        case -0x7ff8de93:
code_r0x0071fccd:
          return "ERROR_DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED";
        case -0x7ff8de92:
code_r0x0071fcd7:
          return "ERROR_DS_MUST_BE_RUN_ON_DST_DC";
        case -0x7ff8de91:
code_r0x0071fce1:
          return "ERROR_DS_SRC_DC_MUST_BE_SP4_OR_GREATER";
        case -0x7ff8de90:
code_r0x0071fceb:
          return "ERROR_DS_CANT_TREE_DELETE_CRITICAL_OBJ";
        case -0x7ff8de8f:
code_r0x0071fcf5:
          return "ERROR_DS_INIT_FAILURE_CONSOLE";
        case -0x7ff8de8e:
code_r0x0071fcff:
          return "ERROR_DS_SAM_INIT_FAILURE_CONSOLE";
        case -0x7ff8de8d:
code_r0x0071fd09:
          return "ERROR_DS_FOREST_VERSION_TOO_HIGH";
        case -0x7ff8de8c:
code_r0x0071fd13:
          return "ERROR_DS_DOMAIN_VERSION_TOO_HIGH";
        case -0x7ff8de8b:
code_r0x0071fd1d:
          return "ERROR_DS_FOREST_VERSION_TOO_LOW";
        case -0x7ff8de8a:
code_r0x0071fd27:
          return "ERROR_DS_DOMAIN_VERSION_TOO_LOW";
        case -0x7ff8de89:
code_r0x0071fd31:
          return "ERROR_DS_INCOMPATIBLE_VERSION";
        case -0x7ff8de88:
code_r0x0071fd3b:
          return "ERROR_DS_LOW_DSA_VERSION";
        case -0x7ff8de87:
code_r0x0071fd45:
          return "ERROR_DS_NO_BEHAVIOR_VERSION_IN_MIXEDDOMAIN";
        case -0x7ff8de86:
code_r0x0071fd4f:
          return "ERROR_DS_NOT_SUPPORTED_SORT_ORDER";
        case -0x7ff8de85:
code_r0x0071fd59:
          return "ERROR_DS_NAME_NOT_UNIQUE";
        case -0x7ff8de84:
code_r0x0071fd63:
          return "ERROR_DS_MACHINE_ACCOUNT_CREATED_PRENT4";
        case -0x7ff8de83:
code_r0x0071fd6d:
          return "ERROR_DS_OUT_OF_VERSION_STORE";
        case -0x7ff8de82:
code_r0x0071fd77:
          return "ERROR_DS_INCOMPATIBLE_CONTROLS_USED";
        case -0x7ff8de81:
code_r0x0071fd81:
          return "ERROR_DS_NO_REF_DOMAIN";
        }
      }
    }
    else if (param_1 < -0x7ff8dcd7) {
      if (param_1 == -0x7ff8dcd8) {
LAB_0071fe8f:
        return "DNS_ERROR_RESPONSE_CODES_BASE";
      }
      switch(param_1) {
      case -0x7ff8de7f:
code_r0x0071fd95:
        return "ERROR_DS_LINK_ID_NOT_AVAILABLE";
      case -0x7ff8de7e:
code_r0x0071fd9f:
        return "ERROR_DS_AG_CANT_HAVE_UNIVERSAL_MEMBER";
      case -0x7ff8de7d:
code_r0x0071fda9:
        return "ERROR_DS_MODIFYDN_DISALLOWED_BY_INSTANCE_TYPE";
      case -0x7ff8de7c:
code_r0x0071fdb3:
        return "ERROR_DS_NO_OBJECT_MOVE_IN_SCHEMA_NC";
      case -0x7ff8de7b:
code_r0x0071fdbd:
        return "ERROR_DS_MODIFYDN_DISALLOWED_BY_FLAG";
      case -0x7ff8de7a:
code_r0x0071fdc7:
        return "ERROR_DS_MODIFYDN_WRONG_GRANDPARENT";
      case -0x7ff8de79:
code_r0x0071fdd1:
        return "ERROR_DS_NAME_ERROR_TRUST_REFERRAL";
      case -0x7ff8de78:
code_r0x0071fddb:
        return "ERROR_NOT_SUPPORTED_ON_STANDARD_SERVER";
      case -0x7ff8de77:
code_r0x0071fde5:
        return "ERROR_DS_CANT_ACCESS_REMOTE_PART_OF_AD";
      case -0x7ff8de76:
code_r0x0071fdef:
        return "ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE_V2";
      case -0x7ff8de75:
code_r0x0071fdf9:
        return "ERROR_DS_THREAD_LIMIT_EXCEEDED";
      case -0x7ff8de74:
code_r0x0071fe03:
        return "ERROR_DS_NOT_CLOSEST";
      case -0x7ff8de73:
code_r0x0071fe0d:
        return "ERROR_DS_CANT_DERIVE_SPN_WITHOUT_SERVER_REF";
      case -0x7ff8de72:
code_r0x0071fe17:
        return "ERROR_DS_SINGLE_USER_MODE_FAILED";
      case -0x7ff8de71:
code_r0x0071fe21:
        return "ERROR_DS_NTDSCRIPT_SYNTAX_ERROR";
      case -0x7ff8de70:
code_r0x0071fe2b:
        return "ERROR_DS_NTDSCRIPT_PROCESS_ERROR";
      case -0x7ff8de6f:
code_r0x0071fe35:
        return "ERROR_DS_DIFFERENT_REPL_EPOCHS";
      case -0x7ff8de6e:
code_r0x0071fe3f:
        return "ERROR_DS_DRS_EXTENSIONS_CHANGED";
      case -0x7ff8de6d:
code_r0x0071fe49:
        return "ERROR_DS_REPLICA_SET_CHANGE_NOT_ALLOWED_ON_DISABLED_CR";
      case -0x7ff8de6c:
code_r0x0071fe53:
        return "ERROR_DS_NO_MSDS_INTID";
      case -0x7ff8de6b:
code_r0x0071fe5d:
        return "ERROR_DS_DUP_MSDS_INTID";
      case -0x7ff8de6a:
code_r0x0071fe67:
        return "ERROR_DS_EXISTS_IN_RDNATTID";
      case -0x7ff8de69:
code_r0x0071fe71:
        return "ERROR_DS_AUTHORIZATION_FAILED";
      case -0x7ff8de68:
code_r0x0071fe7b:
        return "ERROR_DS_INVALID_SCRIPT";
      case -0x7ff8de67:
code_r0x0071fe85:
        return "ERROR_DS_REMOTE_CROSSREF_OP_FAILED";
      }
    }
    else if (param_1 < -0x7ff8dae3) {
      if (param_1 == -0x7ff8dae4) {
LAB_0071ff43:
        return "DNS_ERROR_PACKET_FMT_BASE";
      }
      switch(param_1) {
      case -0x7ff8dcd7:
code_r0x0071fec1:
        return "DNS_ERROR_RCODE_FORMAT_ERROR";
      case -0x7ff8dcd6:
code_r0x0071fecb:
        return "DNS_ERROR_RCODE_SERVER_FAILURE";
      case -0x7ff8dcd5:
code_r0x0071fed5:
        return "DNS_ERROR_RCODE_NAME_ERROR";
      case -0x7ff8dcd4:
code_r0x0071fedf:
        return "DNS_ERROR_RCODE_NOT_IMPLEMENTED";
      case -0x7ff8dcd3:
code_r0x0071fee9:
        return "DNS_ERROR_RCODE_REFUSED";
      case -0x7ff8dcd2:
code_r0x0071fef3:
        return "DNS_ERROR_RCODE_YXDOMAIN";
      case -0x7ff8dcd1:
code_r0x0071fefd:
        return "DNS_ERROR_RCODE_YXRRSET";
      case -0x7ff8dcd0:
code_r0x0071ff07:
        return "DNS_ERROR_RCODE_NXRRSET";
      case -0x7ff8dccf:
code_r0x0071ff11:
        return "DNS_ERROR_RCODE_NOTAUTH";
      case -0x7ff8dcce:
code_r0x0071ff1b:
        return "DNS_ERROR_RCODE_NOTZONE";
      case -0x7ff8dcc8:
code_r0x0071ff25:
        return "DNS_ERROR_RCODE_BADSIG";
      case -0x7ff8dcc7:
code_r0x0071ff2f:
        return "DNS_ERROR_RCODE_BADKEY";
      case -0x7ff8dcc6:
code_r0x0071ff39:
        return "DNS_ERROR_RCODE_BADTIME";
      }
    }
    else if (param_1 < -0x7ff8c948) {
      if (param_1 == -0x7ff8c949) {
LAB_00720be5:
        return "ERROR_SXS_KEY_NOT_FOUND";
      }
      if (param_1 < -0x7ff8d502) {
        if (param_1 == -0x7ff8d503) {
LAB_00720550:
          return "WSA_QOS_RECEIVERS";
        }
        if (param_1 < -0x7ff8d984) {
          if (param_1 == -0x7ff8d985) {
LAB_00720211:
            return "DNS_ERROR_NO_TCPIP";
          }
          if (param_1 < -0x7ff8da6b) {
            if (param_1 == -0x7ff8da6c) goto LAB_007203c9;
            switch(param_1) {
            case -0x7ff8dae3:
              goto code_r0x0071ff91;
            case -0x7ff8dae2:
              goto code_r0x0071ff9b;
            case -0x7ff8dae1:
              goto code_r0x0071ffa5;
            case -0x7ff8dae0:
              goto code_r0x0071ffaf;
            case -0x7ff8dadf:
              goto code_r0x0071ffb9;
            case -0x7ff8dab2:
              goto code_r0x0071ffc3;
            case -0x7ff8dab1:
              goto code_r0x0071ffcd;
            case -0x7ff8dab0:
              goto code_r0x0071ffd7;
            case -0x7ff8daaf:
              goto code_r0x0071ffe1;
            case -0x7ff8daae:
              goto code_r0x0071ffeb;
            case -0x7ff8daad:
              goto code_r0x0071fff5;
            case -0x7ff8daac:
              goto code_r0x0071ffff;
            case -0x7ff8daab:
              goto code_r0x00720009;
            case -0x7ff8daaa:
              goto code_r0x00720013;
            case -0x7ff8daa9:
              goto code_r0x0072001d;
            case -0x7ff8da80:
              goto code_r0x00720027;
            case -0x7ff8da7f:
              goto code_r0x00720031;
            case -0x7ff8da7e:
              goto code_r0x0072003b;
            case -0x7ff8da7d:
              goto code_r0x00720045;
            case -0x7ff8da7c:
              goto code_r0x0072004f;
            case -0x7ff8da7b:
              goto code_r0x00720059;
            case -0x7ff8da7a:
              goto code_r0x00720063;
            case -0x7ff8da79:
              goto code_r0x0072006d;
            case -0x7ff8da78:
              goto code_r0x00720077;
            case -0x7ff8da77:
              goto code_r0x00720081;
            case -0x7ff8da76:
              goto code_r0x0072008b;
            case -0x7ff8da75:
              goto code_r0x00720095;
            case -0x7ff8da74:
              goto code_r0x0072009f;
            case -0x7ff8da73:
              goto code_r0x007200a9;
            case -0x7ff8da72:
              goto code_r0x007200b3;
            case -0x7ff8da71:
              goto code_r0x007200bd;
            case -0x7ff8da70:
              goto code_r0x007200c7;
            case -0x7ff8da6f:
              goto code_r0x007200d1;
            case -0x7ff8da6e:
              goto code_r0x007200db;
            case -0x7ff8da6d:
              goto code_r0x007203bf;
            }
          }
          else if (param_1 < -0x7ff8da11) {
            if (param_1 == -0x7ff8da12) goto LAB_00720171;
            if (param_1 < -0x7ff8da1a) {
              if (param_1 == -0x7ff8da1b) goto LAB_00720117;
              if (param_1 < -0x7ff8da4a) {
                if (param_1 == -0x7ff8da4b) goto LAB_007200f9;
                if (param_1 == -0x7ff8da6b) goto LAB_007203d3;
                if (param_1 == -0x7ff8da4e) goto LAB_007200e5;
                if (param_1 == -0x7ff8da4d) goto LAB_007200ef;
                if (param_1 == -0x7ff8da4c) goto code_r0x00718724;
              }
              else {
                if (param_1 == -0x7ff8da4a) goto LAB_00720103;
                if (param_1 == -0x7ff8da49) goto LAB_0072010d;
                if (param_1 == -0x7ff8da1c) goto code_r0x0071874f;
              }
            }
            else {
              switch(param_1) {
              case -0x7ff8da1a:
                goto LAB_00720121;
              case -0x7ff8da19:
                goto LAB_0072012b;
              case -0x7ff8da18:
                goto LAB_00720135;
              case -0x7ff8da17:
                goto LAB_0072013f;
              case -0x7ff8da16:
                goto LAB_00720149;
              case -0x7ff8da15:
                goto LAB_00720153;
              case -0x7ff8da14:
                goto LAB_0072015d;
              case -0x7ff8da13:
                goto LAB_00720167;
              }
            }
          }
          else if (param_1 < -0x7ff8d9e9) {
            if (param_1 == -0x7ff8d9ea) goto LAB_007201d5;
            switch(param_1) {
            case -0x7ff8da11:
              goto LAB_0072017b;
            case -0x7ff8da10:
              goto LAB_00720185;
            case -0x7ff8da0f:
              goto LAB_0072018f;
            case -0x7ff8da0e:
              goto LAB_00720199;
            case -0x7ff8da0d:
              goto LAB_007201a3;
            case -0x7ff8da0c:
              goto LAB_007201ad;
            case -0x7ff8da0b:
              goto LAB_007201b7;
            case -0x7ff8da0a:
              goto LAB_007201c1;
            case -0x7ff8da09:
              goto LAB_007201cb;
            }
          }
          else {
            if (param_1 == -0x7ff8d9e9) goto LAB_007201df;
            if (param_1 == -0x7ff8d9e8) goto LAB_007201e9;
            if (param_1 == -0x7ff8d9e7) goto LAB_007201f3;
            if (param_1 == -0x7ff8d9b8) goto LAB_007201fd;
            if (param_1 == -0x7ff8d9b7) goto LAB_00720207;
            if (param_1 == -0x7ff8d986) goto code_r0x007187d4;
          }
        }
        else if (param_1 < -0x7ff8d8b7) {
          if (param_1 == -0x7ff8d8b8) goto LAB_0072031f;
          if (param_1 < -0x7ff8d8c8) {
            if (param_1 == -0x7ff8d8c9) goto LAB_00720275;
            if (param_1 < -0x7ff8d8e6) {
              if (param_1 == -0x7ff8d8e7) goto LAB_0072022f;
              if (param_1 < -0x7ff8d950) {
                if (param_1 == -0x7ff8d951) goto LAB_007203f1;
                if (param_1 == -0x7ff8d984) goto LAB_0072021b;
                if (param_1 == -0x7ff8d954) goto LAB_007203dd;
                if (param_1 == -0x7ff8d953) goto LAB_007203e7;
                if (param_1 == -0x7ff8d952) goto code_r0x0071884a;
              }
              else {
                if (param_1 == -0x7ff8d950) goto LAB_007203fb;
                if (param_1 == -0x7ff8d8f0) goto LAB_00720225;
                if (param_1 == -0x7ff8d8ec) goto code_r0x00718875;
              }
            }
            else if (param_1 < -0x7ff8d8cc) {
              if (param_1 == -0x7ff8d8cd) goto LAB_00720257;
              if (param_1 == -0x7ff8d8e3) goto LAB_00720239;
              if (param_1 == -0x7ff8d8e2) goto LAB_00720243;
              if (param_1 == -0x7ff8d8da) goto LAB_0072024d;
              if (param_1 == -0x7ff8d8d8) goto code_r0x007188ba;
            }
            else {
              if (param_1 == -0x7ff8d8cc) goto LAB_00720261;
              if (param_1 == -0x7ff8d8cb) goto LAB_0072026b;
              if (param_1 == -0x7ff8d8ca) goto code_r0x007188e5;
            }
          }
          else {
            switch(param_1) {
            case -0x7ff8d8c8:
              goto LAB_0072027f;
            case -0x7ff8d8c7:
              goto LAB_00720289;
            case -0x7ff8d8c6:
              goto LAB_00720293;
            case -0x7ff8d8c5:
              goto LAB_0072029d;
            case -0x7ff8d8c4:
              goto LAB_007202a7;
            case -0x7ff8d8c3:
              goto LAB_007202b1;
            case -0x7ff8d8c2:
              goto LAB_007202bb;
            case -0x7ff8d8c1:
              goto LAB_007202c5;
            case -0x7ff8d8c0:
              goto LAB_007202cf;
            case -0x7ff8d8bf:
              goto LAB_007202d9;
            case -0x7ff8d8be:
              goto LAB_007202e3;
            case -0x7ff8d8bd:
              goto LAB_007202ed;
            case -0x7ff8d8bc:
              goto LAB_007202f7;
            case -0x7ff8d8bb:
              goto LAB_00720301;
            case -0x7ff8d8ba:
              goto LAB_0072030b;
            case -0x7ff8d8b9:
              goto LAB_00720315;
            }
          }
        }
        else if (param_1 < -0x7ff8d506) {
          if (param_1 == -0x7ff8d507) {
LAB_007204e1:
            return "WSAHOST_NOT_FOUND";
          }
          switch(param_1) {
          case -0x7ff8d8b7:
            goto LAB_00720329;
          case -0x7ff8d8b6:
            goto LAB_00720333;
          case -0x7ff8d8b5:
            goto LAB_0072033d;
          case -0x7ff8d8b4:
            goto LAB_00720347;
          case -0x7ff8d8b3:
            goto LAB_00720351;
          case -0x7ff8d8b2:
            goto LAB_0072035b;
          case -0x7ff8d8b1:
            goto LAB_00720365;
          case -0x7ff8d8b0:
            goto LAB_0072036f;
          case -0x7ff8d8af:
            goto LAB_00720379;
          case -0x7ff8d8ae:
            goto LAB_00720383;
          case -0x7ff8d8ad:
            goto LAB_0072038d;
          case -0x7ff8d8ac:
            goto LAB_00720397;
          case -0x7ff8d8ab:
            goto LAB_007203a1;
          case -0x7ff8d8aa:
            goto LAB_007203ab;
          case -0x7ff8d8a9:
            goto LAB_007203b5;
          case -0x7ff8d895:
            goto LAB_00720405;
          case -0x7ff8d894:
LAB_007204ac:
            return "WSAVERNOTSUPPORTED";
          case -0x7ff8d893:
LAB_007204a2:
            return "WSANOTINITIALISED";
          case -0x7ff8d88b:
LAB_00720498:
            return "WSAEDISCON";
          case -0x7ff8d88a:
LAB_0072048e:
            return "WSAENOMORE";
          case -0x7ff8d889:
LAB_00720484:
            return "WSAECANCELLED";
          case -0x7ff8d888:
LAB_0072047a:
            return "WSAEINVALIDPROCTABLE";
          case -0x7ff8d887:
code_r0x00720470:
            return "WSAEINVALIDPROVIDER";
          case -0x7ff8d886:
LAB_007204b6:
            return "WSAEPROVIDERFAILEDINIT";
          case -0x7ff8d885:
LAB_0072051d:
            return "WSASYSCALLFAILURE";
          case -0x7ff8d884:
LAB_00720513:
            return "WSASERVICE_NOT_FOUND";
          case -0x7ff8d883:
LAB_00720509:
            return "WSATYPE_NOT_FOUND";
          case -0x7ff8d882:
LAB_007204ff:
            return "WSA_E_NO_MORE";
          case -0x7ff8d881:
LAB_007204f5:
            return "WSA_E_CANCELLED";
          case -0x7ff8d880:
LAB_007204eb:
            return "WSAEREFUSED";
          }
        }
        else {
          if (param_1 == -0x7ff8d506) {
LAB_00720527:
            return "WSATRY_AGAIN";
          }
          if (param_1 == -0x7ff8d505) {
LAB_00720546:
            return "WSANO_RECOVERY";
          }
          if (param_1 == -0x7ff8d504) goto code_r0x00718950;
        }
      }
      else if (param_1 < -0x7ff8cd37) {
        if (param_1 == -0x7ff8cd38) {
LAB_00720686:
          return "ERROR_IPSEC_QM_POLICY_EXISTS";
        }
        switch(param_1) {
        case -0x7ff8d502:
LAB_0072055a:
          return "WSA_QOS_SENDERS";
        case -0x7ff8d501:
LAB_00720564:
          return "WSA_QOS_NO_SENDERS";
        case -0x7ff8d500:
LAB_0072056e:
          return "WSA_QOS_NO_RECEIVERS";
        case -0x7ff8d4ff:
LAB_00720578:
          return "WSA_QOS_REQUEST_CONFIRMED";
        case -0x7ff8d4fe:
LAB_00720582:
          return "WSA_QOS_ADMISSION_FAILURE";
        case -0x7ff8d4fd:
LAB_0072058c:
          return "WSA_QOS_POLICY_FAILURE";
        case -0x7ff8d4fc:
LAB_00720596:
          return "WSA_QOS_BAD_STYLE";
        case -0x7ff8d4fb:
LAB_007205a0:
          return "WSA_QOS_BAD_OBJECT";
        case -0x7ff8d4fa:
LAB_007205aa:
          return "WSA_QOS_TRAFFIC_CTRL_ERROR";
        case -0x7ff8d4f9:
LAB_007205b4:
          return "WSA_QOS_GENERIC_ERROR";
        case -0x7ff8d4f8:
LAB_007205be:
          return "WSA_QOS_ESERVICETYPE";
        case -0x7ff8d4f7:
LAB_007205c8:
          return "WSA_QOS_EFLOWSPEC";
        case -0x7ff8d4f6:
LAB_007205fa:
          return "WSA_QOS_EPROVSPECBUF";
        case -0x7ff8d4f5:
LAB_00720604:
          return "WSA_QOS_EFILTERSTYLE";
        case -0x7ff8d4f4:
LAB_0072060e:
          return "WSA_QOS_EFILTERTYPE";
        case -0x7ff8d4f3:
LAB_00720618:
          return "WSA_QOS_EFILTERCOUNT";
        case -0x7ff8d4f2:
LAB_00720622:
          return "WSA_QOS_EOBJLENGTH";
        case -0x7ff8d4f1:
LAB_0072062c:
          return "WSA_QOS_EFLOWCOUNT";
        case -0x7ff8d4f0:
LAB_00720636:
          return "WSA_QOS_EUNKOWNPSOBJ";
        case -0x7ff8d4ef:
LAB_00720640:
          return "WSA_QOS_EPOLICYOBJ";
        case -0x7ff8d4ee:
LAB_0072064a:
          return "WSA_QOS_EFLOWDESC";
        case -0x7ff8d4ed:
LAB_00720654:
          return "WSA_QOS_EPSFLOWSPEC";
        case -0x7ff8d4ec:
LAB_0072065e:
          return "WSA_QOS_EPSFILTERSPEC";
        case -0x7ff8d4eb:
LAB_00720668:
          return "WSA_QOS_ESDMODEOBJ";
        case -0x7ff8d4ea:
LAB_00720672:
          return "WSA_QOS_ESHAPERATEOBJ";
        case -0x7ff8d4e9:
LAB_0072067c:
          return "WSA_QOS_RESERVED_PETYPE";
        }
      }
      else if (param_1 < -0x7ff8ca17) {
        if (param_1 == -0x7ff8ca18) {
LAB_00720823:
          return "ERROR_IPSEC_IKE_NEG_STATUS_BEGIN";
        }
        switch(param_1) {
        case -0x7ff8cd37:
LAB_007206a5:
          return "ERROR_IPSEC_QM_POLICY_NOT_FOUND";
        case -0x7ff8cd36:
LAB_007206af:
          return "ERROR_IPSEC_QM_POLICY_IN_USE";
        case -0x7ff8cd35:
LAB_007206b9:
          return "ERROR_IPSEC_MM_POLICY_EXISTS";
        case -0x7ff8cd34:
LAB_007206c3:
          return "ERROR_IPSEC_MM_POLICY_NOT_FOUND";
        case -0x7ff8cd33:
LAB_007206cd:
          return "ERROR_IPSEC_MM_POLICY_IN_USE";
        case -0x7ff8cd32:
LAB_007206d7:
          return "ERROR_IPSEC_MM_FILTER_EXISTS";
        case -0x7ff8cd31:
LAB_007206e1:
          return "ERROR_IPSEC_MM_FILTER_NOT_FOUND";
        case -0x7ff8cd30:
LAB_007206eb:
          return "ERROR_IPSEC_TRANSPORT_FILTER_EXISTS";
        case -0x7ff8cd2f:
LAB_007206f5:
          return "ERROR_IPSEC_TRANSPORT_FILTER_NOT_FOUND";
        case -0x7ff8cd2e:
LAB_007206ff:
          return "ERROR_IPSEC_MM_AUTH_EXISTS";
        case -0x7ff8cd2d:
LAB_00720709:
          return "ERROR_IPSEC_MM_AUTH_NOT_FOUND";
        case -0x7ff8cd2c:
LAB_00720713:
          return "ERROR_IPSEC_MM_AUTH_IN_USE";
        case -0x7ff8cd2b:
LAB_0072071d:
          return "ERROR_IPSEC_DEFAULT_MM_POLICY_NOT_FOUND";
        case -0x7ff8cd2a:
LAB_00720727:
          return "ERROR_IPSEC_DEFAULT_MM_AUTH_NOT_FOUND";
        case -0x7ff8cd29:
          goto LAB_00720731;
        case -0x7ff8cd28:
LAB_007207c3:
          return "ERROR_IPSEC_TUNNEL_FILTER_EXISTS";
        case -0x7ff8cd27:
LAB_007207b9:
          return "ERROR_IPSEC_TUNNEL_FILTER_NOT_FOUND";
        case -0x7ff8cd26:
LAB_007207af:
          return "ERROR_IPSEC_MM_FILTER_PENDING_DELETION";
        case -0x7ff8cd25:
LAB_007207a5:
          return "ERROR_IPSEC_TRANSPORT_FILTER_PENDING_DELETION";
        case -0x7ff8cd24:
LAB_0072079b:
          return "ERROR_IPSEC_TUNNEL_FILTER_PENDING_DELETION";
        case -0x7ff8cd23:
LAB_00720791:
          return "ERROR_IPSEC_MM_POLICY_PENDING_DELETION";
        case -0x7ff8cd22:
code_r0x00720787:
          return "ERROR_IPSEC_MM_AUTH_PENDING_DELETION";
        case -0x7ff8cd21:
LAB_007207cd:
          return "ERROR_IPSEC_QM_POLICY_PENDING_DELETION";
        }
      }
      else {
        switch(param_1) {
        case -0x7ff8ca17:
LAB_00720819:
          return "ERROR_IPSEC_IKE_AUTH_FAIL";
        case -0x7ff8ca16:
LAB_0072080f:
          return "ERROR_IPSEC_IKE_ATTRIB_FAIL";
        case -0x7ff8ca15:
LAB_00720805:
          return "ERROR_IPSEC_IKE_NEGOTIATION_PENDING";
        case -0x7ff8ca14:
LAB_007207fb:
          return "ERROR_IPSEC_IKE_GENERAL_PROCESSING_ERROR";
        case -0x7ff8ca13:
code_r0x007207f1:
          return "ERROR_IPSEC_IKE_TIMED_OUT";
        case -0x7ff8ca12:
LAB_0072082d:
          return "ERROR_IPSEC_IKE_NO_CERT";
        case -0x7ff8ca11:
LAB_0072084c:
          return "ERROR_IPSEC_IKE_SA_DELETED";
        case -0x7ff8ca10:
LAB_00720856:
          return "ERROR_IPSEC_IKE_SA_REAPED";
        case -0x7ff8ca0f:
LAB_00720860:
          return "ERROR_IPSEC_IKE_MM_ACQUIRE_DROP";
        case -0x7ff8ca0e:
LAB_0072086a:
          return "ERROR_IPSEC_IKE_QM_ACQUIRE_DROP";
        case -0x7ff8ca0d:
LAB_00720874:
          return "ERROR_IPSEC_IKE_QUEUE_DROP_MM";
        case -0x7ff8ca0c:
LAB_0072087e:
          return "ERROR_IPSEC_IKE_QUEUE_DROP_NO_MM";
        case -0x7ff8ca0b:
LAB_00720888:
          return "ERROR_IPSEC_IKE_DROP_NO_RESPONSE";
        case -0x7ff8ca0a:
LAB_00720892:
          return "ERROR_IPSEC_IKE_MM_DELAY_DROP";
        case -0x7ff8ca09:
LAB_0072089c:
          return "ERROR_IPSEC_IKE_QM_DELAY_DROP";
        case -0x7ff8ca08:
LAB_007208a6:
          return "ERROR_IPSEC_IKE_ERROR";
        case -0x7ff8ca07:
LAB_007208b0:
          return "ERROR_IPSEC_IKE_CRL_FAILED";
        case -0x7ff8ca06:
LAB_007208ba:
          return "ERROR_IPSEC_IKE_INVALID_KEY_USAGE";
        case -0x7ff8ca05:
LAB_007208c4:
          return "ERROR_IPSEC_IKE_INVALID_CERT_TYPE";
        case -0x7ff8ca04:
LAB_007208ce:
          return "ERROR_IPSEC_IKE_NO_PRIVATE_KEY";
        case -0x7ff8ca02:
LAB_007208d8:
          return "ERROR_IPSEC_IKE_DH_FAIL";
        case -0x7ff8ca00:
LAB_007208f7:
          return "ERROR_IPSEC_IKE_INVALID_HEADER";
        case -0x7ff8c9ff:
LAB_00720901:
          return "ERROR_IPSEC_IKE_NO_POLICY";
        case -0x7ff8c9fe:
LAB_0072090b:
          return "ERROR_IPSEC_IKE_INVALID_SIGNATURE";
        case -0x7ff8c9fd:
LAB_00720915:
          return "ERROR_IPSEC_IKE_KERBEROS_ERROR";
        case -0x7ff8c9fc:
LAB_0072091f:
          return "ERROR_IPSEC_IKE_NO_PUBLIC_KEY";
        case -0x7ff8c9fb:
LAB_00720929:
          return "ERROR_IPSEC_IKE_PROCESS_ERR";
        case -0x7ff8c9fa:
LAB_00720933:
          return "ERROR_IPSEC_IKE_PROCESS_ERR_SA";
        case -0x7ff8c9f9:
LAB_0072093d:
          return "ERROR_IPSEC_IKE_PROCESS_ERR_PROP";
        case -0x7ff8c9f8:
LAB_00720947:
          return "ERROR_IPSEC_IKE_PROCESS_ERR_TRANS";
        case -0x7ff8c9f7:
LAB_00720951:
          return "ERROR_IPSEC_IKE_PROCESS_ERR_KE";
        case -0x7ff8c9f6:
LAB_0072095b:
          return "ERROR_IPSEC_IKE_PROCESS_ERR_ID";
        case -0x7ff8c9f5:
LAB_00720965:
          return "ERROR_IPSEC_IKE_PROCESS_ERR_CERT";
        case -0x7ff8c9f4:
LAB_0072096f:
          return "ERROR_IPSEC_IKE_PROCESS_ERR_CERT_REQ";
        case -0x7ff8c9f3:
LAB_00720979:
          return "ERROR_IPSEC_IKE_PROCESS_ERR_HASH";
        case -0x7ff8c9f2:
LAB_00720983:
          return "ERROR_IPSEC_IKE_PROCESS_ERR_SIG";
        case -0x7ff8c9f1:
LAB_0072098d:
          return "ERROR_IPSEC_IKE_PROCESS_ERR_NONCE";
        case -0x7ff8c9f0:
LAB_00720997:
          return "ERROR_IPSEC_IKE_PROCESS_ERR_NOTIFY";
        case -0x7ff8c9ef:
LAB_007209a1:
          return "ERROR_IPSEC_IKE_PROCESS_ERR_DELETE";
        case -0x7ff8c9ee:
LAB_007209ab:
          return "ERROR_IPSEC_IKE_PROCESS_ERR_VENDOR";
        case -0x7ff8c9ed:
LAB_007209b5:
          return "ERROR_IPSEC_IKE_INVALID_PAYLOAD";
        case -0x7ff8c9ec:
LAB_007209bf:
          return "ERROR_IPSEC_IKE_LOAD_SOFT_SA";
        case -0x7ff8c9eb:
LAB_007209c9:
          return "ERROR_IPSEC_IKE_SOFT_SA_TORN_DOWN";
        case -0x7ff8c9ea:
LAB_007209d3:
          return "ERROR_IPSEC_IKE_INVALID_COOKIE";
        case -0x7ff8c9e9:
LAB_007209dd:
          return "ERROR_IPSEC_IKE_NO_PEER_CERT";
        case -0x7ff8c9e8:
LAB_007209e7:
          return "ERROR_IPSEC_IKE_PEER_CRL_FAILED";
        case -0x7ff8c9e7:
LAB_007209f1:
          return "ERROR_IPSEC_IKE_POLICY_CHANGE";
        case -0x7ff8c9e6:
LAB_007209fb:
          return "ERROR_IPSEC_IKE_NO_MM_POLICY";
        case -0x7ff8c9e5:
LAB_00720a05:
          return "ERROR_IPSEC_IKE_NOTCBPRIV";
        case -0x7ff8c9e4:
LAB_00720a0f:
          return "ERROR_IPSEC_IKE_SECLOADFAIL";
        case -0x7ff8c9e3:
          goto LAB_00720a19;
        case -0x7ff8c9e2:
          goto LAB_00720a4b;
        case -0x7ff8c9e1:
          goto LAB_00720a55;
        case -0x7ff8c9e0:
          goto LAB_00720a5f;
        case -0x7ff8c9df:
          goto LAB_00720a69;
        case -0x7ff8c9de:
          goto LAB_00720a73;
        case -0x7ff8c9dd:
          goto LAB_00720a7d;
        case -0x7ff8c9dc:
          goto LAB_00720a87;
        case -0x7ff8c9db:
          goto LAB_00720a91;
        case -0x7ff8c9da:
          goto LAB_00720a9b;
        case -0x7ff8c9d9:
          goto LAB_00720aa5;
        case -0x7ff8c9d8:
          goto LAB_00720aaf;
        case -0x7ff8c9d7:
          goto LAB_00720ab9;
        case -0x7ff8c9d6:
          goto LAB_00720ac3;
        case -0x7ff8c9d5:
          goto LAB_00720acd;
        case -0x7ff8c9d4:
          goto LAB_00720ad7;
        case -0x7ff8c9d3:
          goto LAB_00720ae1;
        case -0x7ff8c9d2:
          goto LAB_00720aeb;
        case -0x7ff8c9d1:
          goto LAB_00720af5;
        case -0x7ff8c9d0:
          goto LAB_00720aff;
        case -0x7ff8c9cf:
          goto LAB_00720b09;
        case -0x7ff8c9ce:
          goto LAB_00720b13;
        case -0x7ff8c9cd:
          goto LAB_00720b1d;
        case -0x7ff8c9cc:
          goto LAB_00720b27;
        case -0x7ff8c9cb:
          goto LAB_00720b31;
        case -0x7ff8c9ca:
          goto LAB_00720b3b;
        case -0x7ff8c9c9:
          goto LAB_00720b45;
        case -0x7ff8c9c7:
          goto LAB_00720b4f;
        case -0x7ff8c9c6:
          goto LAB_00720b59;
        case -0x7ff8c9c5:
          goto LAB_00720b63;
        case -0x7ff8c9c4:
          goto LAB_00720b6d;
        case -0x7ff8c950:
          goto LAB_00720b77;
        case -0x7ff8c94f:
          goto LAB_00720ba9;
        case -0x7ff8c94e:
          goto LAB_00720bb3;
        case -0x7ff8c94d:
          goto LAB_00720bbd;
        case -0x7ff8c94c:
          goto LAB_00720bc7;
        case -0x7ff8c94b:
          goto LAB_00720bd1;
        case -0x7ff8c94a:
          goto LAB_00720bdb;
        }
      }
    }
    else if (param_1 < -0x7ff7fffe) {
      if (param_1 == -0x7ff7ffff) {
        return "CO_E_CLASS_CREATE_FAILED";
      }
      switch(param_1) {
      case -0x7ff8c948:
LAB_00720bef:
        return "ERROR_SXS_VERSION_CONFLICT";
      case -0x7ff8c947:
LAB_00720bf9:
        return "ERROR_SXS_WRONG_SECTION_TYPE";
      case -0x7ff8c946:
LAB_00720c03:
        return "ERROR_SXS_THREAD_QUERIES_DISABLED";
      case -0x7ff8c945:
LAB_00720c0d:
        return "ERROR_SXS_PROCESS_DEFAULT_ALREADY_SET";
      case -0x7ff8c944:
LAB_00720c17:
        return "ERROR_SXS_UNKNOWN_ENCODING_GROUP";
      case -0x7ff8c943:
LAB_00720c21:
        return "ERROR_SXS_UNKNOWN_ENCODING";
      case -0x7ff8c942:
LAB_00720c2b:
        return "ERROR_SXS_INVALID_XML_NAMESPACE_URI";
      case -0x7ff8c941:
LAB_00720c35:
        return "ERROR_SXS_ROOT_MANIFEST_DEPENDENCY_NOT_INSTALLED";
      case -0x7ff8c940:
LAB_00720c3f:
        return "ERROR_SXS_LEAF_MANIFEST_DEPENDENCY_NOT_INSTALLED";
      case -0x7ff8c93f:
LAB_00720c49:
        return "ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE";
      case -0x7ff8c93e:
LAB_00720c53:
        return "ERROR_SXS_MANIFEST_MISSING_REQUIRED_DEFAULT_NAMESPACE";
      case -0x7ff8c93d:
LAB_00720c5d:
        return "ERROR_SXS_MANIFEST_INVALID_REQUIRED_DEFAULT_NAMESPACE";
      case -0x7ff8c93c:
LAB_00720c67:
        return "ERROR_SXS_PRIVATE_MANIFEST_CROSS_PATH_WITH_REPARSE_POINT";
      case -0x7ff8c93b:
LAB_00720c71:
        return "ERROR_SXS_DUPLICATE_DLL_NAME";
      case -0x7ff8c93a:
LAB_00720c7b:
        return "ERROR_SXS_DUPLICATE_WINDOWCLASS_NAME";
      case -0x7ff8c939:
LAB_00720c85:
        return "ERROR_SXS_DUPLICATE_CLSID";
      case -0x7ff8c938:
LAB_00720c8f:
        return "ERROR_SXS_DUPLICATE_IID";
      case -0x7ff8c937:
LAB_00720c99:
        return "ERROR_SXS_DUPLICATE_TLBID";
      case -0x7ff8c936:
LAB_00720ca3:
        return "ERROR_SXS_DUPLICATE_PROGID";
      case -0x7ff8c935:
LAB_00720cad:
        return "ERROR_SXS_DUPLICATE_ASSEMBLY_NAME";
      case -0x7ff8c934:
LAB_00720cb7:
        return "ERROR_SXS_FILE_HASH_MISMATCH";
      case -0x7ff8c933:
LAB_00720cc1:
        return "ERROR_SXS_POLICY_PARSE_ERROR";
      case -0x7ff8c932:
LAB_00720ccb:
        return "ERROR_SXS_XML_E_MISSINGQUOTE";
      case -0x7ff8c931:
LAB_00720cd5:
        return "ERROR_SXS_XML_E_COMMENTSYNTAX";
      case -0x7ff8c930:
LAB_00720cdf:
        return "ERROR_SXS_XML_E_BADSTARTNAMECHAR";
      case -0x7ff8c92f:
LAB_00720ce9:
        return "ERROR_SXS_XML_E_BADNAMECHAR";
      case -0x7ff8c92e:
LAB_00720cf3:
        return "ERROR_SXS_XML_E_BADCHARINSTRING";
      case -0x7ff8c92d:
LAB_00720cfd:
        return "ERROR_SXS_XML_E_XMLDECLSYNTAX";
      case -0x7ff8c92c:
LAB_00720d07:
        return "ERROR_SXS_XML_E_BADCHARDATA";
      case -0x7ff8c92b:
LAB_00720d11:
        return "ERROR_SXS_XML_E_MISSINGWHITESPACE";
      case -0x7ff8c92a:
LAB_00720d1b:
        return "ERROR_SXS_XML_E_EXPECTINGTAGEND";
      case -0x7ff8c929:
LAB_00720d25:
        return "ERROR_SXS_XML_E_MISSINGSEMICOLON";
      case -0x7ff8c928:
LAB_00720d2f:
        return "ERROR_SXS_XML_E_UNBALANCEDPAREN";
      case -0x7ff8c927:
LAB_00720d39:
        return "ERROR_SXS_XML_E_INTERNALERROR";
      case -0x7ff8c926:
LAB_00720d43:
        return "ERROR_SXS_XML_E_UNEXPECTED_WHITESPACE";
      case -0x7ff8c925:
LAB_00720d4d:
        return "ERROR_SXS_XML_E_INCOMPLETE_ENCODING";
      case -0x7ff8c924:
LAB_00720d57:
        return "ERROR_SXS_XML_E_MISSING_PAREN";
      case -0x7ff8c923:
LAB_00720d61:
        return "ERROR_SXS_XML_E_EXPECTINGCLOSEQUOTE";
      case -0x7ff8c922:
LAB_00720d6b:
        return "ERROR_SXS_XML_E_MULTIPLE_COLONS";
      case -0x7ff8c921:
LAB_00720d75:
        return "ERROR_SXS_XML_E_INVALID_DECIMAL";
      case -0x7ff8c920:
LAB_00720d7f:
        return "ERROR_SXS_XML_E_INVALID_HEXIDECIMAL";
      case -0x7ff8c91f:
LAB_00720d89:
        return "ERROR_SXS_XML_E_INVALID_UNICODE";
      case -0x7ff8c91e:
LAB_00720d93:
        return "ERROR_SXS_XML_E_WHITESPACEORQUESTIONMARK";
      case -0x7ff8c91d:
LAB_00720d9d:
        return "ERROR_SXS_XML_E_UNEXPECTEDENDTAG";
      case -0x7ff8c91c:
LAB_00720da7:
        return "ERROR_SXS_XML_E_UNCLOSEDTAG";
      case -0x7ff8c91b:
LAB_00720db1:
        return "ERROR_SXS_XML_E_DUPLICATEATTRIBUTE";
      case -0x7ff8c91a:
LAB_00720dbb:
        return "ERROR_SXS_XML_E_MULTIPLEROOTS";
      case -0x7ff8c919:
LAB_00720dc5:
        return "ERROR_SXS_XML_E_INVALIDATROOTLEVEL";
      case -0x7ff8c918:
LAB_00720dcf:
        return "ERROR_SXS_XML_E_BADXMLDECL";
      case -0x7ff8c917:
LAB_00720dd9:
        return "ERROR_SXS_XML_E_MISSINGROOT";
      case -0x7ff8c916:
LAB_00720de3:
        return "ERROR_SXS_XML_E_UNEXPECTEDEOF";
      case -0x7ff8c915:
LAB_00720ded:
        return "ERROR_SXS_XML_E_BADPEREFINSUBSET";
      case -0x7ff8c914:
LAB_00720df7:
        return "ERROR_SXS_XML_E_UNCLOSEDSTARTTAG";
      case -0x7ff8c913:
LAB_00720e01:
        return "ERROR_SXS_XML_E_UNCLOSEDENDTAG";
      case -0x7ff8c912:
LAB_00720e0b:
        return "ERROR_SXS_XML_E_UNCLOSEDSTRING";
      case -0x7ff8c911:
LAB_00720e15:
        return "ERROR_SXS_XML_E_UNCLOSEDCOMMENT";
      case -0x7ff8c910:
code_r0x00720e1f:
        return "ERROR_SXS_XML_E_UNCLOSEDDECL";
      case -0x7ff8c90f:
LAB_00720e29:
        return "ERROR_SXS_XML_E_UNCLOSEDCDATA";
      case -0x7ff8c90e:
LAB_00720e33:
        return "ERROR_SXS_XML_E_RESERVEDNAMESPACE";
      case -0x7ff8c90d:
LAB_00720e3d:
        return "ERROR_SXS_XML_E_INVALIDENCODING";
      case -0x7ff8c90c:
LAB_00720e47:
        return "ERROR_SXS_XML_E_INVALIDSWITCH";
      case -0x7ff8c90b:
LAB_00720e51:
        return "ERROR_SXS_XML_E_BADXMLCASE";
      case -0x7ff8c90a:
LAB_00720e5b:
        return "ERROR_SXS_XML_E_INVALID_STANDALONE";
      case -0x7ff8c909:
LAB_00720e65:
        return "ERROR_SXS_XML_E_UNEXPECTED_STANDALONE";
      case -0x7ff8c908:
LAB_00720e6f:
        return "ERROR_SXS_XML_E_INVALID_VERSION";
      case -0x7ff8c907:
LAB_00720e79:
        return "ERROR_SXS_XML_E_MISSINGEQUALS";
      case -0x7ff8c906:
LAB_00720e83:
        return "ERROR_SXS_PROTECTION_RECOVERY_FAILED";
      case -0x7ff8c905:
LAB_00720e8d:
        return "ERROR_SXS_PROTECTION_PUBLIC_KEY_TOO_SHORT";
      case -0x7ff8c904:
LAB_00720e97:
        return "ERROR_SXS_PROTECTION_CATALOG_NOT_VALID";
      case -0x7ff8c903:
LAB_00720ea1:
        return "ERROR_SXS_UNTRANSLATABLE_HRESULT";
      case -0x7ff8c902:
LAB_00720eab:
        return "ERROR_SXS_PROTECTION_CATALOG_FILE_MISSING";
      case -0x7ff8c901:
LAB_00720eb5:
        return "ERROR_SXS_MISSING_ASSEMBLY_IDENTITY_ATTRIBUTE";
      case -0x7ff8c900:
LAB_00720ebf:
        return "ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE_NAME";
      }
    }
    else if (param_1 < -0x7ff6fffe) {
      if (param_1 == -0x7ff6ffff) {
        return "NTE_BAD_UID";
      }
      switch(param_1) {
      case -0x7ff7fffe:
        return "CO_E_SCM_ERROR";
      case -0x7ff7fffd:
        return "CO_E_SCM_RPC_FAILURE";
      case -0x7ff7fffc:
        return "CO_E_BAD_PATH";
      case -0x7ff7fffb:
        return "CO_E_SERVER_EXEC_FAILURE";
      case -0x7ff7fffa:
        return "CO_E_OBJSRV_RPC_FAILURE";
      case -0x7ff7fff9:
        return "MK_E_NO_NORMALIZED";
      case -0x7ff7fff8:
        return "CO_E_SERVER_STOPPING";
      case -0x7ff7fff7:
        return "MEM_E_INVALID_ROOT";
      case -0x7ff7fff0:
        return "MEM_E_INVALID_LINK";
      case -0x7ff7ffef:
        return "MEM_E_INVALID_SIZE";
      }
    }
    else if (param_1 < -0x7ff6fcff) {
      if (param_1 == -0x7ff6fd00) {
        return "SEC_E_INSUFFICIENT_MEMORY";
      }
      switch(param_1) {
      case -0x7ff6fffe:
        return "NTE_BAD_HASH";
      case -0x7ff6fffd:
        return "NTE_BAD_KEY";
      case -0x7ff6fffc:
        return "NTE_BAD_LEN";
      case -0x7ff6fffb:
        return "NTE_BAD_DATA";
      case -0x7ff6fffa:
        return "NTE_BAD_SIGNATURE";
      case -0x7ff6fff9:
        return "NTE_BAD_VER";
      case -0x7ff6fff8:
        return "NTE_BAD_ALGID";
      case -0x7ff6fff7:
        return "NTE_BAD_FLAGS";
      case -0x7ff6fff6:
        return "NTE_BAD_TYPE";
      case -0x7ff6fff5:
        return "NTE_BAD_KEY_STATE";
      case -0x7ff6fff4:
        return "NTE_BAD_HASH_STATE";
      case -0x7ff6fff3:
        return "NTE_NO_KEY";
      case -0x7ff6fff2:
        return "NTE_NO_MEMORY";
      case -0x7ff6fff1:
        return "NTE_EXISTS";
      case -0x7ff6fff0:
        return "NTE_PERM";
      case -0x7ff6ffef:
        return "NTE_NOT_FOUND";
      case -0x7ff6ffee:
        return "NTE_DOUBLE_ENCRYPT";
      case -0x7ff6ffed:
        return "NTE_BAD_PROVIDER";
      case -0x7ff6ffec:
        return "NTE_BAD_PROV_TYPE";
      case -0x7ff6ffeb:
        return "NTE_BAD_PUBLIC_KEY";
      case -0x7ff6ffea:
        return "NTE_BAD_KEYSET";
      case -0x7ff6ffe9:
        return "NTE_PROV_TYPE_NOT_DEF";
      case -0x7ff6ffe8:
        return "NTE_PROV_TYPE_ENTRY_BAD";
      case -0x7ff6ffe7:
        return "NTE_KEYSET_NOT_DEF";
      case -0x7ff6ffe6:
        return "NTE_KEYSET_ENTRY_BAD";
      case -0x7ff6ffe5:
        return "NTE_PROV_TYPE_NO_MATCH";
      case -0x7ff6ffe4:
        return "NTE_SIGNATURE_FILE_BAD";
      case -0x7ff6ffe3:
        return "NTE_PROVIDER_DLL_FAIL";
      case -0x7ff6ffe2:
        return "NTE_PROV_DLL_NOT_FOUND";
      case -0x7ff6ffe1:
        return "NTE_BAD_KEYSET_PARAM";
      case -0x7ff6ffe0:
        return "NTE_FAIL";
      case -0x7ff6ffdf:
        return "NTE_SYS_ERR";
      case -0x7ff6ffde:
        return "NTE_SILENT_CONTEXT";
      case -0x7ff6ffdd:
        return "NTE_TOKEN_KEYSET_STORAGE_FULL";
      case -0x7ff6ffdc:
        return "NTE_TEMPORARY_PROFILE";
      case -0x7ff6ffdb:
        return "NTE_FIXEDPARAMETER";
      }
    }
    else if (param_1 < -0x7ff6effe) {
      if (param_1 == -0x7ff6efff) {
        return "CRYPT_E_MSG_ERROR";
      }
      switch(param_1) {
      case -0x7ff6fcff:
        return "SEC_E_INVALID_HANDLE";
      case -0x7ff6fcfe:
        return "SEC_E_UNSUPPORTED_FUNCTION";
      case -0x7ff6fcfd:
        return "SEC_E_TARGET_UNKNOWN";
      case -0x7ff6fcfc:
        return "SEC_E_INTERNAL_ERROR";
      case -0x7ff6fcfb:
        return "SEC_E_SECPKG_NOT_FOUND";
      case -0x7ff6fcfa:
        return "SEC_E_NOT_OWNER";
      case -0x7ff6fcf9:
        return "SEC_E_CANNOT_INSTALL";
      case -0x7ff6fcf8:
        return "SEC_E_INVALID_TOKEN";
      case -0x7ff6fcf7:
        return "SEC_E_CANNOT_PACK";
      case -0x7ff6fcf6:
        return "SEC_E_QOP_NOT_SUPPORTED";
      case -0x7ff6fcf5:
        return "SEC_E_NO_IMPERSONATION";
      case -0x7ff6fcf4:
        return "SEC_E_LOGON_DENIED";
      case -0x7ff6fcf3:
        return "SEC_E_UNKNOWN_CREDENTIALS";
      case -0x7ff6fcf2:
        return "SEC_E_NO_CREDENTIALS";
      case -0x7ff6fcf1:
        return "SEC_E_MESSAGE_ALTERED";
      case -0x7ff6fcf0:
        return "SEC_E_OUT_OF_SEQUENCE";
      case -0x7ff6fcef:
        return "SEC_E_NO_AUTHENTICATING_AUTHORITY";
      case -0x7ff6fcea:
        return "SEC_E_BAD_PKGID";
      case -0x7ff6fce9:
        return "SEC_E_CONTEXT_EXPIRED";
      case -0x7ff6fce8:
        return "SEC_E_INCOMPLETE_MESSAGE";
      case -0x7ff6fce0:
        return "SEC_E_INCOMPLETE_CREDENTIALS";
      case -0x7ff6fcdf:
        return "SEC_E_BUFFER_TOO_SMALL";
      case -0x7ff6fcde:
        return "SEC_E_WRONG_PRINCIPAL";
      case -0x7ff6fcdc:
        return "SEC_E_TIME_SKEW";
      case -0x7ff6fcdb:
        return "SEC_E_UNTRUSTED_ROOT";
      case -0x7ff6fcda:
        return "SEC_E_ILLEGAL_MESSAGE";
      case -0x7ff6fcd9:
        return "SEC_E_CERT_UNKNOWN";
      case -0x7ff6fcd8:
        return "SEC_E_CERT_EXPIRED";
      case -0x7ff6fcd7:
        return "SEC_E_ENCRYPT_FAILURE";
      case -0x7ff6fcd0:
        return "SEC_E_DECRYPT_FAILURE";
      case -0x7ff6fccf:
        return "SEC_E_ALGORITHM_MISMATCH";
      case -0x7ff6fcce:
        return "SEC_E_SECURITY_QOS_FAILED";
      case -0x7ff6fccd:
        return "SEC_E_UNFINISHED_CONTEXT_DELETED";
      case -0x7ff6fccc:
        return "SEC_E_NO_TGT_REPLY";
      case -0x7ff6fccb:
        return "SEC_E_NO_IP_ADDRESSES";
      case -0x7ff6fcca:
        return "SEC_E_WRONG_CREDENTIAL_HANDLE";
      case -0x7ff6fcc9:
        return "SEC_E_CRYPTO_SYSTEM_INVALID";
      case -0x7ff6fcc8:
        return "SEC_E_MAX_REFERRALS_EXCEEDED";
      case -0x7ff6fcc7:
        return "SEC_E_MUST_BE_KDC";
      case -0x7ff6fcc6:
        return "SEC_E_STRONG_CRYPTO_NOT_SUPPORTED";
      case -0x7ff6fcc5:
        return "SEC_E_TOO_MANY_PRINCIPALS";
      case -0x7ff6fcc4:
        return "SEC_E_NO_PA_DATA";
      case -0x7ff6fcc3:
        return "SEC_E_PKINIT_NAME_MISMATCH";
      case -0x7ff6fcc2:
        return "SEC_E_SMARTCARD_LOGON_REQUIRED";
      case -0x7ff6fcc1:
        return "SEC_E_SHUTDOWN_IN_PROGRESS";
      case -0x7ff6fcc0:
        return "SEC_E_KDC_INVALID_REQUEST";
      case -0x7ff6fcbf:
        return "SEC_E_KDC_UNABLE_TO_REFER";
      case -0x7ff6fcbe:
        return "SEC_E_KDC_UNKNOWN_ETYPE";
      case -0x7ff6fcbd:
        return "SEC_E_UNSUPPORTED_PREAUTH";
      case -0x7ff6fcbb:
        return "SEC_E_DELEGATION_REQUIRED";
      case -0x7ff6fcba:
        return "SEC_E_BAD_BINDINGS";
      case -0x7ff6fcb9:
        return "SEC_E_MULTIPLE_ACCOUNTS";
      case -0x7ff6fcb8:
        return "SEC_E_NO_KERB_KEY";
      case -0x7ff6fcaf:
        return "SEC_E_SMARTCARD_CERT_REVOKED";
      case -0x7ff6fcae:
        return "SEC_E_ISSUING_CA_UNTRUSTED";
      case -0x7ff6fcad:
        return "SEC_E_REVOCATION_OFFLINE_C";
      case -0x7ff6fcac:
        return "SEC_E_PKINIT_CLIENT_FAILURE";
      case -0x7ff6fcab:
        return "SEC_E_SMARTCARD_CERT_EXPIRED";
      }
    }
    else if (param_1 < -0x7ff6dffe) {
      if (param_1 == -0x7ff6dfff) {
        return "CRYPT_E_BAD_LEN";
      }
      switch(param_1) {
      case -0x7ff6effe:
        return "CRYPT_E_UNKNOWN_ALGO";
      case -0x7ff6effd:
        return "CRYPT_E_OID_FORMAT";
      case -0x7ff6effc:
        return "CRYPT_E_INVALID_MSG_TYPE";
      case -0x7ff6effb:
        return "CRYPT_E_UNEXPECTED_ENCODING";
      case -0x7ff6effa:
        return "CRYPT_E_AUTH_ATTR_MISSING";
      case -0x7ff6eff9:
        return "CRYPT_E_HASH_VALUE";
      case -0x7ff6eff8:
        return "CRYPT_E_INVALID_INDEX";
      case -0x7ff6eff7:
        return "CRYPT_E_ALREADY_DECRYPTED";
      case -0x7ff6eff6:
        return "CRYPT_E_NOT_DECRYPTED";
      case -0x7ff6eff5:
        return "CRYPT_E_RECIPIENT_NOT_FOUND";
      case -0x7ff6eff4:
        return "CRYPT_E_CONTROL_TYPE";
      case -0x7ff6eff3:
        return "CRYPT_E_ISSUER_SERIALNUMBER";
      case -0x7ff6eff2:
        return "CRYPT_E_SIGNER_NOT_FOUND";
      case -0x7ff6eff1:
        return "CRYPT_E_ATTRIBUTES_MISSING";
      case -0x7ff6eff0:
        return "CRYPT_E_STREAM_MSG_NOT_READY";
      case -0x7ff6efef:
        return "CRYPT_E_STREAM_INSUFFICIENT_DATA";
      }
    }
    else if (param_1 < -0x7ff6cfff) {
      if (param_1 == -0x7ff6d000) {
        return "CRYPT_E_OSS_ERROR";
      }
      switch(param_1) {
      case -0x7ff6dffe:
        return "CRYPT_E_BAD_ENCODE";
      case -0x7ff6dffd:
        return "CRYPT_E_FILE_ERROR";
      case -0x7ff6dffc:
        return "CRYPT_E_NOT_FOUND";
      case -0x7ff6dffb:
        return "CRYPT_E_EXISTS";
      case -0x7ff6dffa:
        return "CRYPT_E_NO_PROVIDER";
      case -0x7ff6dff9:
        return "CRYPT_E_SELF_SIGNED";
      case -0x7ff6dff8:
        return "CRYPT_E_DELETED_PREV";
      case -0x7ff6dff7:
        return "CRYPT_E_NO_MATCH";
      case -0x7ff6dff6:
        return "CRYPT_E_UNEXPECTED_MSG_TYPE";
      case -0x7ff6dff5:
        return "CRYPT_E_NO_KEY_PROPERTY";
      case -0x7ff6dff4:
        return "CRYPT_E_NO_DECRYPT_CERT";
      case -0x7ff6dff3:
        return "CRYPT_E_BAD_MSG";
      case -0x7ff6dff2:
        return "CRYPT_E_NO_SIGNER";
      case -0x7ff6dff1:
        return "CRYPT_E_PENDING_CLOSE";
      case -0x7ff6dff0:
        return "CRYPT_E_REVOKED";
      case -0x7ff6dfef:
        return "CRYPT_E_NO_REVOCATION_DLL";
      case -0x7ff6dfee:
        return "CRYPT_E_NO_REVOCATION_CHECK";
      case -0x7ff6dfed:
        return "CRYPT_E_REVOCATION_OFFLINE";
      case -0x7ff6dfec:
        return "CRYPT_E_NOT_IN_REVOCATION_DATABASE";
      case -0x7ff6dfe0:
        return "CRYPT_E_INVALID_NUMERIC_STRING";
      case -0x7ff6dfdf:
        return "CRYPT_E_INVALID_PRINTABLE_STRING";
      case -0x7ff6dfde:
        return "CRYPT_E_INVALID_IA5_STRING";
      case -0x7ff6dfdd:
        return "CRYPT_E_INVALID_X500_STRING";
      case -0x7ff6dfdc:
        return "CRYPT_E_NOT_CHAR_STRING";
      case -0x7ff6dfdb:
        return "CRYPT_E_FILERESIZED";
      case -0x7ff6dfda:
        return "CRYPT_E_SECURITY_SETTINGS";
      case -0x7ff6dfd9:
        return "CRYPT_E_NO_VERIFY_USAGE_DLL";
      case -0x7ff6dfd8:
        return "CRYPT_E_NO_VERIFY_USAGE_CHECK";
      case -0x7ff6dfd7:
        return "CRYPT_E_VERIFY_USAGE_OFFLINE";
      case -0x7ff6dfd6:
        return "CRYPT_E_NOT_IN_CTL";
      case -0x7ff6dfd5:
        return "CRYPT_E_NO_TRUSTED_SIGNER";
      case -0x7ff6dfd4:
        return "CRYPT_E_MISSING_PUBKEY_PARA";
      }
    }
    else if (param_1 < -0x7ff6ceff) {
      if (param_1 == -0x7ff6cf00) {
        return "CRYPT_E_ASN1_ERROR";
      }
      switch(param_1) {
      case -0x7ff6cfff:
        return "OSS_MORE_BUF";
      case -0x7ff6cffe:
        return "OSS_NEGATIVE_UINTEGER";
      case -0x7ff6cffd:
        return "OSS_PDU_RANGE";
      case -0x7ff6cffc:
        return "OSS_MORE_INPUT";
      case -0x7ff6cffb:
        return "OSS_DATA_ERROR";
      case -0x7ff6cffa:
        return "OSS_BAD_ARG";
      case -0x7ff6cff9:
        return "OSS_BAD_VERSION";
      case -0x7ff6cff8:
        return "OSS_OUT_MEMORY";
      case -0x7ff6cff7:
        return "OSS_PDU_MISMATCH";
      case -0x7ff6cff6:
        return "OSS_LIMITED";
      case -0x7ff6cff5:
        return "OSS_BAD_PTR";
      case -0x7ff6cff4:
        return "OSS_BAD_TIME";
      case -0x7ff6cff3:
        return "OSS_INDEFINITE_NOT_SUPPORTED";
      case -0x7ff6cff2:
        return "OSS_MEM_ERROR";
      case -0x7ff6cff1:
        return "OSS_BAD_TABLE";
      case -0x7ff6cff0:
        return "OSS_TOO_LONG";
      case -0x7ff6cfef:
        return "OSS_CONSTRAINT_VIOLATED";
      case -0x7ff6cfee:
        return "OSS_FATAL_ERROR";
      case -0x7ff6cfed:
        return "OSS_ACCESS_SERIALIZATION_ERROR";
      case -0x7ff6cfec:
        return "OSS_NULL_TBL";
      case -0x7ff6cfeb:
        return "OSS_NULL_FCN";
      case -0x7ff6cfea:
        return "OSS_BAD_ENCRULES";
      case -0x7ff6cfe9:
        return "OSS_UNAVAIL_ENCRULES";
      case -0x7ff6cfe8:
        return "OSS_CANT_OPEN_TRACE_WINDOW";
      case -0x7ff6cfe7:
        return "OSS_UNIMPLEMENTED";
      case -0x7ff6cfe6:
        return "OSS_OID_DLL_NOT_LINKED";
      case -0x7ff6cfe5:
        return "OSS_CANT_OPEN_TRACE_FILE";
      case -0x7ff6cfe4:
        return "OSS_TRACE_FILE_ALREADY_OPEN";
      case -0x7ff6cfe3:
        return "OSS_TABLE_MISMATCH";
      case -0x7ff6cfe2:
        return "OSS_TYPE_NOT_SUPPORTED";
      case -0x7ff6cfe1:
        return "OSS_REAL_DLL_NOT_LINKED";
      case -0x7ff6cfe0:
        return "OSS_REAL_CODE_NOT_LINKED";
      case -0x7ff6cfdf:
        return "OSS_OUT_OF_RANGE";
      case -0x7ff6cfde:
        return "OSS_COPIER_DLL_NOT_LINKED";
      case -0x7ff6cfdd:
        return "OSS_CONSTRAINT_DLL_NOT_LINKED";
      case -0x7ff6cfdc:
        return "OSS_COMPARATOR_DLL_NOT_LINKED";
      case -0x7ff6cfdb:
        return "OSS_COMPARATOR_CODE_NOT_LINKED";
      case -0x7ff6cfda:
        return "OSS_MEM_MGR_DLL_NOT_LINKED";
      case -0x7ff6cfd9:
        return "OSS_PDV_DLL_NOT_LINKED";
      case -0x7ff6cfd8:
        return "OSS_PDV_CODE_NOT_LINKED";
      case -0x7ff6cfd7:
        return "OSS_API_DLL_NOT_LINKED";
      case -0x7ff6cfd6:
        return "OSS_BERDER_DLL_NOT_LINKED";
      case -0x7ff6cfd5:
        return "OSS_PER_DLL_NOT_LINKED";
      case -0x7ff6cfd4:
        return "OSS_OPEN_TYPE_ERROR";
      case -0x7ff6cfd3:
        return "OSS_MUTEX_NOT_CREATED";
      case -0x7ff6cfd2:
        return "OSS_CANT_CLOSE_TRACE_FILE";
      }
    }
    else if (param_1 == -0x7ff6ceff) {
      return "CRYPT_E_ASN1_INTERNAL";
    }
  }
  else if (param_1 < -0x7ff6cecc) {
    if (param_1 == -0x7ff6cecd) {
      return "CRYPT_E_ASN1_PDU_TYPE";
    }
    switch(param_1) {
    case -0x7ff6cefd:
      return "CRYPT_E_ASN1_CORRUPT";
    case -0x7ff6cefc:
      return "CRYPT_E_ASN1_LARGE";
    case -0x7ff6cefb:
      return "CRYPT_E_ASN1_CONSTRAINT";
    case -0x7ff6cefa:
      return "CRYPT_E_ASN1_MEMORY";
    case -0x7ff6cef9:
      return "CRYPT_E_ASN1_OVERFLOW";
    case -0x7ff6cef8:
      return "CRYPT_E_ASN1_BADPDU";
    case -0x7ff6cef7:
      return "CRYPT_E_ASN1_BADARGS";
    case -0x7ff6cef6:
      return "CRYPT_E_ASN1_BADREAL";
    case -0x7ff6cef5:
      return "CRYPT_E_ASN1_BADTAG";
    case -0x7ff6cef4:
      return "CRYPT_E_ASN1_CHOICE";
    case -0x7ff6cef3:
      return "CRYPT_E_ASN1_RULE";
    case -0x7ff6cef2:
      return "CRYPT_E_ASN1_UTF8";
    }
  }
  else if (param_1 < 0x5de) {
    if (param_1 == 0x5dd) {
LAB_0071d8a3:
      return "ERROR_EVENTLOG_CANT_START";
    }
    if (param_1 < -0x7787eed5) {
      if (param_1 == -0x7787eed6) {
        return "DMUS_E_NOTPCM";
      }
      if (param_1 < -0x7feef7df) {
        if (param_1 == -0x7feef7e0) {
          return "COMADMIN_E_CANNOT_ALIAS_EVENTCLASS";
        }
        if (param_1 < -0x7ff0fdc8) {
          if (param_1 == -0x7ff0fdc9) {
            return "SPAPI_E_INCORRECTLY_COPIED_INF";
          }
          if (param_1 < -0x7ff4fff4) {
            if (param_1 == -0x7ff4fff5) {
              return "PERSIST_E_NOTSELFSIZING";
            }
            if (param_1 < -0x7ff6affc) {
              if (param_1 == -0x7ff6affd) {
                return "XENROLL_E_RESPONSE_UNEXPECTED_KA_HASH";
              }
              if (param_1 < -0x7ff6b7ff) {
                if (param_1 == -0x7ff6b800) {
                  return "CERTSRV_E_UNSUPPORTED_CERT_TYPE";
                }
                if (param_1 < -0x7ff6bff7) {
                  if (param_1 == -0x7ff6bff8) {
                    return "CERTSRV_E_ROLECONFLICT";
                  }
                  if (param_1 < -0x7ff6bffc) {
                    if (param_1 == -0x7ff6bffd) {
                      return "CERTSRV_E_BAD_REQUESTSTATUS";
                    }
                    if (param_1 == -0x7ff6cecc) {
                      return "CRYPT_E_ASN1_NYI";
                    }
                    if (param_1 == -0x7ff6cdff) {
                      return "CRYPT_E_ASN1_EXTENDED";
                    }
                    if (param_1 == -0x7ff6cdfe) {
                      return "CRYPT_E_ASN1_NOEOD";
                    }
                    if (param_1 == -0x7ff6bfff) {
                      return "CERTSRV_E_BAD_REQUESTSUBJECT";
                    }
                    if (param_1 == -0x7ff6bffe) {
                      return "CERTSRV_E_NO_REQUEST";
                    }
                  }
                  else {
                    if (param_1 == -0x7ff6bffc) {
                      return "CERTSRV_E_PROPERTY_EMPTY";
                    }
                    if (param_1 == -0x7ff6bffb) {
                      return "CERTSRV_E_INVALID_CA_CERTIFICATE";
                    }
                    if (param_1 == -0x7ff6bffa) {
                      return "CERTSRV_E_SERVER_SUSPENDED";
                    }
                    if (param_1 == -0x7ff6bff9) {
                      return "CERTSRV_E_ENCODING_LENGTH";
                    }
                  }
                }
                else {
                  switch(param_1) {
                  case -0x7ff6bff7:
                    return "CERTSRV_E_RESTRICTEDOFFICER";
                  case -0x7ff6bff6:
                    return "CERTSRV_E_KEY_ARCHIVAL_NOT_CONFIGURED";
                  case -0x7ff6bff5:
                    return "CERTSRV_E_NO_VALID_KRA";
                  case -0x7ff6bff4:
                    return "CERTSRV_E_BAD_REQUEST_KEY_ARCHIVAL";
                  case -0x7ff6bff3:
                    return "CERTSRV_E_NO_CAADMIN_DEFINED";
                  case -0x7ff6bff2:
                    return "CERTSRV_E_BAD_RENEWAL_CERT_ATTRIBUTE";
                  case -0x7ff6bff1:
                    return "CERTSRV_E_NO_DB_SESSIONS";
                  case -0x7ff6bff0:
                    return "CERTSRV_E_ALIGNMENT_FAULT";
                  case -0x7ff6bfef:
                    return "CERTSRV_E_ENROLL_DENIED";
                  case -0x7ff6bfee:
                    return "CERTSRV_E_TEMPLATE_DENIED";
                  }
                }
              }
              else if (param_1 < -0x7ff6afff) {
                if (param_1 == -0x7ff6b000) {
                  return "XENROLL_E_KEY_NOT_EXPORTABLE";
                }
                switch(param_1) {
                case -0x7ff6b7ff:
                  return "CERTSRV_E_NO_CERT_TYPE";
                case -0x7ff6b7fe:
                  return "CERTSRV_E_TEMPLATE_CONFLICT";
                case -0x7ff6b7fd:
                  return "CERTSRV_E_SUBJECT_ALT_NAME_REQUIRED";
                case -0x7ff6b7fc:
                  return "CERTSRV_E_ARCHIVED_KEY_REQUIRED";
                case -0x7ff6b7fb:
                  return "CERTSRV_E_SMIME_REQUIRED";
                case -0x7ff6b7fa:
                  return "CERTSRV_E_BAD_RENEWAL_SUBJECT";
                case -0x7ff6b7f9:
                  return "CERTSRV_E_BAD_TEMPLATE_VERSION";
                case -0x7ff6b7f8:
                  return "CERTSRV_E_TEMPLATE_POLICY_REQUIRED";
                case -0x7ff6b7f7:
                  return "CERTSRV_E_SIGNATURE_POLICY_REQUIRED";
                case -0x7ff6b7f6:
                  return "CERTSRV_E_SIGNATURE_COUNT";
                case -0x7ff6b7f5:
                  return "CERTSRV_E_SIGNATURE_REJECTED";
                case -0x7ff6b7f4:
                  return "CERTSRV_E_ISSUANCE_POLICY_REQUIRED";
                case -0x7ff6b7f3:
                  return "CERTSRV_E_SUBJECT_UPN_REQUIRED";
                case -0x7ff6b7f2:
                  return "CERTSRV_E_SUBJECT_DIRECTORY_GUID_REQUIRED";
                case -0x7ff6b7f1:
                  return "CERTSRV_E_SUBJECT_DNS_REQUIRED";
                case -0x7ff6b7f0:
                  return "CERTSRV_E_ARCHIVED_KEY_UNEXPECTED";
                case -0x7ff6b7ef:
                  return "CERTSRV_E_KEY_LENGTH";
                }
              }
              else {
                if (param_1 == -0x7ff6afff) {
                  return "XENROLL_E_CANNOT_ADD_ROOT_CERT";
                }
                if (param_1 == -0x7ff6affe) {
                  return "XENROLL_E_RESPONSE_KA_HASH_NOT_FOUND";
                }
              }
            }
            else if (param_1 < -0x7ff68ff3) {
              if (param_1 == -0x7ff68ff4) {
                return "MSSIPOTF_E_TABLE_CHECKSUM";
              }
              if (param_1 < -0x7ff68ffe) {
                if (param_1 == -0x7ff68fff) {
                  return "MSSIPOTF_E_OUTOFMEMRANGE";
                }
                if (param_1 < -0x7ff69ffb) {
                  if (param_1 == -0x7ff69ffc) {
                    return "TRUST_E_CERT_SIGNATURE";
                  }
                  if (param_1 == -0x7ff6affc) {
                    return "XENROLL_E_RESPONSE_KA_HASH_MISMATCH";
                  }
                  if (param_1 == -0x7ff6affb) {
                    return "XENROLL_E_KEYSPEC_SMIME_MISMATCH";
                  }
                  if (param_1 == -0x7ff69fff) {
                    return "TRUST_E_SYSTEM_ERROR";
                  }
                  if (param_1 == -0x7ff69ffe) {
                    return "TRUST_E_NO_SIGNER_CERT";
                  }
                  if (param_1 == -0x7ff69ffd) {
                    return "TRUST_E_COUNTER_SIGNER";
                  }
                }
                else {
                  if (param_1 == -0x7ff69ffb) {
                    return "TRUST_E_TIME_STAMP";
                  }
                  if (param_1 == -0x7ff69ff0) {
                    return "TRUST_E_BAD_DIGEST";
                  }
                  if (param_1 == -0x7ff69fe7) {
                    return "TRUST_E_BASIC_CONSTRAINTS";
                  }
                  if (param_1 == -0x7ff69fe2) {
                    return "TRUST_E_FINANCIAL_CRITERIA";
                  }
                }
              }
              else {
                switch(param_1) {
                case -0x7ff68ffe:
                  return "MSSIPOTF_E_CANTGETOBJECT";
                case -0x7ff68ffd:
                  return "MSSIPOTF_E_NOHEADTABLE";
                case -0x7ff68ffc:
                  return "MSSIPOTF_E_BAD_MAGICNUMBER";
                case -0x7ff68ffb:
                  return "MSSIPOTF_E_BAD_OFFSET_TABLE";
                case -0x7ff68ffa:
                  return "MSSIPOTF_E_TABLE_TAGORDER";
                case -0x7ff68ff9:
                  return "MSSIPOTF_E_TABLE_LONGWORD";
                case -0x7ff68ff8:
                  return "MSSIPOTF_E_BAD_FIRST_TABLE_PLACEMENT";
                case -0x7ff68ff7:
                  return "MSSIPOTF_E_TABLES_OVERLAP";
                case -0x7ff68ff6:
                  return "MSSIPOTF_E_TABLE_PADBYTES";
                case -0x7ff68ff5:
                  return "MSSIPOTF_E_FILETOOSMALL";
                }
              }
            }
            else if (param_1 < -0x7ff4fffe) {
              if (param_1 == -0x7ff4ffff) {
                return "TRUST_E_PROVIDER_UNKNOWN";
              }
              switch(param_1) {
              case -0x7ff68ff3:
                return "MSSIPOTF_E_FILE_CHECKSUM";
              case -0x7ff68ff0:
                return "MSSIPOTF_E_FAILED_POLICY";
              case -0x7ff68fef:
                return "MSSIPOTF_E_FAILED_HINTS_CHECK";
              case -0x7ff68fee:
                return "MSSIPOTF_E_NOT_OPENTYPE";
              case -0x7ff68fed:
                return "MSSIPOTF_E_FILE";
              case -0x7ff68fec:
                return "MSSIPOTF_E_CRYPT";
              case -0x7ff68feb:
                return "MSSIPOTF_E_BADVERSION";
              case -0x7ff68fea:
                return "MSSIPOTF_E_DSIG_STRUCTURE";
              case -0x7ff68fe9:
                return "MSSIPOTF_E_PCONST_CHECK";
              case -0x7ff68fe8:
                return "MSSIPOTF_E_STRUCTURE";
              }
            }
            else {
              switch(param_1) {
              case -0x7ff4fffe:
                return "TRUST_E_ACTION_UNKNOWN";
              case -0x7ff4fffd:
                return "TRUST_E_SUBJECT_FORM_UNKNOWN";
              case -0x7ff4fffc:
                return "TRUST_E_SUBJECT_NOT_TRUSTED";
              case -0x7ff4fffb:
                return "DIGSIG_E_ENCODE";
              case -0x7ff4fffa:
                return "DIGSIG_E_DECODE";
              case -0x7ff4fff9:
                return "DIGSIG_E_EXTENSIBILITY";
              case -0x7ff4fff8:
                return "DIGSIG_E_CRYPTO";
              case -0x7ff4fff7:
                return "PERSIST_E_SIZEDEFINITE";
              case -0x7ff4fff6:
                return "PERSIST_E_SIZEINDEFINITE";
              }
            }
          }
          else if (param_1 < -0x7ff0ffff) {
            if (param_1 == -0x7ff10000) {
              return "SPAPI_E_EXPECTED_SECTION_NAME";
            }
            switch(param_1) {
            case -0x7ff4ff00:
              return "TRUST_E_NOSIGNATURE";
            case -0x7ff4feff:
              return "CERT_E_EXPIRED";
            case -0x7ff4fefe:
              return "CERT_E_VALIDITYPERIODNESTING";
            case -0x7ff4fefd:
              return "CERT_E_ROLE";
            case -0x7ff4fefc:
              return "CERT_E_PATHLENCONST";
            case -0x7ff4fefb:
              return "CERT_E_CRITICAL";
            case -0x7ff4fefa:
              return "CERT_E_PURPOSE";
            case -0x7ff4fef9:
              return "CERT_E_ISSUERCHAINING";
            case -0x7ff4fef8:
              return "CERT_E_MALFORMED";
            case -0x7ff4fef7:
              return "CERT_E_UNTRUSTEDROOT";
            case -0x7ff4fef6:
              return "CERT_E_CHAINING";
            case -0x7ff4fef5:
              return "TRUST_E_FAIL";
            case -0x7ff4fef4:
              return "CERT_E_REVOKED";
            case -0x7ff4fef3:
              return "CERT_E_UNTRUSTEDTESTROOT";
            case -0x7ff4fef2:
              return "CERT_E_REVOCATION_FAILURE";
            case -0x7ff4fef1:
              return "CERT_E_CN_NO_MATCH";
            case -0x7ff4fef0:
              return "CERT_E_WRONG_USAGE";
            case -0x7ff4feef:
              return "TRUST_E_EXPLICIT_DISTRUST";
            case -0x7ff4feee:
              return "CERT_E_UNTRUSTEDCA";
            case -0x7ff4feed:
              return "CERT_E_INVALID_POLICY";
            case -0x7ff4feec:
              return "CERT_E_INVALID_NAME";
            }
          }
          else if (param_1 < -0x7ff0fde7) {
            if (param_1 == -0x7ff0fde8) {
              return "SPAPI_E_NO_CLASS_DRIVER_LIST";
            }
            if (param_1 < -0x7ff0fdf7) {
              if (param_1 == -0x7ff0fdf8) {
                return "SPAPI_E_DEVINFO_NOT_REGISTERED";
              }
              if (param_1 < -0x7ff0fdff) {
                if (param_1 == -0x7ff0fe00) {
                  return "SPAPI_E_NO_ASSOCIATED_CLASS";
                }
                if (param_1 == -0x7ff0ffff) {
                  return "SPAPI_E_BAD_SECTION_NAME_LINE";
                }
                if (param_1 == -0x7ff0fffe) {
                  return "SPAPI_E_SECTION_NAME_TOO_LONG";
                }
                if (param_1 == -0x7ff0fffd) {
                  return "SPAPI_E_GENERAL_SYNTAX";
                }
                if (param_1 == -0x7ff0ff00) {
                  return "SPAPI_E_WRONG_INF_STYLE";
                }
                if (param_1 == -0x7ff0feff) {
                  return "SPAPI_E_SECTION_NOT_FOUND";
                }
                if (param_1 == -0x7ff0fefe) {
                  return "SPAPI_E_LINE_NOT_FOUND";
                }
                if (param_1 == -0x7ff0fefd) {
                  return "SPAPI_E_NO_BACKUP";
                }
              }
              else {
                if (param_1 == -0x7ff0fdff) {
                  return "SPAPI_E_CLASS_MISMATCH";
                }
                if (param_1 == -0x7ff0fdfe) {
                  return "SPAPI_E_DUPLICATE_FOUND";
                }
                if (param_1 == -0x7ff0fdfd) {
                  return "SPAPI_E_NO_DRIVER_SELECTED";
                }
                if (param_1 == -0x7ff0fdfc) {
                  return "SPAPI_E_KEY_DOES_NOT_EXIST";
                }
                if (param_1 == -0x7ff0fdfb) {
                  return "SPAPI_E_INVALID_DEVINST_NAME";
                }
                if (param_1 == -0x7ff0fdfa) {
                  return "SPAPI_E_INVALID_CLASS";
                }
                if (param_1 == -0x7ff0fdf9) {
                  return "SPAPI_E_DEVINST_ALREADY_EXISTS";
                }
              }
            }
            else {
              switch(param_1) {
              case -0x7ff0fdf7:
                return "SPAPI_E_INVALID_REG_PROPERTY";
              case -0x7ff0fdf6:
                return "SPAPI_E_NO_INF";
              case -0x7ff0fdf5:
                return "SPAPI_E_NO_SUCH_DEVINST";
              case -0x7ff0fdf4:
                return "SPAPI_E_CANT_LOAD_CLASS_ICON";
              case -0x7ff0fdf3:
                return "SPAPI_E_INVALID_CLASS_INSTALLER";
              case -0x7ff0fdf2:
                return "SPAPI_E_DI_DO_DEFAULT";
              case -0x7ff0fdf1:
                return "SPAPI_E_DI_NOFILECOPY";
              case -0x7ff0fdf0:
                return "SPAPI_E_INVALID_HWPROFILE";
              case -0x7ff0fdef:
                return "SPAPI_E_NO_DEVICE_SELECTED";
              case -0x7ff0fdee:
                return "SPAPI_E_DEVINFO_LIST_LOCKED";
              case -0x7ff0fded:
                return "SPAPI_E_DEVINFO_DATA_LOCKED";
              case -0x7ff0fdec:
                return "SPAPI_E_DI_BAD_PATH";
              case -0x7ff0fdeb:
                return "SPAPI_E_NO_CLASSINSTALL_PARAMS";
              case -0x7ff0fdea:
                return "SPAPI_E_FILEQUEUE_LOCKED";
              case -0x7ff0fde9:
                return "SPAPI_E_BAD_SERVICE_INSTALLSECT";
              }
            }
          }
          else {
            switch(param_1) {
            case -0x7ff0fde7:
              return "SPAPI_E_NO_ASSOCIATED_SERVICE";
            case -0x7ff0fde6:
              return "SPAPI_E_NO_DEFAULT_DEVICE_INTERFACE";
            case -0x7ff0fde5:
              return "SPAPI_E_DEVICE_INTERFACE_ACTIVE";
            case -0x7ff0fde4:
              return "SPAPI_E_DEVICE_INTERFACE_REMOVED";
            case -0x7ff0fde3:
              return "SPAPI_E_BAD_INTERFACE_INSTALLSECT";
            case -0x7ff0fde2:
              return "SPAPI_E_NO_SUCH_INTERFACE_CLASS";
            case -0x7ff0fde1:
              return "SPAPI_E_INVALID_REFERENCE_STRING";
            case -0x7ff0fde0:
              return "SPAPI_E_INVALID_MACHINENAME";
            case -0x7ff0fddf:
              return "SPAPI_E_REMOTE_COMM_FAILURE";
            case -0x7ff0fdde:
              return "SPAPI_E_MACHINE_UNAVAILABLE";
            case -0x7ff0fddd:
              return "SPAPI_E_NO_CONFIGMGR_SERVICES";
            case -0x7ff0fddc:
              return "SPAPI_E_INVALID_PROPPAGE_PROVIDER";
            case -0x7ff0fddb:
              return "SPAPI_E_NO_SUCH_DEVICE_INTERFACE";
            case -0x7ff0fdda:
              return "SPAPI_E_DI_POSTPROCESSING_REQUIRED";
            case -0x7ff0fdd9:
              return "SPAPI_E_INVALID_COINSTALLER";
            case -0x7ff0fdd8:
              return "SPAPI_E_NO_COMPAT_DRIVERS";
            case -0x7ff0fdd7:
              return "SPAPI_E_NO_DEVICE_ICON";
            case -0x7ff0fdd6:
              return "SPAPI_E_INVALID_INF_LOGCONFIG";
            case -0x7ff0fdd5:
              return "SPAPI_E_DI_DONT_INSTALL";
            case -0x7ff0fdd4:
              return "SPAPI_E_INVALID_FILTER_DRIVER";
            case -0x7ff0fdd3:
              return "SPAPI_E_NON_WINDOWS_NT_DRIVER";
            case -0x7ff0fdd2:
              return "SPAPI_E_NON_WINDOWS_DRIVER";
            case -0x7ff0fdd1:
              return "SPAPI_E_NO_CATALOG_FOR_OEM_INF";
            case -0x7ff0fdd0:
              return "SPAPI_E_DEVINSTALL_QUEUE_NONNATIVE";
            case -0x7ff0fdcf:
              return "SPAPI_E_NOT_DISABLEABLE";
            case -0x7ff0fdce:
              return "SPAPI_E_CANT_REMOVE_DEVINST";
            case -0x7ff0fdcd:
              return "SPAPI_E_INVALID_TARGET";
            case -0x7ff0fdcc:
              return "SPAPI_E_DRIVER_NONNATIVE";
            case -0x7ff0fdcb:
              return "SPAPI_E_IN_WOW64";
            case -0x7ff0fdca:
              return "SPAPI_E_SET_SYSTEM_RESTORE_POINT";
            }
          }
        }
        else if (param_1 < -0x7feefbe0) {
          if (param_1 == -0x7feefbe1) {
            return "COMADMIN_E_APPDIRNOTFOUND";
          }
          if (param_1 < -0x7fefffd6) {
            if (param_1 == -0x7fefffd7) {
              return "SCARD_E_BAD_SEEK";
            }
            if (param_1 < -0x7fefffeb) {
              if (param_1 == -0x7fefffec) {
                return "SCARD_F_UNKNOWN_ERROR";
              }
              if (param_1 < -0x7feffff6) {
                if (param_1 == -0x7feffff7) {
                  return "SCARD_E_UNKNOWN_READER";
                }
                if (param_1 < -0x7feffffb) {
                  if (param_1 == -0x7feffffc) {
                    return "SCARD_E_INVALID_PARAMETER";
                  }
                  if (param_1 == -0x7ff0fdc8) {
                    return "SPAPI_E_SCE_DISABLED";
                  }
                  if (param_1 == -0x7ff0f000) {
                    return "SPAPI_E_ERROR_NOT_INSTALLED";
                  }
                  if (param_1 == -0x7fefffff) {
                    return "SCARD_F_INTERNAL_ERROR";
                  }
                  if (param_1 == -0x7feffffe) {
                    return "SCARD_E_CANCELLED";
                  }
                  if (param_1 == -0x7feffffd) {
                    return "SCARD_E_INVALID_HANDLE";
                  }
                }
                else {
                  if (param_1 == -0x7feffffb) {
                    return "SCARD_E_INVALID_TARGET";
                  }
                  if (param_1 == -0x7feffffa) {
                    return "SCARD_E_NO_MEMORY";
                  }
                  if (param_1 == -0x7feffff9) {
                    return "SCARD_F_WAITED_TOO_LONG";
                  }
                  if (param_1 == -0x7feffff8) {
                    return "SCARD_E_INSUFFICIENT_BUFFER";
                  }
                }
              }
              else {
                switch(param_1) {
                case -0x7feffff6:
                  return "SCARD_E_TIMEOUT";
                case -0x7feffff5:
                  return "SCARD_E_SHARING_VIOLATION";
                case -0x7feffff4:
                  return "SCARD_E_NO_SMARTCARD";
                case -0x7feffff3:
                  return "SCARD_E_UNKNOWN_CARD";
                case -0x7feffff2:
                  return "SCARD_E_CANT_DISPOSE";
                case -0x7feffff1:
                  return "SCARD_E_PROTO_MISMATCH";
                case -0x7feffff0:
                  return "SCARD_E_NOT_READY";
                case -0x7fefffef:
                  return "SCARD_E_INVALID_VALUE";
                case -0x7fefffee:
                  return "SCARD_E_SYSTEM_CANCELLED";
                case -0x7fefffed:
                  return "SCARD_F_COMM_ERROR";
                }
              }
            }
            else {
              switch(param_1) {
              case -0x7fefffeb:
                return "SCARD_E_INVALID_ATR";
              case -0x7fefffea:
                return "SCARD_E_NOT_TRANSACTED";
              case -0x7fefffe9:
                return "SCARD_E_READER_UNAVAILABLE";
              case -0x7fefffe8:
                return "SCARD_P_SHUTDOWN";
              case -0x7fefffe7:
                return "SCARD_E_PCI_TOO_SMALL";
              case -0x7fefffe6:
                return "SCARD_E_READER_UNSUPPORTED";
              case -0x7fefffe5:
                return "SCARD_E_DUPLICATE_READER";
              case -0x7fefffe4:
                return "SCARD_E_CARD_UNSUPPORTED";
              case -0x7fefffe3:
                return "SCARD_E_NO_SERVICE";
              case -0x7fefffe2:
                return "SCARD_E_SERVICE_STOPPED";
              case -0x7fefffe1:
                return "SCARD_E_UNEXPECTED";
              case -0x7fefffe0:
                return "SCARD_E_ICC_INSTALLATION";
              case -0x7fefffdf:
                return "SCARD_E_ICC_CREATEORDER";
              case -0x7fefffde:
                return "SCARD_E_UNSUPPORTED_FEATURE";
              case -0x7fefffdd:
                return "SCARD_E_DIR_NOT_FOUND";
              case -0x7fefffdc:
                return "SCARD_E_FILE_NOT_FOUND";
              case -0x7fefffdb:
                return "SCARD_E_NO_DIR";
              case -0x7fefffda:
                return "SCARD_E_NO_FILE";
              case -0x7fefffd9:
                return "SCARD_E_NO_ACCESS";
              case -0x7fefffd8:
                return "SCARD_E_WRITE_TOO_MANY";
              }
            }
          }
          else if (param_1 < -0x7feefbfc) {
            if (param_1 == -0x7feefbfd) {
              return "COMADMIN_E_KEYMISSING";
            }
            if (param_1 < -0x7fefff97) {
              if (param_1 == -0x7fefff98) {
                return "SCARD_W_RESET_CARD";
              }
              if (param_1 < -0x7fefffd0) {
                if (param_1 == -0x7fefffd1) {
                  return "SCARD_E_COMM_DATA_LOST";
                }
                if (param_1 == -0x7fefffd6) {
                  return "SCARD_E_INVALID_CHV";
                }
                if (param_1 == -0x7fefffd5) {
                  return "SCARD_E_UNKNOWN_RES_MNG";
                }
                if (param_1 == -0x7fefffd4) {
                  return "SCARD_E_NO_SUCH_CERTIFICATE";
                }
                if (param_1 == -0x7fefffd3) {
                  return "SCARD_E_CERTIFICATE_UNAVAILABLE";
                }
                if (param_1 == -0x7fefffd2) {
                  return "SCARD_E_NO_READERS_AVAILABLE";
                }
              }
              else {
                if (param_1 == -0x7fefffd0) {
                  return "SCARD_E_NO_KEY_CONTAINER";
                }
                if (param_1 == -0x7fefff9b) {
                  return "SCARD_W_UNSUPPORTED_CARD";
                }
                if (param_1 == -0x7fefff9a) {
                  return "SCARD_W_UNRESPONSIVE_CARD";
                }
                if (param_1 == -0x7fefff99) {
                  return "SCARD_W_UNPOWERED_CARD";
                }
              }
            }
            else if (param_1 < -0x7fefff92) {
              if (param_1 == -0x7fefff93) {
                return "SCARD_W_EOF";
              }
              if (param_1 == -0x7fefff97) {
                return "SCARD_W_REMOVED_CARD";
              }
              if (param_1 == -0x7fefff96) {
                return "SCARD_W_SECURITY_VIOLATION";
              }
              if (param_1 == -0x7fefff95) {
                return "SCARD_W_WRONG_CHV";
              }
              if (param_1 == -0x7fefff94) {
                return "SCARD_W_CHV_BLOCKED";
              }
            }
            else {
              if (param_1 == -0x7fefff92) {
                return "SCARD_W_CANCELLED_BY_USER";
              }
              if (param_1 == -0x7fefff91) {
                return "SCARD_W_CARD_NOT_AUTHENTICATED";
              }
              if (param_1 == -0x7feefbff) {
                return "COMADMIN_E_OBJECTERRORS";
              }
              if (param_1 == -0x7feefbfe) {
                return "COMADMIN_E_OBJECTINVALID";
              }
            }
          }
          else {
            switch(param_1) {
            case -0x7feefbfc:
              return "COMADMIN_E_ALREADYINSTALLED";
            case -0x7feefbf9:
              return "COMADMIN_E_APP_FILE_WRITEFAIL";
            case -0x7feefbf8:
              return "COMADMIN_E_APP_FILE_READFAIL";
            case -0x7feefbf7:
              return "COMADMIN_E_APP_FILE_VERSION";
            case -0x7feefbf6:
              return "COMADMIN_E_BADPATH";
            case -0x7feefbf5:
              return "COMADMIN_E_APPLICATIONEXISTS";
            case -0x7feefbf4:
              return "COMADMIN_E_ROLEEXISTS";
            case -0x7feefbf3:
              return "COMADMIN_E_CANTCOPYFILE";
            case -0x7feefbf1:
              return "COMADMIN_E_NOUSER";
            case -0x7feefbf0:
              return "COMADMIN_E_INVALIDUSERIDS";
            case -0x7feefbef:
              return "COMADMIN_E_NOREGISTRYCLSID";
            case -0x7feefbee:
              return "COMADMIN_E_BADREGISTRYPROGID";
            case -0x7feefbed:
              return "COMADMIN_E_AUTHENTICATIONLEVEL";
            case -0x7feefbec:
              return "COMADMIN_E_USERPASSWDNOTVALID";
            case -0x7feefbe8:
              return "COMADMIN_E_CLSIDORIIDMISMATCH";
            case -0x7feefbe7:
              return "COMADMIN_E_REMOTEINTERFACE";
            case -0x7feefbe6:
              return "COMADMIN_E_DLLREGISTERSERVER";
            case -0x7feefbe5:
              return "COMADMIN_E_NOSERVERSHARE";
            case -0x7feefbe3:
              return "COMADMIN_E_DLLLOADFAILED";
            case -0x7feefbe2:
              return "COMADMIN_E_BADREGISTRYLIBID";
            }
          }
        }
        else if (param_1 < -0x7feef9ff) {
          if (param_1 == -0x7feefa00) {
            return "COMQC_E_APPLICATION_NOT_QUEUED";
          }
          switch(param_1) {
          case -0x7feefbdd:
            return "COMADMIN_E_REGISTRARFAILED";
          case -0x7feefbdc:
            return "COMADMIN_E_COMPFILE_DOESNOTEXIST";
          case -0x7feefbdb:
            return "COMADMIN_E_COMPFILE_LOADDLLFAIL";
          case -0x7feefbda:
            return "COMADMIN_E_COMPFILE_GETCLASSOBJ";
          case -0x7feefbd9:
            return "COMADMIN_E_COMPFILE_CLASSNOTAVAIL";
          case -0x7feefbd8:
            return "COMADMIN_E_COMPFILE_BADTLB";
          case -0x7feefbd7:
            return "COMADMIN_E_COMPFILE_NOTINSTALLABLE";
          case -0x7feefbd6:
            return "COMADMIN_E_NOTCHANGEABLE";
          case -0x7feefbd5:
            return "COMADMIN_E_NOTDELETEABLE";
          case -0x7feefbd4:
            return "COMADMIN_E_SESSION";
          case -0x7feefbd3:
            return "COMADMIN_E_COMP_MOVE_LOCKED";
          case -0x7feefbd2:
            return "COMADMIN_E_COMP_MOVE_BAD_DEST";
          case -0x7feefbd0:
            return "COMADMIN_E_REGISTERTLB";
          case -0x7feefbcd:
            return "COMADMIN_E_SYSTEMAPP";
          case -0x7feefbcc:
            return "COMADMIN_E_COMPFILE_NOREGISTRAR";
          case -0x7feefbcb:
            return "COMADMIN_E_COREQCOMPINSTALLED";
          case -0x7feefbca:
            return "COMADMIN_E_SERVICENOTINSTALLED";
          case -0x7feefbc9:
            return "COMADMIN_E_PROPERTYSAVEFAILED";
          case -0x7feefbc8:
            return "COMADMIN_E_OBJECTEXISTS";
          case -0x7feefbc7:
            return "COMADMIN_E_COMPONENTEXISTS";
          case -0x7feefbc5:
            return "COMADMIN_E_REGFILE_CORRUPT";
          case -0x7feefbc4:
            return "COMADMIN_E_PROPERTY_OVERFLOW";
          case -0x7feefbc2:
            return "COMADMIN_E_NOTINREGISTRY";
          case -0x7feefbc1:
            return "COMADMIN_E_OBJECTNOTPOOLABLE";
          case -0x7feefbba:
            return "COMADMIN_E_APPLID_MATCHES_CLSID";
          case -0x7feefbb9:
            return "COMADMIN_E_ROLE_DOES_NOT_EXIST";
          case -0x7feefbb8:
            return "COMADMIN_E_START_APP_NEEDS_COMPONENTS";
          case -0x7feefbb7:
            return "COMADMIN_E_REQUIRES_DIFFERENT_PLATFORM";
          case -0x7feefbb6:
            return "COMADMIN_E_CAN_NOT_EXPORT_APP_PROXY";
          case -0x7feefbb5:
            return "COMADMIN_E_CAN_NOT_START_APP";
          case -0x7feefbb4:
            return "COMADMIN_E_CAN_NOT_EXPORT_SYS_APP";
          case -0x7feefbb3:
            return "COMADMIN_E_CANT_SUBSCRIBE_TO_COMPONENT";
          case -0x7feefbb2:
            return "COMADMIN_E_EVENTCLASS_CANT_BE_SUBSCRIBER";
          case -0x7feefbb1:
            return "COMADMIN_E_LIB_APP_PROXY_INCOMPATIBLE";
          case -0x7feefbb0:
            return "COMADMIN_E_BASE_PARTITION_ONLY";
          case -0x7feefbaf:
            return "COMADMIN_E_START_APP_DISABLED";
          case -0x7feefba9:
            return "COMADMIN_E_CAT_DUPLICATE_PARTITION_NAME";
          case -0x7feefba8:
            return "COMADMIN_E_CAT_INVALID_PARTITION_NAME";
          case -0x7feefba7:
            return "COMADMIN_E_CAT_PARTITION_IN_USE";
          case -0x7feefba6:
            return "COMADMIN_E_FILE_PARTITION_DUPLICATE_FILES";
          case -0x7feefba5:
            return "COMADMIN_E_CAT_IMPORTED_COMPONENTS_NOT_ALLOWED";
          case -0x7feefba4:
            return "COMADMIN_E_AMBIGUOUS_APPLICATION_NAME";
          case -0x7feefba3:
            return "COMADMIN_E_AMBIGUOUS_PARTITION_NAME";
          case -0x7feefb8e:
            return "COMADMIN_E_REGDB_NOTINITIALIZED";
          case -0x7feefb8d:
            return "COMADMIN_E_REGDB_NOTOPEN";
          case -0x7feefb8c:
            return "COMADMIN_E_REGDB_SYSTEMERR";
          case -0x7feefb8b:
            return "COMADMIN_E_REGDB_ALREADYRUNNING";
          case -0x7feefb80:
            return "COMADMIN_E_MIG_VERSIONNOTSUPPORTED";
          case -0x7feefb7f:
            return "COMADMIN_E_MIG_SCHEMANOTFOUND";
          case -0x7feefb7e:
            return "COMADMIN_E_CAT_BITNESSMISMATCH";
          case -0x7feefb7d:
            return "COMADMIN_E_CAT_UNACCEPTABLEBITNESS";
          case -0x7feefb7c:
            return "COMADMIN_E_CAT_WRONGAPPBITNESS";
          case -0x7feefb7b:
            return "COMADMIN_E_CAT_PAUSE_RESUME_NOT_SUPPORTED";
          case -0x7feefb7a:
            return "COMADMIN_E_CAT_SERVERFAULT";
          }
        }
        else if (param_1 < -0x7feef7ee) {
          if (param_1 == -0x7feef7ef) {
            return "COMADMIN_E_CANTRECYCLESERVICEAPPS";
          }
          if (param_1 < -0x7feef7f7) {
            if (param_1 == -0x7feef7f8) {
              return "COMADMIN_E_OBJECT_PARENT_MISSING";
            }
            if (param_1 == -0x7feef9ff) {
              return "COMQC_E_NO_QUEUEABLE_INTERFACES";
            }
            if (param_1 == -0x7feef9fe) {
              return "COMQC_E_QUEUING_SERVICE_NOT_AVAILABLE";
            }
            if (param_1 == -0x7feef9fd) {
              return "COMQC_E_NO_IPERSISTSTREAM";
            }
            if (param_1 == -0x7feef9fc) {
              return "COMQC_E_BAD_MESSAGE";
            }
            if (param_1 == -0x7feef9fb) {
              return "COMQC_E_UNAUTHENTICATED";
            }
            if (param_1 == -0x7feef9fa) {
              return "COMQC_E_UNTRUSTED_ENQUEUER";
            }
            if (param_1 == -0x7feef8ff) {
              return "MSDTC_E_DUPLICATE_RESOURCE";
            }
          }
          else {
            if (param_1 == -0x7feef7f7) {
              return "COMADMIN_E_OBJECT_DOES_NOT_EXIST";
            }
            if (param_1 == -0x7feef7f6) {
              return "COMADMIN_E_APP_NOT_RUNNING";
            }
            if (param_1 == -0x7feef7f5) {
              return "COMADMIN_E_INVALID_PARTITION";
            }
            if (param_1 == -0x7feef7f3) {
              return "COMADMIN_E_SVCAPP_NOT_POOLABLE_OR_RECYCLABLE";
            }
            if (param_1 == -0x7feef7f2) {
              return "COMADMIN_E_USER_IN_SET";
            }
            if (param_1 == -0x7feef7f1) {
              return "COMADMIN_E_CANTRECYCLELIBRARYAPPS";
            }
          }
        }
        else {
          switch(param_1) {
          case -0x7feef7ee:
            return "COMADMIN_E_PROCESSALREADYRECYCLED";
          case -0x7feef7ed:
            return "COMADMIN_E_PAUSEDPROCESSMAYNOTBERECYCLED";
          case -0x7feef7ec:
            return "COMADMIN_E_CANTMAKEINPROCSERVICE";
          case -0x7feef7eb:
            return "COMADMIN_E_PROGIDINUSEBYCLSID";
          case -0x7feef7ea:
            return "COMADMIN_E_DEFAULT_PARTITION_NOT_IN_SET";
          case -0x7feef7e9:
            return "COMADMIN_E_RECYCLEDPROCESSMAYNOTBEPAUSED";
          case -0x7feef7e8:
            return "COMADMIN_E_PARTITION_ACCESSDENIED";
          case -0x7feef7e7:
            return "COMADMIN_E_PARTITION_MSI_ONLY";
          case -0x7feef7e6:
            return "COMADMIN_E_LEGACYCOMPS_NOT_ALLOWED_IN_1_0_FORMAT";
          case -0x7feef7e5:
            return "COMADMIN_E_LEGACYCOMPS_NOT_ALLOWED_IN_NONBASE_PARTITIONS";
          case -0x7feef7e4:
            return "COMADMIN_E_COMP_MOVE_SOURCE";
          case -0x7feef7e3:
            return "COMADMIN_E_COMP_MOVE_DEST";
          case -0x7feef7e2:
            return "COMADMIN_E_COMP_MOVE_PRIVATE";
          case -0x7feef7e1:
            return "COMADMIN_E_BASEPARTITION_REQUIRED_IN_SET";
          }
        }
      }
      else if (param_1 < -0x7789fe01) {
        if (param_1 == -0x7789fe02) {
          return "DDERR_UNSUPPORTEDFORMAT";
        }
        if (param_1 < -0x7fea7c7f) {
          if (param_1 == -0x7fea7c80) {
            return "DPNERR_INVALIDINSTANCE";
          }
          if (param_1 < -0x7feafe73) {
            if (param_1 == -0x7feafe74) {
              return "DVERR_TRANSPORTNOPLAYER";
            }
            if (param_1 < -0x7feafe8c) {
              if (param_1 == -0x7feafe8d) {
                return "DVERR_ALREADYPENDING";
              }
              if (param_1 < -0x7feafed3) {
                if (param_1 == -0x7feafed4) {
                  return "DVERR_SESSIONLOST";
                }
                if (param_1 < -0x7feaff87) {
                  if (param_1 == -0x7feaff88) {
                    return "DVERR_INVALIDFLAGS";
                  }
                  if (param_1 == -0x7feef7df) {
                    return "COMADMIN_E_PRIVATE_ACCESSDENIED";
                  }
                  if (param_1 == -0x7feef7de) {
                    return "COMADMIN_E_SAFERINVALID";
                  }
                  if (param_1 == -0x7feef7dd) {
                    return "COMADMIN_E_REGISTRY_ACCESSDENIED";
                  }
                  if (param_1 == -0x7feaffe2) {
                    return "DVERR_BUFFERTOOSMALL";
                  }
                  if (param_1 == -0x7feaffb6) {
                    return "DVERR_EXCEPTION";
                  }
                }
                else {
                  if (param_1 == -0x7feaff7e) {
                    return "DVERR_INVALIDOBJECT";
                  }
                  if (param_1 == -0x7feaff79) {
                    return "DVERR_INVALIDPLAYER";
                  }
                  if (param_1 == -0x7feaff6f) {
                    return "DVERR_INVALIDGROUP";
                  }
                  if (param_1 == -0x7feaff6a) {
                    return "DVERR_INVALIDHANDLE";
                  }
                }
              }
              else if (param_1 < -0x7feafe91) {
                if (param_1 == -0x7feafe92) {
                  return "DVERR_CONNECTABORTING";
                }
                if (param_1 == -0x7feafed2) {
                  return "DVERR_NOVOICESESSION";
                }
                if (param_1 == -0x7feafe98) {
                  return "DVERR_CONNECTIONLOST";
                }
                if (param_1 == -0x7feafe97) {
                  return "DVERR_NOTINITIALIZED";
                }
                if (param_1 == -0x7feafe96) {
                  return "DVERR_CONNECTED";
                }
                if (param_1 == -0x7feafe95) {
                  return "DVERR_NOTCONNECTED";
                }
              }
              else {
                if (param_1 == -0x7feafe91) {
                  return "DVERR_NOTALLOWED";
                }
                if (param_1 == -0x7feafe90) {
                  return "DVERR_INVALIDTARGET";
                }
                if (param_1 == -0x7feafe8f) {
                  return "DVERR_TRANSPORTNOTHOST";
                }
                if (param_1 == -0x7feafe8e) {
                  return "DVERR_COMPRESSIONNOTSUPPORTED";
                }
              }
            }
            else {
              switch(param_1) {
              case -0x7feafe8c:
                return "DVERR_SOUNDINITFAILURE";
              case -0x7feafe8b:
                return "DVERR_TIMEOUT";
              case -0x7feafe8a:
                return "DVERR_CONNECTABORTED";
              case -0x7feafe89:
                return "DVERR_NO3DSOUND";
              case -0x7feafe88:
                return "DVERR_ALREADYBUFFERED";
              case -0x7feafe87:
                return "DVERR_NOTBUFFERED";
              case -0x7feafe86:
                return "DVERR_HOSTING";
              case -0x7feafe85:
                return "DVERR_NOTHOSTING";
              case -0x7feafe84:
                return "DVERR_INVALIDDEVICE";
              case -0x7feafe83:
                return "DVERR_RECORDSYSTEMERROR";
              case -0x7feafe82:
                return "DVERR_PLAYBACKSYSTEMERROR";
              case -0x7feafe81:
                return "DVERR_SENDERROR";
              case -0x7feafe80:
                return "DVERR_USERCANCEL";
              case -0x7feafe7d:
                return "DVERR_RUNSETUP";
              case -0x7feafe7c:
                return "DVERR_INCOMPATIBLEVERSION";
              case -0x7feafe79:
                return "DVERR_INITIALIZED";
              case -0x7feafe78:
                return "DVERR_NOTRANSPORT";
              case -0x7feafe77:
                return "DVERR_NOCALLBACK";
              case -0x7feafe76:
                return "DVERR_TRANSPORTNOTINIT";
              case -0x7feafe75:
                return "DVERR_TRANSPORTNOSESSION";
              }
            }
          }
          else if (param_1 < -0x7fea7e7f) {
            if (param_1 == -0x7fea7e80) {
              return "DPNERR_DOESNOTEXIST";
            }
            if (param_1 < -0x7fea7f6f) {
              if (param_1 == -0x7fea7f70) {
                return "DPNERR_ALREADYREGISTERED";
              }
              if (param_1 < -0x7fea7fbf) {
                if (param_1 == -0x7fea7fc0) {
                  return "DPNERR_ADDRESSING";
                }
                if (param_1 == -0x7feafe73) {
                  return "DVERR_USERBACK";
                }
                if (param_1 == -0x7feafe72) {
                  return "DVERR_NORECVOLAVAILABLE";
                }
                if (param_1 == -0x7feafe71) {
                  return "DVERR_INVALIDBUFFER";
                }
                if (param_1 == -0x7feafe70) {
                  return "DVERR_LOCKEDBUFFER";
                }
                if (param_1 == -0x7fea7fd0) {
                  return "DPNERR_ABORTED";
                }
              }
              else {
                if (param_1 == -0x7fea7fb0) {
                  return "DPNERR_ALREADYCLOSING";
                }
                if (param_1 == -0x7fea7fa0) {
                  return "DPNERR_ALREADYCONNECTED";
                }
                if (param_1 == -0x7fea7f90) {
                  return "DPNERR_ALREADYDISCONNECTING";
                }
                if (param_1 == -0x7fea7f80) {
                  return "DPNERR_ALREADYINITIALIZED";
                }
              }
            }
            else if (param_1 < -0x7fea7ebf) {
              if (param_1 == -0x7fea7ec0) {
                return "DPNERR_CANTLAUNCHAPPLICATION";
              }
              if (param_1 == -0x7fea7f00) {
                return "DPNERR_BUFFERTOOSMALL";
              }
              if (param_1 == -0x7fea7ef0) {
                return "DPNERR_CANNOTCANCEL";
              }
              if (param_1 == -0x7fea7ee0) {
                return "DPNERR_CANTCREATEGROUP";
              }
              if (param_1 == -0x7fea7ed0) {
                return "DPNERR_CANTCREATEPLAYER";
              }
            }
            else {
              if (param_1 == -0x7fea7eb0) {
                return "DPNERR_CONNECTING";
              }
              if (param_1 == -0x7fea7ea0) {
                return "DPNERR_CONNECTIONLOST";
              }
              if (param_1 == -0x7fea7e90) {
                return "DPNERR_CONVERSION";
              }
              if (param_1 == -0x7fea7e8b) {
                return "DPNERR_DATATOOLARGE";
              }
            }
          }
          else if (param_1 < -0x7fea7d7f) {
            if (param_1 == -0x7fea7d80) {
              return "DPNERR_INCOMPLETEADDRESS";
            }
            if (param_1 < -0x7fea7dcf) {
              if (param_1 == -0x7fea7dd0) {
                return "DPNERR_EXCEPTION";
              }
              if (param_1 == -0x7fea7e7b) {
                return "DPNERR_DPNSVRNOTAVAILABLE";
              }
              if (param_1 == -0x7fea7e70) {
                return "DPNERR_DUPLICATECOMMAND";
              }
              if (param_1 == -0x7fea7e00) {
                return "DPNERR_ENDPOINTNOTRECEIVING";
              }
              if (param_1 == -0x7fea7df0) {
                return "DPNERR_ENUMQUERYTOOLARGE";
              }
              if (param_1 == -0x7fea7de0) {
                return "DPNERR_ENUMRESPONSETOOLARGE";
              }
            }
            else {
              if (param_1 == -0x7fea7dc0) {
                return "DPNERR_GROUPNOTEMPTY";
              }
              if (param_1 == -0x7fea7db0) {
                return "DPNERR_HOSTING";
              }
              if (param_1 == -0x7fea7da0) {
                return "DPNERR_HOSTREJECTEDCONNECTION";
              }
              if (param_1 == -0x7fea7d90) {
                return "DPNERR_HOSTTERMINATEDSESSION";
              }
            }
          }
          else if (param_1 < -0x7fea7ccf) {
            if (param_1 == -0x7fea7cd0) {
              return "DPNERR_INVALIDENDPOINT";
            }
            if (param_1 == -0x7fea7d70) {
              return "DPNERR_INVALIDADDRESSFORMAT";
            }
            if (param_1 == -0x7fea7d00) {
              return "DPNERR_INVALIDAPPLICATION";
            }
            if (param_1 == -0x7fea7cf0) {
              return "DPNERR_INVALIDCOMMAND";
            }
            if (param_1 == -0x7fea7ce0) {
              return "DPNERR_INVALIDDEVICEADDRESS";
            }
          }
          else {
            if (param_1 == -0x7fea7cc0) {
              return "DPNERR_INVALIDFLAGS";
            }
            if (param_1 == -0x7fea7cb0) {
              return "DPNERR_INVALIDGROUP";
            }
            if (param_1 == -0x7fea7ca0) {
              return "DPNERR_INVALIDHANDLE";
            }
            if (param_1 == -0x7fea7c90) {
              return "DPNERR_INVALIDHOSTADDRESS";
            }
          }
        }
        else if (param_1 < -0x7789ff4b) {
          if (param_1 == -0x7789ff4c) {
            return "DDERR_NOALPHAHW";
          }
          if (param_1 < -0x7fea79ff) {
            if (param_1 == -0x7fea7a00) {
              return "DPNERR_SENDTOOLARGE";
            }
            if (param_1 < -0x7fea7b6f) {
              if (param_1 == -0x7fea7b70) {
                return "DPNERR_NOHOSTPLAYER";
              }
              if (param_1 < -0x7fea7bbf) {
                if (param_1 == -0x7fea7bc0) {
                  return "DPNERR_INVALIDSTRING";
                }
                if (param_1 == -0x7fea7c70) {
                  return "DPNERR_INVALIDINTERFACE";
                }
                if (param_1 == -0x7fea7c00) {
                  return "DPNERR_INVALIDOBJECT";
                }
                if (param_1 == -0x7fea7bf0) {
                  return "DPNERR_INVALIDPASSWORD";
                }
                if (param_1 == -0x7fea7be0) {
                  return "DPNERR_INVALIDPLAYER";
                }
                if (param_1 == -0x7fea7bd0) {
                  return "DPNERR_INVALIDPRIORITY";
                }
              }
              else {
                if (param_1 == -0x7fea7bb0) {
                  return "DPNERR_INVALIDURL";
                }
                if (param_1 == -0x7fea7ba0) {
                  return "DPNERR_INVALIDVERSION";
                }
                if (param_1 == -0x7fea7b90) {
                  return "DPNERR_NOCAPS";
                }
                if (param_1 == -0x7fea7b80) {
                  return "DPNERR_NOCONNECTION";
                }
              }
            }
            else if (param_1 < -0x7fea7aaf) {
              if (param_1 == -0x7fea7ab0) {
                return "DPNERR_NOTREGISTERED";
              }
              if (param_1 == -0x7fea7b00) {
                return "DPNERR_NOMOREADDRESSCOMPONENTS";
              }
              if (param_1 == -0x7fea7af0) {
                return "DPNERR_NORESPONSE";
              }
              if (param_1 == -0x7fea7ae0) {
                return "DPNERR_NOTALLOWED";
              }
              if (param_1 == -0x7fea7ad0) {
                return "DPNERR_NOTHOST";
              }
              if (param_1 == -0x7fea7ac0) {
                return "DPNERR_NOTREADY";
              }
            }
            else {
              if (param_1 == -0x7fea7aa0) {
                return "DPNERR_PLAYERALREADYINGROUP";
              }
              if (param_1 == -0x7fea7a90) {
                return "DPNERR_PLAYERLOST";
              }
              if (param_1 == -0x7fea7a80) {
                return "DPNERR_PLAYERNOTINGROUP";
              }
              if (param_1 == -0x7fea7a70) {
                return "DPNERR_PLAYERNOTREACHABLE";
              }
            }
          }
          else if (param_1 < -0x7789ffa5) {
            if (param_1 == -0x7789ffa6) {
              return "DDERR_HEIGHTALIGN";
            }
            if (param_1 < -0x7789fffa) {
              if (param_1 == -0x7789fffb) {
                return "DDERR_ALREADYINITIALIZED";
              }
              if (param_1 == -0x7fea79f0) {
                return "DPNERR_SESSIONFULL";
              }
              if (param_1 == -0x7fea79e0) {
                return "DPNERR_TABLEFULL";
              }
              if (param_1 == -0x7fea79d0) {
                return "DPNERR_TIMEDOUT";
              }
              if (param_1 == -0x7fea79c0) {
                return "DPNERR_UNINITIALIZED";
              }
              if (param_1 == -0x7fea79b0) {
                return "DPNERR_USERCANCEL";
              }
            }
            else {
              if (param_1 == -0x7789fff6) {
                return "DDERR_CANNOTATTACHSURFACE";
              }
              if (param_1 == -0x7789ffec) {
                return "DDERR_CANNOTDETACHSURFACE";
              }
              if (param_1 == -0x7789ffd8) {
                return "DDERR_CURRENTLYNOTAVAIL";
              }
              if (param_1 == -0x7789ffc9) {
                return "DDERR_EXCEPTION";
              }
            }
          }
          else if (param_1 < -0x7789ff7d) {
            if (param_1 == -0x7789ff7e) {
              return "DDERR_INVALIDOBJECT";
            }
            if (param_1 == -0x7789ffa1) {
              return "DDERR_INCOMPATIBLEPRIMARY";
            }
            if (param_1 == -0x7789ff9c) {
              return "DDERR_INVALIDCAPS";
            }
            if (param_1 == -0x7789ff92) {
              return "DDERR_INVALIDCLIPLIST";
            }
            if (param_1 == -0x7789ff88) {
              return "DDERR_INVALIDMODE";
            }
          }
          else {
            if (param_1 == -0x7789ff6f) {
              return "DDERR_INVALIDPIXELFORMAT";
            }
            if (param_1 == -0x7789ff6a) {
              return "DDERR_INVALIDRECT";
            }
            if (param_1 == -0x7789ff60) {
              return "DDERR_LOCKEDSURFACES";
            }
            if (param_1 == -0x7789ff56) {
              return "DDERR_NO3D";
            }
          }
        }
        else if (param_1 < -0x7789febf) {
          if (param_1 == -0x7789fec0) {
            return "DDERR_NOT8BITCOLOR";
          }
          if (param_1 < -0x7789ff0f) {
            if (param_1 == -0x7789ff10) {
              return "DDERR_NOGDI";
            }
            if (param_1 < -0x7789ff28) {
              if (param_1 == -0x7789ff29) {
                return "DDERR_NOCOLORKEY";
              }
              if (param_1 == -0x7789ff4b) {
                return "DDERR_NOSTEREOHARDWARE";
              }
              if (param_1 == -0x7789ff4a) {
                return "DDERR_NOSURFACELEFT";
              }
              if (param_1 == -0x7789ff33) {
                return "DDERR_NOCLIPLIST";
              }
              if (param_1 == -0x7789ff2e) {
                return "DDERR_NOCOLORCONVHW";
              }
              if (param_1 == -0x7789ff2c) {
                return "DDERR_NOCOOPERATIVELEVELSET";
              }
            }
            else {
              if (param_1 == -0x7789ff24) {
                return "DDERR_NOCOLORKEYHW";
              }
              if (param_1 == -0x7789ff22) {
                return "DDERR_NODIRECTDRAWSUPPORT";
              }
              if (param_1 == -0x7789ff1f) {
                return "DDERR_NOEXCLUSIVEMODE";
              }
              if (param_1 == -0x7789ff1a) {
                return "DDERR_NOFLIPHW";
              }
            }
          }
          else if (param_1 < -0x7789fee7) {
            if (param_1 == -0x7789fee8) {
              return "DDERR_NORASTEROPHW";
            }
            if (param_1 == -0x7789ff06) {
              return "DDERR_NOMIRRORHW";
            }
            if (param_1 == -0x7789ff01) {
              return "DDERR_NOTFOUND";
            }
            if (param_1 == -0x7789fefc) {
              return "DDERR_NOOVERLAYHW";
            }
            if (param_1 == -0x7789fef2) {
              return "DDERR_OVERLAPPINGRECTS";
            }
          }
          else {
            if (param_1 == -0x7789fede) {
              return "DDERR_NOROTATIONHW";
            }
            if (param_1 == -0x7789feca) {
              return "DDERR_NOSTRETCHHW";
            }
            if (param_1 == -0x7789fec4) {
              return "DDERR_NOT4BITCOLOR";
            }
            if (param_1 == -0x7789fec3) {
              return "DDERR_NOT4BITCOLORINDEX";
            }
          }
        }
        else if (param_1 < -0x7789fe65) {
          if (param_1 == -0x7789fe66) {
            return "DDERR_SURFACEALREADYATTACHED";
          }
          if (param_1 < -0x7789fe83) {
            if (param_1 == -0x7789fe84) {
              return "D3DERR_OUTOFVIDEOMEMORY";
            }
            if (param_1 == -0x7789feb6) {
              return "DDERR_NOTEXTUREHW";
            }
            if (param_1 == -0x7789feb1) {
              return "DDERR_NOVSYNCHW";
            }
            if (param_1 == -0x7789feac) {
              return "DDERR_NOZBUFFERHW";
            }
            if (param_1 == -0x7789fea2) {
              return "DDERR_NOZOVERLAYHW";
            }
            if (param_1 == -0x7789fe98) {
              return "DDERR_OUTOFCAPS";
            }
          }
          else {
            if (param_1 == -0x7789fe82) {
              return "DDERR_OVERLAYCANTCLIP";
            }
            if (param_1 == -0x7789fe80) {
              return "DDERR_OVERLAYCOLORKEYONLYONEACTIVE";
            }
            if (param_1 == -0x7789fe7d) {
              return "DDERR_PALETTEBUSY";
            }
            if (param_1 == -0x7789fe70) {
              return "DDERR_COLORKEYNOTSET";
            }
          }
        }
        else if (param_1 < -0x7789fe3d) {
          if (param_1 == -0x7789fe3e) {
            return "DDERR_SURFACELOST";
          }
          if (param_1 == -0x7789fe5c) {
            return "DDERR_SURFACEALREADYDEPENDENT";
          }
          if (param_1 == -0x7789fe52) {
            return "DDERR_SURFACEBUSY";
          }
          if (param_1 == -0x7789fe4d) {
            return "DDERR_CANTLOCKSURFACE";
          }
          if (param_1 == -0x7789fe48) {
            return "DDERR_SURFACEISOBSCURED";
          }
        }
        else {
          if (param_1 == -0x7789fe34) {
            return "DDERR_SURFACENOTATTACHED";
          }
          if (param_1 == -0x7789fe2a) {
            return "DDERR_TOOBIGHEIGHT";
          }
          if (param_1 == -0x7789fe20) {
            return "DDERR_TOOBIGSIZE";
          }
          if (param_1 == -0x7789fe16) {
            return "DDERR_TOOBIGWIDTH";
          }
        }
      }
      else if (param_1 < -0x7789fc7a) {
        if (param_1 == -0x7789fc7b) {
          return "D3DXFERR_BADVALUE";
        }
        if (param_1 + 0x7789fdf8U < 0x17d) {
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
          switch(*(undefined1 *)(param_1 + 0x77fc4e37)) {
          case 0:
            return "DDERR_UNSUPPORTEDMASK";
          case 1:
            return "DDERR_INVALIDSTREAM";
          case 2:
            return "DDERR_VERTICALBLANKINPROGRESS";
          case 3:
            return "DDERR_WASSTILLDRAWING";
          case 4:
            return "DDERR_DDSCAPSCOMPLEXREQUIRED";
          case 5:
            return "DDERR_XALIGN";
          case 6:
            return "DDERR_INVALIDDIRECTDRAWGUID";
          case 7:
            return "DDERR_DIRECTDRAWALREADYCREATED";
          case 8:
            return "DDERR_NODIRECTDRAWHW";
          case 9:
            return "DDERR_PRIMARYSURFACEALREADYEXISTS";
          case 10:
            return "DDERR_NOEMULATION";
          case 0xb:
            return "DDERR_REGIONTOOSMALL";
          case 0xc:
            return "DDERR_CLIPPERISUSINGHWND";
          case 0xd:
            return "DDERR_NOCLIPPERATTACHED";
          case 0xe:
            return "DDERR_NOHWND";
          case 0xf:
            return "DDERR_HWNDSUBCLASSED";
          case 0x10:
            return "DDERR_HWNDALREADYSET";
          case 0x11:
            return "DDERR_NOPALETTEATTACHED";
          case 0x12:
            return "DDERR_NOPALETTEHW";
          case 0x13:
            return "DDERR_BLTFASTCANTCLIP";
          case 0x14:
            return "DDERR_NOBLTHW";
          case 0x15:
            return "DDERR_NODDROPSHW";
          case 0x16:
            return "DDERR_OVERLAYNOTVISIBLE";
          case 0x17:
            return "DDERR_NOOVERLAYDEST";
          case 0x18:
            return "DDERR_INVALIDPOSITION";
          case 0x19:
            return "DDERR_NOTAOVERLAYSURFACE";
          case 0x1a:
            return "DDERR_EXCLUSIVEMODEALREADYSET";
          case 0x1b:
            return "DDERR_NOTFLIPPABLE";
          case 0x1c:
            return "DDERR_CANTDUPLICATE";
          case 0x1d:
            return "DDERR_NOTLOCKED";
          case 0x1e:
            return "DDERR_CANTCREATEDC";
          case 0x1f:
            return "DDERR_NODC";
          case 0x20:
            return "DDERR_WRONGMODE";
          case 0x21:
            return "DDERR_IMPLICITLYCREATED";
          case 0x22:
            return "DDERR_NOTPALETTIZED";
          case 0x23:
            return "DDERR_UNSUPPORTEDMODE";
          case 0x24:
            return "DDERR_NOMIPMAPHW";
          case 0x25:
            return "DDERR_INVALIDSURFACETYPE";
          case 0x26:
            return "DDERR_NOOPTIMIZEHW";
          case 0x27:
            return "DDERR_NOTLOADED";
          case 0x28:
            return "DDERR_NOFOCUSWINDOW";
          case 0x29:
            return "DDERR_NOTONMIPMAPSUBLEVEL";
          case 0x2a:
            return "DDERR_DCALREADYCREATED";
          case 0x2b:
            return "DDERR_NONONLOCALVIDMEM";
          case 0x2c:
            return "DDERR_CANTPAGELOCK";
          case 0x2d:
            return "DDERR_CANTPAGEUNLOCK";
          case 0x2e:
            return "DDERR_NOTPAGELOCKED";
          case 0x2f:
            return "DDERR_MOREDATA";
          case 0x30:
            return "DDERR_EXPIRED";
          case 0x31:
            return "DDERR_TESTFINISHED";
          case 0x32:
            return "DDERR_NEWMODE";
          case 0x33:
            return "DDERR_D3DNOTINITIALIZED";
          case 0x34:
            return "DDERR_VIDEONOTACTIVE";
          case 0x35:
            return "DDERR_NOMONITORINFORMATION";
          case 0x36:
            return "DDERR_NODRIVERSUPPORT";
          case 0x37:
            return "DDERR_DEVICEDOESNTOWNSURFACE";
          case 0x38:
            return "DXFILEERR_BADOBJECT";
          case 0x39:
            return "DXFILEERR_BADVALUE";
          case 0x3a:
            return "DXFILEERR_BADTYPE";
          case 0x3b:
            return "DXFILEERR_BADSTREAMHANDLE";
          case 0x3c:
            return "DXFILEERR_BADALLOC";
          case 0x3d:
            return "DXFILEERR_NOTFOUND";
          case 0x3e:
            return "DXFILEERR_NOTDONEYET";
          case 0x3f:
            return "DXFILEERR_FILENOTFOUND";
          case 0x40:
            return "DXFILEERR_RESOURCENOTFOUND";
          case 0x41:
            return "DXFILEERR_URLNOTFOUND";
          case 0x42:
            return "DXFILEERR_BADRESOURCE";
          case 0x43:
            return "DXFILEERR_BADFILETYPE";
          case 0x44:
            return "DXFILEERR_BADFILEVERSION";
          case 0x45:
            return "DXFILEERR_BADFILEFLOATSIZE";
          case 0x46:
            return "DXFILEERR_BADFILECOMPRESSIONTYPE";
          case 0x47:
            return "DXFILEERR_BADFILE";
          case 0x48:
            return "DXFILEERR_PARSEERROR";
          case 0x49:
            return "DXFILEERR_NOTEMPLATE";
          case 0x4a:
            return "DXFILEERR_BADARRAYSIZE";
          case 0x4b:
            return "DXFILEERR_BADDATAREFERENCE";
          case 0x4c:
            return "DXFILEERR_INTERNALERROR";
          case 0x4d:
            return "DXFILEERR_NOMOREOBJECTS";
          case 0x4e:
            return "DXFILEERR_BADINTRINSICS";
          case 0x4f:
            return "DXFILEERR_NOMORESTREAMHANDLES";
          case 0x50:
            return "DXFILEERR_NOMOREDATA";
          case 0x51:
            return "DXFILEERR_BADCACHEFILE";
          case 0x52:
            return "DXFILEERR_NOINTERNET";
          case 0x53:
            return "D3DXFERR_BADOBJECT";
          }
        }
      }
      else if (param_1 < -0x7789f7e7) {
        if (param_1 == -0x7789f7e8) {
          return "D3DERR_WRONGTEXTUREFORMAT";
        }
        switch(param_1) {
        case -0x7789fc7a:
          return "D3DXFERR_BADTYPE";
        case -0x7789fc79:
          return "D3DXFERR_NOTFOUND";
        case -0x7789fc78:
          return "D3DXFERR_NOTDONEYET";
        case -0x7789fc77:
          return "D3DXFERR_FILENOTFOUND";
        case -0x7789fc76:
          return "D3DXFERR_RESOURCENOTFOUND";
        case -0x7789fc75:
          return "D3DXFERR_BADRESOURCE";
        case -0x7789fc74:
          return "D3DXFERR_BADFILETYPE";
        case -0x7789fc73:
          return "D3DXFERR_BADFILEVERSION";
        case -0x7789fc72:
          return "D3DXFERR_BADFILEFLOATSIZE";
        case -0x7789fc71:
          return "D3DXFERR_BADFILE";
        case -0x7789fc70:
          return "D3DXFERR_PARSEERROR";
        case -0x7789fc6f:
          return "D3DXFERR_BADARRAYSIZE";
        case -0x7789fc6e:
          return "D3DXFERR_BADDATAREFERENCE";
        case -0x7789fc6d:
          return "D3DXFERR_NOMOREOBJECTS";
        case -0x7789fc6c:
          return "D3DXFERR_NOMOREDATA";
        case -0x7789fc6b:
          return "D3DXFERR_BADCACHEFILE";
        }
      }
      else if (param_1 < -0x7789f799) {
        if (param_1 == -0x7789f79a) {
          return "D3DERR_NOTFOUND";
        }
        switch(param_1) {
        case -0x7789f7e7:
          return "D3DERR_UNSUPPORTEDCOLOROPERATION";
        case -0x7789f7e6:
          return "D3DERR_UNSUPPORTEDCOLORARG";
        case -0x7789f7e5:
          return "D3DERR_UNSUPPORTEDALPHAOPERATION";
        case -0x7789f7e4:
          return "D3DERR_UNSUPPORTEDALPHAARG";
        case -0x7789f7e3:
          return "D3DERR_TOOMANYOPERATIONS";
        case -0x7789f7e2:
          return "D3DERR_CONFLICTINGTEXTUREFILTER";
        case -0x7789f7e1:
          return "D3DERR_UNSUPPORTEDFACTORVALUE";
        case -0x7789f7df:
          return "D3DERR_CONFLICTINGRENDERSTATE";
        case -0x7789f7de:
          return "D3DERR_UNSUPPORTEDTEXTUREFILTER";
        case -0x7789f7da:
          return "D3DERR_CONFLICTINGTEXTUREPALETTE";
        case -0x7789f7d9:
          return "D3DERR_DRIVERINTERNALERROR";
        }
      }
      else if (param_1 < -0x7787ff41) {
        if (param_1 == -0x7787ff42) {
          return "DSERR_DS8_REQUIRED";
        }
        if (param_1 < -0x7789f4a5) {
          if (param_1 == -0x7789f4a6) {
            return "D3DXERR_LOADEDMESHASNODATA";
          }
          if (param_1 < -0x7789f792) {
            if (param_1 == -0x7789f793) {
              return "D3DERR_DRIVERINVALIDCALL";
            }
            if (param_1 == -0x7789f799) {
              return "D3DERR_MOREDATA";
            }
            if (param_1 == -0x7789f798) {
              return "D3DERR_DEVICELOST";
            }
            if (param_1 == -0x7789f797) {
              return "D3DERR_DEVICENOTRESET";
            }
            if (param_1 == -0x7789f796) {
              return "D3DERR_NOTAVAILABLE";
            }
            if (param_1 == -0x7789f795) {
              return "D3DERR_INVALIDDEVICE";
            }
            if (param_1 == -0x7789f794) {
              return "D3DERR_INVALIDCALL";
            }
          }
          else {
            if (param_1 == -0x7789f4ac) {
              return "D3DXERR_CANNOTMODIFYINDEXBUFFER";
            }
            if (param_1 == -0x7789f4ab) {
              return "D3DXERR_INVALIDMESH";
            }
            if (param_1 == -0x7789f4aa) {
              return "D3DXERR_CANNOTATTRSORT";
            }
            if (param_1 == -0x7789f4a9) {
              return "D3DXERR_SKINNINGNOTSUPPORTED";
            }
            if (param_1 == -0x7789f4a8) {
              return "D3DXERR_TOOMANYINFLUENCES";
            }
            if (param_1 == -0x7789f4a7) {
              return "D3DXERR_INVALIDDATA";
            }
          }
        }
        else if (param_1 < -0x7787ff9b) {
          if (param_1 == -0x7787ff9c) {
            return "DSERR_BADFORMAT";
          }
          if (param_1 == -0x7789f4a5) {
            return "D3DXERR_DUPLICATENAMEDFRAGMENT";
          }
          if (param_1 == -0x7789f4a4) {
            return "D3DXERR_CANNOTREMOVELASTITEM";
          }
          if (param_1 == -0x7787fff6) {
            return "DSERR_ALLOCATED";
          }
          if (param_1 == -0x7787ffe2) {
            return "DSERR_CONTROLUNAVAIL";
          }
          if (param_1 == -0x7787ffce) {
            return "DSERR_INVALIDCALL";
          }
          if (param_1 == -0x7787ffba) {
            return "DSERR_PRIOLEVELNEEDED";
          }
        }
        else {
          if (param_1 == -0x7787ff88) {
            return "DSERR_NODRIVER";
          }
          if (param_1 == -0x7787ff7e) {
            return "DSERR_ALREADYINITIALIZED";
          }
          if (param_1 == -0x7787ff6a) {
            return "DSERR_BUFFERLOST";
          }
          if (param_1 == -0x7787ff60) {
            return "DSERR_OTHERAPPHASPRIO";
          }
          if (param_1 == -0x7787ff56) {
            return "DSERR_UNINITIALIZED";
          }
          if (param_1 == -0x7787ff4c) {
            return "DSERR_BUFFERTOOSMALL";
          }
        }
      }
      else if (param_1 < -0x7787eeea) {
        if (param_1 == -0x7787eeeb) {
          return "DMUS_E_CANNOTSEEK";
        }
        if (param_1 < -0x7787eefa) {
          if (param_1 == -0x7787eefb) {
            return "DMUS_E_BUFFERNOTSET";
          }
          if (param_1 == -0x7787ff38) {
            return "DSERR_SENDLOOP";
          }
          if (param_1 == -0x7787ff2e) {
            return "DSERR_BADSENDBUFFERGUID";
          }
          if (param_1 == -0x7787eeff) {
            return "DMUS_E_DRIVER_FAILED";
          }
          if (param_1 == -0x7787eefe) {
            return "DMUS_E_PORTS_OPEN";
          }
          if (param_1 == -0x7787eefd) {
            return "DMUS_E_DEVICE_IN_USE";
          }
          if (param_1 == -0x7787eefc) {
            return "DMUS_E_INSUFFICIENTBUFFER";
          }
        }
        else {
          if (param_1 == -0x7787eefa) {
            return "DMUS_E_BUFFERNOTAVAILABLE";
          }
          if (param_1 == -0x7787eef8) {
            return "DMUS_E_NOTADLSCOL";
          }
          if (param_1 == -0x7787eef7) {
            return "DMUS_E_INVALIDOFFSET";
          }
          if (param_1 == -0x7787eeef) {
            return "DMUS_E_ALREADY_LOADED";
          }
          if (param_1 == -0x7787eeed) {
            return "DMUS_E_INVALIDPOS";
          }
          if (param_1 == -0x7787eeec) {
            return "DMUS_E_INVALIDPATCH";
          }
        }
      }
      else {
        switch(param_1) {
        case -0x7787eeea:
          return "DMUS_E_CANNOTWRITE";
        case -0x7787eee9:
          return "DMUS_E_CHUNKNOTFOUND";
        case -0x7787eee7:
          return "DMUS_E_INVALID_DOWNLOADID";
        case -0x7787eee0:
          return "DMUS_E_NOT_DOWNLOADED_TO_PORT";
        case -0x7787eedf:
          return "DMUS_E_ALREADY_DOWNLOADED";
        case -0x7787eede:
          return "DMUS_E_UNKNOWN_PROPERTY";
        case -0x7787eedd:
          return "DMUS_E_SET_UNSUPPORTED";
        case -0x7787eedc:
          return "DMUS_E_GET_UNSUPPORTED";
        case -0x7787eedb:
          return "DMUS_E_NOTMONO";
        case -0x7787eeda:
          return "DMUS_E_BADARTICULATION";
        case -0x7787eed9:
          return "DMUS_E_BADINSTRUMENT";
        case -0x7787eed8:
          return "DMUS_E_BADWAVELINK";
        case -0x7787eed7:
          return "DMUS_E_NOARTICULATION";
        }
      }
    }
    else if (param_1 < -0x7787ee8f) {
      if (param_1 == -0x7787ee90) {
        return "DMUS_E_NO_MASTER_CLOCK";
      }
      switch(param_1) {
      case -0x7787eed5:
        return "DMUS_E_BADWAVE";
      case -0x7787eed4:
        return "DMUS_E_BADOFFSETTABLE";
      case -0x7787eed3:
        return "DMUS_E_UNKNOWNDOWNLOAD";
      case -0x7787eed2:
        return "DMUS_E_NOSYNTHSINK";
      case -0x7787eed1:
        return "DMUS_E_ALREADYOPEN";
      case -0x7787eed0:
        return "DMUS_E_ALREADYCLOSED";
      case -0x7787eecf:
        return "DMUS_E_SYNTHNOTCONFIGURED";
      case -0x7787eece:
        return "DMUS_E_SYNTHACTIVE";
      case -0x7787eecd:
        return "DMUS_E_CANNOTREAD";
      case -0x7787eecc:
        return "DMUS_E_DMUSIC_RELEASED";
      case -0x7787eecb:
        return "DMUS_E_BUFFER_EMPTY";
      case -0x7787eeca:
        return "DMUS_E_BUFFER_FULL";
      case -0x7787eec9:
        return "DMUS_E_PORT_NOT_CAPTURE";
      case -0x7787eec8:
        return "DMUS_E_PORT_NOT_RENDER";
      case -0x7787eec7:
        return "DMUS_E_DSOUND_NOT_SET";
      case -0x7787eec6:
        return "DMUS_E_ALREADY_ACTIVATED";
      case -0x7787eec5:
        return "DMUS_E_INVALIDBUFFER";
      case -0x7787eec4:
        return "DMUS_E_WAVEFORMATNOTSUPPORTED";
      case -0x7787eec3:
        return "DMUS_E_SYNTHINACTIVE";
      case -0x7787eec2:
        return "DMUS_E_DSOUND_ALREADY_SET";
      case -0x7787eec1:
        return "DMUS_E_INVALID_EVENT";
      case -0x7787eeb0:
        return "DMUS_E_UNSUPPORTED_STREAM";
      case -0x7787eeaf:
        return "DMUS_E_ALREADY_INITED";
      case -0x7787eeae:
        return "DMUS_E_INVALID_BAND";
      case -0x7787eeab:
        return "DMUS_E_TRACK_HDR_NOT_FIRST_CK";
      case -0x7787eeaa:
        return "DMUS_E_TOOL_HDR_NOT_FIRST_CK";
      case -0x7787eea9:
        return "DMUS_E_INVALID_TRACK_HDR";
      case -0x7787eea8:
        return "DMUS_E_INVALID_TOOL_HDR";
      case -0x7787eea7:
        return "DMUS_E_ALL_TOOLS_FAILED";
      case -0x7787eea0:
        return "DMUS_E_ALL_TRACKS_FAILED";
      case -0x7787ee9f:
        return "DSERR_OBJECTNOTFOUND";
      case -0x7787ee9e:
        return "DMUS_E_NOT_INIT";
      case -0x7787ee9d:
        return "DMUS_E_TYPE_DISABLED";
      case -0x7787ee9c:
        return "DMUS_E_TYPE_UNSUPPORTED";
      case -0x7787ee9b:
        return "DMUS_E_TIME_PAST";
      case -0x7787ee9a:
        return "DMUS_E_TRACK_NOT_FOUND";
      case -0x7787ee99:
        return "DMUS_E_TRACK_NO_CLOCKTIME_SUPPORT";
      }
    }
    else if (param_1 < 0x429) {
      if (param_1 == 0x428) {
LAB_0071cc02:
        return "ERROR_EXCEPTION_IN_SERVICE";
      }
      if (param_1 < 0x6c) {
        if (param_1 == 0x6b) {
LAB_0071c4f8:
          return "ERROR_DISK_CHANGE";
        }
        if (param_1 < -0x3788f426) {
          if (param_1 == -0x3788f427) {
            return "D3DXERR_COLORDEPTHTOOLOW";
          }
          if (param_1 < -0x7787edd4) {
            if (param_1 == -0x7787edd5) {
              return "DMUS_E_AUDIOPATH_NOPORT";
            }
            switch(param_1) {
            case -0x7787ee80:
              return "DMUS_E_LOADER_NOCLASSID";
            case -0x7787ee7f:
              return "DMUS_E_LOADER_BADPATH";
            case -0x7787ee7e:
              return "DMUS_E_LOADER_FAILEDOPEN";
            case -0x7787ee7d:
              return "DMUS_E_LOADER_FORMATNOTSUPPORTED";
            case -0x7787ee7c:
              return "DMUS_E_LOADER_FAILEDCREATE";
            case -0x7787ee7b:
              return "DMUS_E_LOADER_OBJECTNOTFOUND";
            case -0x7787ee7a:
              return "DMUS_E_LOADER_NOFILENAME";
            case -0x7787ee00:
              return "DMUS_E_INVALIDFILE";
            case -0x7787edff:
              return "DMUS_E_ALREADY_EXISTS";
            case -0x7787edfe:
              return "DMUS_E_OUT_OF_RANGE";
            case -0x7787edfd:
              return "DMUS_E_SEGMENT_INIT_FAILED";
            case -0x7787edfc:
              return "DMUS_E_ALREADY_SENT";
            case -0x7787edfb:
              return "DMUS_E_CANNOT_FREE";
            case -0x7787edfa:
              return "DMUS_E_CANNOT_OPEN_PORT";
            case -0x7787edf9:
              return "DMUS_E_CANNOT_CONVERT";
            case -0x7787edf0:
              return "DMUS_E_DESCEND_CHUNK_FAIL";
            case -0x7787edef:
              return "DMUS_E_NOT_LOADED";
            case -0x7787eded:
              return "DMUS_E_SCRIPT_LANGUAGE_INCOMPATIBLE";
            case -0x7787edec:
              return "DMUS_E_SCRIPT_UNSUPPORTED_VARTYPE";
            case -0x7787edeb:
              return "DMUS_E_SCRIPT_ERROR_IN_SCRIPT";
            case -0x7787edea:
              return "DMUS_E_SCRIPT_CANTLOAD_OLEAUT32";
            case -0x7787ede9:
              return "DMUS_E_SCRIPT_LOADSCRIPT_ERROR";
            case -0x7787ede8:
              return "DMUS_E_SCRIPT_INVALID_FILE";
            case -0x7787ede7:
              return "DMUS_E_INVALID_SCRIPTTRACK";
            case -0x7787ede6:
              return "DMUS_E_SCRIPT_VARIABLE_NOT_FOUND";
            case -0x7787ede5:
              return "DMUS_E_SCRIPT_ROUTINE_NOT_FOUND";
            case -0x7787ede4:
              return "DMUS_E_SCRIPT_CONTENT_READONLY";
            case -0x7787ede3:
              return "DMUS_E_SCRIPT_NOT_A_REFERENCE";
            case -0x7787ede2:
              return "DMUS_E_SCRIPT_VALUE_NOT_SUPPORTED";
            case -0x7787ede0:
              return "DMUS_E_INVALID_SEGMENTTRIGGERTRACK";
            case -0x7787eddf:
              return "DMUS_E_INVALID_LYRICSTRACK";
            case -0x7787edde:
              return "DMUS_E_INVALID_PARAMCONTROLTRACK";
            case -0x7787eddd:
              return "DMUS_E_AUDIOVBSCRIPT_SYNTAXERROR";
            case -0x7787eddc:
              return "DMUS_E_AUDIOVBSCRIPT_RUNTIMEERROR";
            case -0x7787eddb:
              return "DMUS_E_AUDIOVBSCRIPT_OPERATIONFAILURE";
            case -0x7787edda:
              return "DMUS_E_AUDIOPATHS_NOT_VALID";
            case -0x7787edd9:
              return "DMUS_E_AUDIOPATHS_IN_USE";
            case -0x7787edd8:
              return "DMUS_E_NO_AUDIOPATH_CONFIG";
            case -0x7787edd7:
              return "DMUS_E_AUDIOPATH_INACTIVE";
            case -0x7787edd6:
              return "DMUS_E_AUDIOPATH_NOBUFFER";
            }
          }
          else if (param_1 < -0x3788f43a) {
            if (param_1 == -0x3788f43b) {
              return "D3DXERR_INITFAILED";
            }
            if (param_1 < -0x3788f444) {
              if (param_1 == -0x3788f445) {
                return "D3DXERR_NODIRECTDRAWAVAILABLE";
              }
              if (param_1 < -0x3ff6fffe) {
                if (param_1 == -0x3ff6ffff) {
                  return "ERROR_AUDITING_DISABLED";
                }
                if (param_1 == -0x7787edd4) {
                  return "DMUS_E_NO_AUDIOPATH";
                }
                if (param_1 == -0x7787edd3) {
                  return "DMUS_E_INVALIDCHUNK";
                }
                if (param_1 == -0x7787edd2) {
                  return "DMUS_E_AUDIOPATH_NOGLOBALFXBUFFER";
                }
                if (param_1 == -0x7787edd1) {
                  return "DMUS_E_INVALID_CONTAINER_OBJECT";
                }
              }
              else {
                if (param_1 == -0x3ff6fffe) {
                  return "ERROR_ALL_SIDS_FILTERED";
                }
                if (param_1 == -0x3788f448) {
                  return "D3DXERR_NOMEMORY";
                }
                if (param_1 == -0x3788f447) {
                  return "D3DXERR_NULLPOINTER";
                }
                if (param_1 == -0x3788f446) {
                  return "D3DXERR_INVALIDD3DXDEVICEINDEX";
                }
              }
            }
            else {
              switch(param_1) {
              case -0x3788f444:
                return "D3DXERR_NODIRECT3DAVAILABLE";
              case -0x3788f443:
                return "D3DXERR_NODIRECT3DDEVICEAVAILABLE";
              case -0x3788f442:
                return "D3DXERR_NOPRIMARYAVAILABLE";
              case -0x3788f441:
                return "D3DXERR_NOZBUFFERAVAILABLE";
              case -0x3788f440:
                return "D3DXERR_NOBACKBUFFERAVAILABLE";
              case -0x3788f43f:
                return "D3DXERR_COULDNTUPDATECAPS";
              case -0x3788f43e:
                return "D3DXERR_NOZBUFFER";
              case -0x3788f43d:
                return "D3DXERR_INVALIDMODE";
              case -0x3788f43c:
                return "D3DXERR_INVALIDPARAMETER";
              }
            }
          }
          else {
            switch(param_1) {
            case -0x3788f43a:
              return "D3DXERR_STARTUPFAILED";
            case -0x3788f439:
              return "D3DXERR_D3DXNOTSTARTEDYET";
            case -0x3788f438:
              return "D3DXERR_NOTINITIALIZED";
            case -0x3788f437:
              return "D3DXERR_FAILEDDRAWTEXT";
            case -0x3788f436:
              return "D3DXERR_BADD3DXCONTEXT";
            case -0x3788f435:
              return "D3DXERR_CAPSNOTSUPPORTED";
            case -0x3788f434:
              return "D3DXERR_UNSUPPORTEDFILEFORMAT";
            case -0x3788f433:
              return "D3DXERR_IFLERROR";
            case -0x3788f432:
              return "D3DXERR_FAILEDGETCAPS";
            case -0x3788f431:
              return "D3DXERR_CANNOTRESIZEFULLSCREEN";
            case -0x3788f430:
              return "D3DXERR_CANNOTRESIZENONWINDOWED";
            case -0x3788f42f:
              return "D3DXERR_FRONTBUFFERALREADYEXISTS";
            case -0x3788f42e:
              return "D3DXERR_FULLSCREENPRIMARYEXISTS";
            case -0x3788f42d:
              return "D3DXERR_GETDCFAILED";
            case -0x3788f42c:
              return "D3DXERR_BITBLTFAILED";
            case -0x3788f42b:
              return "D3DXERR_NOTEXTURE";
            case -0x3788f42a:
              return "D3DXERR_MIPLEVELABSENT";
            case -0x3788f429:
              return "D3DXERR_SURFACENOTPALETTED";
            case -0x3788f428:
              return "D3DXERR_ENUMFORMATSFAILED";
            }
          }
        }
        else if (param_1 < 0x28) {
          if (param_1 == 0x27) goto LAB_0071c2dd;
          if (param_1 < 0x12) {
            if (param_1 == 0x11) goto LAB_0071c202;
            if (param_1 < 8) {
              if (param_1 == 7) goto LAB_0071c18b;
              if (param_1 < 3) {
                if (param_1 == 2) goto LAB_00717ec4;
                if (param_1 == -0x3788f426) {
                  return "D3DXERR_INVALIDFILEFORMAT";
                }
                if (param_1 == -0x3788f425) {
                  return "D3DXERR_NOMATCHFOUND";
                }
                if (param_1 == 0) {
                  return "S_OK";
                }
                if (param_1 == 1) {
                  return "S_FALSE";
                }
              }
              else {
                if (param_1 == 3) goto LAB_0071c181;
                if (param_1 == 4) goto LAB_0071c177;
                if (param_1 == 5) {
                  return "ERROR_ACCESS_DENIED";
                }
                if (param_1 == 6) {
                  return "ERROR_INVALID_HANDLE";
                }
              }
            }
            else {
              switch(param_1) {
              case 8:
                goto LAB_0071c1a8;
              case 9:
                goto LAB_0071c1b2;
              case 10:
                goto LAB_0071c1bc;
              case 0xb:
                goto LAB_0071c1c6;
              case 0xc:
                goto LAB_0071c1d0;
              case 0xd:
                goto LAB_0071c1da;
              case 0xe:
                return "ERROR_OUTOFMEMORY";
              case 0xf:
                goto LAB_0071c1ee;
              case 0x10:
                goto LAB_0071c1f8;
              }
            }
          }
          else {
            switch(param_1) {
            case 0x12:
              goto LAB_0071c21f;
            case 0x13:
              goto LAB_0071c229;
            case 0x14:
              goto LAB_0071c233;
            case 0x15:
              goto LAB_0071c23d;
            case 0x16:
              goto LAB_0071c247;
            case 0x17:
              goto LAB_0071c251;
            case 0x18:
              goto LAB_0071c25b;
            case 0x19:
              goto LAB_0071c265;
            case 0x1a:
              goto LAB_0071c26f;
            case 0x1b:
              goto LAB_0071c279;
            case 0x1c:
              goto LAB_0071c283;
            case 0x1d:
              goto LAB_0071c28d;
            case 0x1e:
              goto LAB_0071c297;
            case 0x1f:
              goto LAB_0071c2a1;
            case 0x20:
              goto LAB_0071c2ab;
            case 0x21:
              goto LAB_0071c2b5;
            case 0x22:
              goto LAB_0071c2bf;
            case 0x24:
              goto code_r0x0071c2c9;
            case 0x26:
              goto code_r0x0071c2d3;
            }
          }
        }
        else if (param_1 < 0x46) {
          if (param_1 == 0x45) goto LAB_0071c3c7;
          switch(param_1) {
          case 0x32:
            goto LAB_0071c309;
          case 0x33:
            goto LAB_0071c313;
          case 0x34:
            goto LAB_0071c31d;
          case 0x35:
            goto LAB_0071c327;
          case 0x36:
            goto LAB_0071c331;
          case 0x37:
            goto LAB_0071c33b;
          case 0x38:
            goto LAB_0071c345;
          case 0x39:
            goto LAB_0071c34f;
          case 0x3a:
            goto LAB_0071c359;
          case 0x3b:
            goto LAB_0071c363;
          case 0x3c:
            goto LAB_0071c36d;
          case 0x3d:
            goto LAB_0071c377;
          case 0x3e:
            goto LAB_0071c381;
          case 0x3f:
            goto LAB_0071c38b;
          case 0x40:
            goto LAB_0071c395;
          case 0x41:
            goto LAB_0071c39f;
          case 0x42:
            goto LAB_0071c3a9;
          case 0x43:
            goto LAB_0071c3b3;
          case 0x44:
            goto LAB_0071c3bd;
          }
        }
        else if (param_1 < 0x58) {
          if (param_1 == 0x57) {
            return "ERROR_INVALID_PARAMETER";
          }
          if (param_1 < 0x53) {
            if (param_1 == 0x52) goto LAB_0071c423;
            if (param_1 == 0x46) goto LAB_0071c419;
            if (param_1 == 0x47) goto LAB_0071c40f;
            if (param_1 == 0x48) goto LAB_0071c405;
            if (param_1 == 0x50) goto code_r0x0071c3fb;
          }
          else {
            if (param_1 == 0x53) goto LAB_0071c45d;
            if (param_1 == 0x54) goto LAB_0071c453;
            if (param_1 == 0x55) goto LAB_0071c449;
            if (param_1 == 0x56) goto code_r0x0071c43f;
          }
        }
        else if (param_1 < 0x67) {
          if (param_1 == 0x66) goto LAB_0071c4b4;
          if (param_1 == 0x58) goto LAB_0071c4aa;
          if (param_1 == 0x59) goto LAB_0071c4a0;
          if (param_1 == 100) goto LAB_0071c496;
          if (param_1 == 0x65) goto code_r0x0071c48c;
        }
        else {
          if (param_1 == 0x67) goto LAB_0071c4ee;
          if (param_1 == 0x68) goto LAB_0071c4e4;
          if (param_1 == 0x69) goto LAB_0071c4da;
          if (param_1 == 0x6a) goto code_r0x0071c4d0;
        }
      }
      else if (param_1 < 0xf1) {
        if (param_1 == 0xf0) goto LAB_0071c8d4;
        switch(param_1) {
        case 0x6c:
          goto LAB_0071c528;
        case 0x6d:
          goto LAB_0071c532;
        case 0x6e:
          goto LAB_0071c53c;
        case 0x6f:
          goto LAB_0071c546;
        case 0x70:
          goto LAB_0071c550;
        case 0x71:
          goto LAB_0071c55a;
        case 0x72:
          goto LAB_0071c564;
        case 0x75:
          goto LAB_0071c56e;
        case 0x76:
          goto LAB_0071c578;
        case 0x77:
          goto LAB_0071c582;
        case 0x78:
          goto LAB_0071c58c;
        case 0x79:
          goto LAB_0071c596;
        case 0x7a:
          goto LAB_0071c5a0;
        case 0x7b:
          goto LAB_0071c5aa;
        case 0x7c:
          goto LAB_0071c5b4;
        case 0x7d:
          goto LAB_0071c5be;
        case 0x7e:
          goto LAB_0071c5c8;
        case 0x7f:
          goto LAB_0071c5d2;
        case 0x80:
          goto LAB_0071c5dc;
        case 0x81:
          goto LAB_0071c5e6;
        case 0x82:
          goto LAB_0071c5f0;
        case 0x83:
          goto LAB_0071c5fa;
        case 0x84:
          goto LAB_0071c604;
        case 0x85:
          goto LAB_0071c60e;
        case 0x86:
          goto LAB_0071c618;
        case 0x87:
          goto LAB_0071c622;
        case 0x88:
          goto LAB_0071c62c;
        case 0x89:
          goto LAB_0071c636;
        case 0x8a:
          goto LAB_0071c640;
        case 0x8b:
          goto LAB_0071c64a;
        case 0x8c:
          goto LAB_0071c654;
        case 0x8d:
          goto LAB_0071c65e;
        case 0x8e:
          goto LAB_0071c668;
        case 0x8f:
          goto LAB_0071c672;
        case 0x90:
          goto LAB_0071c67c;
        case 0x91:
          goto LAB_0071c686;
        case 0x92:
          goto LAB_0071c690;
        case 0x93:
          goto LAB_0071c69a;
        case 0x94:
          goto LAB_0071c6a4;
        case 0x95:
          goto LAB_0071c6ae;
        case 0x96:
          goto LAB_0071c6b8;
        case 0x97:
          goto LAB_0071c6c2;
        case 0x98:
          goto LAB_0071c6cc;
        case 0x99:
          goto LAB_0071c6d6;
        case 0x9a:
          goto LAB_0071c6e0;
        case 0x9b:
          goto LAB_0071c6ea;
        case 0x9c:
          goto LAB_0071c6f4;
        case 0x9d:
          goto LAB_0071c6fe;
        case 0x9e:
          goto LAB_0071c708;
        case 0x9f:
          goto LAB_0071c712;
        case 0xa0:
          goto LAB_0071c71c;
        case 0xa1:
          goto LAB_0071c726;
        case 0xa2:
          goto LAB_0071c730;
        case 0xa4:
          goto code_r0x0071c73a;
        case 0xa7:
          goto code_r0x0071c744;
        case 0xaa:
          goto code_r0x0071c74e;
        case 0xad:
          goto code_r0x0071c758;
        case 0xae:
          goto LAB_0071c762;
        case 0xb4:
          goto code_r0x0071c76c;
        case 0xb6:
          goto code_r0x0071c776;
        case 0xb7:
          goto code_r0x0071c780;
        case 0xba:
          goto code_r0x0071c78a;
        case 0xbb:
          goto code_r0x0071c794;
        case 0xbc:
          goto code_r0x0071c79e;
        case 0xbd:
          goto LAB_0071c7a8;
        case 0xbe:
          goto LAB_0071c7b2;
        case 0xbf:
          goto LAB_0071c7bc;
        case 0xc0:
          goto LAB_0071c7c6;
        case 0xc1:
          goto LAB_0071c7d0;
        case 0xc2:
          goto LAB_0071c7da;
        case 0xc3:
          goto LAB_0071c7e4;
        case 0xc4:
          goto LAB_0071c7ee;
        case 0xc5:
          goto LAB_0071c7f8;
        case 0xc6:
          goto LAB_0071c802;
        case 199:
          goto LAB_0071c80c;
        case 200:
          return "ERROR_RING2SEG_MUST_BE_MOVABLE";
        case 0xc9:
          return "ERROR_RELOC_CHAIN_XEEDS_SEGLIM";
        case 0xca:
          goto LAB_0071c82a;
        case 0xcb:
          goto LAB_0071c834;
        case 0xcd:
          goto LAB_0071c83e;
        case 0xce:
          goto LAB_0071c848;
        case 0xcf:
          goto LAB_0071c852;
        case 0xd0:
          goto LAB_0071c85c;
        case 0xd1:
          goto LAB_0071c866;
        case 0xd2:
          goto LAB_0071c870;
        case 0xd4:
          goto code_r0x0071c87a;
        case 0xd6:
          goto code_r0x0071c884;
        case 0xd7:
          goto code_r0x0071c88e;
        case 0xd8:
          goto code_r0x0071c898;
        case 0xe6:
          goto LAB_0071c8a2;
        case 0xe7:
          goto LAB_0071c8ac;
        case 0xe8:
          goto LAB_0071c8b6;
        case 0xe9:
          goto LAB_0071c8c0;
        case 0xea:
          goto LAB_0071c8ca;
        }
      }
      else if (param_1 < 0x3ed) {
        if (param_1 == 0x3ec) {
LAB_0071caa6:
          return "ERROR_INVALID_FLAGS";
        }
        if (param_1 < 0x12f) {
          if (param_1 == 0x12e) {
LAB_0071c9c0:
            return "ERROR_DISK_TOO_FRAGMENTED";
          }
          switch(param_1) {
          case 0xfe:
LAB_0071c920:
            return "ERROR_INVALID_EA_NAME";
          case 0xff:
LAB_0071c92a:
            return "ERROR_EA_LIST_INCONSISTENT";
          case 0x102:
LAB_0071c934:
            return "WAIT_TIMEOUT";
          case 0x103:
LAB_0071c93e:
            return "ERROR_NO_MORE_ITEMS & DIERR_NOMOREITEMS";
          case 0x10a:
LAB_0071c948:
            return "ERROR_CANNOT_COPY";
          case 0x10b:
LAB_0071c952:
            return "ERROR_DIRECTORY";
          case 0x113:
LAB_0071c95c:
            return "ERROR_EAS_DIDNT_FIT";
          case 0x114:
LAB_0071c966:
            return "ERROR_EA_FILE_CORRUPT";
          case 0x115:
LAB_0071c970:
            return "ERROR_EA_TABLE_FULL";
          case 0x116:
LAB_0071c97a:
            return "ERROR_INVALID_EA_HANDLE";
          case 0x11a:
LAB_0071c984:
            return "ERROR_EAS_NOT_SUPPORTED";
          case 0x120:
LAB_0071c98e:
            return "ERROR_NOT_OWNER";
          case 0x12a:
LAB_0071c998:
            return "ERROR_TOO_MANY_POSTS";
          case 299:
LAB_0071c9a2:
            return "ERROR_PARTIAL_COPY";
          case 300:
LAB_0071c9ac:
            return "ERROR_OPLOCK_NOT_GRANTED";
          case 0x12d:
            goto LAB_0071c9b6;
          }
        }
        else if (param_1 < 0x3e4) {
          if (param_1 == 0x3e3) {
LAB_0071ca3e:
            return "ERROR_OPERATION_ABORTED";
          }
          if (param_1 == 0x12f) {
LAB_0071ca34:
            return "ERROR_DELETE_PENDING";
          }
          if (param_1 == 0x13d) {
LAB_0071ca2a:
            return "ERROR_MR_MID_NOT_FOUND";
          }
          if (param_1 == 0x1e7) {
LAB_0071ca20:
            return "ERROR_INVALID_ADDRESS";
          }
          if (param_1 == 0x216) {
LAB_0071ca16:
            return "ERROR_ARITHMETIC_OVERFLOW";
          }
          if (param_1 == 0x217) {
LAB_0071ca0c:
            return "ERROR_PIPE_CONNECTED";
          }
          if (param_1 == 0x218) {
LAB_00718029:
            return "ERROR_PIPE_LISTENING";
          }
          if (param_1 == 0x3e2) goto LAB_0071ca02;
        }
        else {
          if (param_1 == 0x3e4) {
LAB_0071ca9c:
            return "ERROR_IO_INCOMPLETE";
          }
          if (param_1 == 0x3e5) {
LAB_0071ca92:
            return "ERROR_IO_PENDING";
          }
          if (param_1 == 0x3e6) {
LAB_0071ca88:
            return "ERROR_NOACCESS";
          }
          if (param_1 == 999) {
LAB_0071ca7e:
            return "ERROR_SWAPERROR";
          }
          if (param_1 == 0x3e9) {
LAB_0071ca74:
            return "ERROR_STACK_OVERFLOW";
          }
          if (param_1 == 0x3ea) {
LAB_00718080:
            return "ERROR_INVALID_MESSAGE";
          }
          if (param_1 == 0x3eb) goto LAB_0071ca6a;
        }
      }
      else {
        switch(param_1) {
        case 0x3ed:
LAB_0071cacc:
          return "ERROR_UNRECOGNIZED_VOLUME";
        case 0x3ee:
LAB_0071cad6:
          return "ERROR_FILE_INVALID";
        case 0x3ef:
LAB_0071cae0:
          return "ERROR_FULLSCREEN_MODE";
        case 0x3f0:
LAB_0071caea:
          return "ERROR_NO_TOKEN";
        case 0x3f1:
LAB_0071caf4:
          return "ERROR_BADDB";
        case 0x3f2:
LAB_0071cafe:
          return "ERROR_BADKEY";
        case 0x3f3:
LAB_0071cb08:
          return "ERROR_CANTOPEN";
        case 0x3f4:
LAB_0071cb12:
          return "ERROR_CANTREAD";
        case 0x3f5:
LAB_0071cb1c:
          return "ERROR_CANTWRITE";
        case 0x3f6:
LAB_0071cb26:
          return "ERROR_REGISTRY_RECOVERED";
        case 0x3f7:
LAB_0071cb30:
          return "ERROR_REGISTRY_CORRUPT";
        case 0x3f8:
LAB_0071cb3a:
          return "ERROR_REGISTRY_IO_FAILED";
        case 0x3f9:
LAB_0071cb44:
          return "ERROR_NOT_REGISTRY_FILE";
        case 0x3fa:
LAB_0071cb4e:
          return "ERROR_KEY_DELETED";
        case 0x3fb:
LAB_0071cb58:
          return "ERROR_NO_LOG_SPACE";
        case 0x3fc:
LAB_0071cb62:
          return "ERROR_KEY_HAS_CHILDREN";
        case 0x3fd:
LAB_0071cb6c:
          return "ERROR_CHILD_MUST_BE_VOLATILE";
        case 0x3fe:
LAB_0071cb76:
          return "ERROR_NOTIFY_ENUM_DIR";
        case 0x41b:
LAB_0071cb80:
          return "ERROR_DEPENDENT_SERVICES_RUNNING";
        case 0x41c:
LAB_0071cb8a:
          return "ERROR_INVALID_SERVICE_CONTROL";
        case 0x41d:
LAB_0071cb94:
          return "ERROR_SERVICE_REQUEST_TIMEOUT";
        case 0x41e:
LAB_0071cb9e:
          return "ERROR_SERVICE_NO_THREAD";
        case 0x41f:
LAB_0071cba8:
          return "ERROR_SERVICE_DATABASE_LOCKED";
        case 0x420:
LAB_0071cbb2:
          return "ERROR_SERVICE_ALREADY_RUNNING";
        case 0x421:
LAB_0071cbbc:
          return "ERROR_INVALID_SERVICE_ACCOUNT";
        case 0x422:
LAB_0071cbc6:
          return "ERROR_SERVICE_DISABLED";
        case 0x423:
LAB_0071cbd0:
          return "ERROR_CIRCULAR_DEPENDENCY";
        case 0x424:
LAB_0071cbda:
          return "ERROR_SERVICE_DOES_NOT_EXIST";
        case 0x425:
LAB_0071cbe4:
          return "ERROR_SERVICE_CANNOT_ACCEPT_CTRL";
        case 0x426:
LAB_0071cbee:
          return "ERROR_SERVICE_NOT_ACTIVE";
        case 0x427:
          goto LAB_0071cbf8;
        }
      }
    }
    else {
      switch(param_1) {
      case 0x429:
LAB_0071cc23:
        return "ERROR_DATABASE_DOES_NOT_EXIST";
      case 0x42a:
LAB_0071cc2d:
        return "ERROR_SERVICE_SPECIFIC_ERROR";
      case 0x42b:
LAB_0071cc37:
        return "ERROR_PROCESS_ABORTED";
      case 0x42c:
LAB_0071cc41:
        return "ERROR_SERVICE_DEPENDENCY_FAIL";
      case 0x42d:
LAB_0071cc4b:
        return "ERROR_SERVICE_LOGON_FAILED";
      case 0x42e:
LAB_0071cc55:
        return "ERROR_SERVICE_START_HANG";
      case 0x42f:
LAB_0071cc5f:
        return "ERROR_INVALID_SERVICE_LOCK";
      case 0x430:
LAB_0071cc69:
        return "ERROR_SERVICE_MARKED_FOR_DELETE";
      case 0x431:
LAB_0071cc73:
        return "ERROR_SERVICE_EXISTS";
      case 0x432:
LAB_0071cc7d:
        return "ERROR_ALREADY_RUNNING_LKG";
      case 0x433:
LAB_0071cc87:
        return "ERROR_SERVICE_DEPENDENCY_DELETED";
      case 0x434:
LAB_0071cc91:
        return "ERROR_BOOT_ALREADY_ACCEPTED";
      case 0x435:
LAB_0071cc9b:
        return "ERROR_SERVICE_NEVER_STARTED";
      case 0x436:
LAB_0071cca5:
        return "ERROR_DUPLICATE_SERVICE_NAME";
      case 0x437:
LAB_0071ccaf:
        return "ERROR_DIFFERENT_SERVICE_ACCOUNT";
      case 0x438:
LAB_0071ccb9:
        return "ERROR_CANNOT_DETECT_DRIVER_FAILURE";
      case 0x439:
LAB_0071ccc3:
        return "ERROR_CANNOT_DETECT_PROCESS_ABORT";
      case 0x43a:
LAB_0071cccd:
        return "ERROR_NO_RECOVERY_PROGRAM";
      case 0x43b:
LAB_0071ccd7:
        return "ERROR_SERVICE_NOT_IN_EXE";
      case 0x43c:
LAB_0071d7bd:
        return "ERROR_NOT_SAFEBOOT_SERVICE";
      case 0x44c:
LAB_0071cce1:
        return "ERROR_END_OF_MEDIA";
      case 0x44d:
LAB_0071cceb:
        return "ERROR_FILEMARK_DETECTED";
      case 0x44e:
LAB_0071ccf5:
        return "ERROR_BEGINNING_OF_MEDIA";
      case 0x44f:
LAB_0071ccff:
        return "ERROR_SETMARK_DETECTED";
      case 0x450:
LAB_0071cd09:
        return "ERROR_NO_DATA_DETECTED";
      case 0x451:
LAB_0071cd13:
        return "ERROR_PARTITION_FAILURE";
      case 0x452:
LAB_0071cd1d:
        return "ERROR_INVALID_BLOCK_LENGTH";
      case 0x453:
LAB_0071cd27:
        return "ERROR_DEVICE_NOT_PARTITIONED";
      case 0x454:
LAB_0071cd31:
        return "ERROR_UNABLE_TO_LOCK_MEDIA";
      case 0x455:
LAB_0071cd3b:
        return "ERROR_UNABLE_TO_UNLOAD_MEDIA";
      case 0x456:
LAB_0071cd45:
        return "ERROR_MEDIA_CHANGED";
      case 0x457:
LAB_0071cd4f:
        return "ERROR_BUS_RESET";
      case 0x458:
LAB_0071cd59:
        return "ERROR_NO_MEDIA_IN_DRIVE";
      case 0x459:
LAB_0071cd63:
        return "ERROR_NO_UNICODE_TRANSLATION";
      case 0x45a:
LAB_0071cd6d:
        return "ERROR_DLL_INIT_FAILED";
      case 0x45b:
LAB_0071cd77:
        return "ERROR_SHUTDOWN_IN_PROGRESS";
      case 0x45c:
LAB_0071cd81:
        return "ERROR_NO_SHUTDOWN_IN_PROGRESS";
      case 0x45d:
LAB_0071cd8b:
        return "ERROR_IO_DEVICE";
      case 0x45e:
LAB_0071cd95:
        return "ERROR_SERIAL_NO_DEVICE";
      case 0x45f:
LAB_0071cd9f:
        return "ERROR_IRQ_BUSY";
      case 0x460:
LAB_0071cda9:
        return "ERROR_MORE_WRITES";
      case 0x461:
LAB_0071cdb3:
        return "ERROR_COUNTER_TIMEOUT";
      case 0x462:
LAB_0071cdbd:
        return "ERROR_FLOPPY_ID_MARK_NOT_FOUND";
      case 0x463:
LAB_0071cdc7:
        return "ERROR_FLOPPY_WRONG_CYLINDER";
      case 0x464:
LAB_0071cdd1:
        return "ERROR_FLOPPY_UNKNOWN_ERROR";
      case 0x465:
LAB_0071cddb:
        return "ERROR_FLOPPY_BAD_REGISTERS";
      case 0x466:
LAB_0071cde5:
        return "ERROR_DISK_RECALIBRATE_FAILED";
      case 0x467:
LAB_0071cdef:
        return "ERROR_DISK_OPERATION_FAILED";
      case 0x468:
LAB_0071cdf9:
        return "ERROR_DISK_RESET_FAILED";
      case 0x469:
LAB_0071ce03:
        return "ERROR_EOM_OVERFLOW";
      case 0x46a:
LAB_0071ce0d:
        return "ERROR_NOT_ENOUGH_SERVER_MEMORY";
      case 0x46b:
LAB_0071ce17:
        return "ERROR_POSSIBLE_DEADLOCK";
      case 0x46c:
LAB_0071ce21:
        return "ERROR_MAPPED_ALIGNMENT";
      case 0x474:
LAB_0071ce2b:
        return "ERROR_SET_POWER_STATE_VETOED";
      case 0x475:
LAB_0071ce35:
        return "ERROR_SET_POWER_STATE_FAILED";
      case 0x476:
LAB_0071ce3f:
        return "ERROR_TOO_MANY_LINKS";
      case 0x47e:
LAB_0071ce49:
        return "ERROR_OLD_WIN_VERSION & DIERR_OLDDIRECTINPUTVERSION";
      case 0x47f:
LAB_0071ce53:
        return "ERROR_APP_WRONG_OS";
      case 0x480:
LAB_0071ce5d:
        return "ERROR_SINGLE_INSTANCE_APP";
      case 0x481:
LAB_0071ce67:
        return "ERROR_RMODE_APP & DIERR_BETADIRECTINPUTVERSION";
      case 0x482:
LAB_0071ce71:
        return "ERROR_INVALID_DLL";
      case 0x483:
LAB_0071ce7b:
        return "ERROR_NO_ASSOCIATION";
      case 0x484:
        goto LAB_0071ce85;
      case 0x485:
        goto LAB_0071ce8f;
      case 0x486:
        goto LAB_0071ce99;
      case 0x487:
        goto LAB_0071cea3;
      case 0x488:
        goto LAB_0071cead;
      case 0x489:
        goto LAB_0071ceb7;
      case 0x48a:
        goto LAB_0071cec1;
      case 0x48b:
        goto LAB_0071cecb;
      case 0x48c:
        goto LAB_0071ced5;
      case 0x48d:
        goto LAB_0071cedf;
      case 0x48e:
        goto LAB_0071cee9;
      case 0x48f:
        goto LAB_0071cef3;
      case 0x490:
        goto LAB_0071cefd;
      case 0x491:
        goto LAB_0071cf07;
      case 0x492:
        goto LAB_0071cf11;
      case 0x493:
        goto LAB_0071cf1b;
      case 0x494:
        goto LAB_0071cf25;
      case 0x495:
        goto LAB_0071cf2f;
      case 0x497:
        goto LAB_0071cf39;
      case 0x498:
        goto LAB_0071cf43;
      case 0x499:
        goto LAB_0071cf4d;
      case 0x49a:
        goto LAB_0071cf57;
      case 0x49b:
        goto LAB_0071cf61;
      case 0x49c:
        goto LAB_0071cf6b;
      case 0x49d:
        goto LAB_0071d7c7;
      case 0x4b0:
        goto LAB_0071cf75;
      case 0x4b1:
        goto LAB_0071cf7f;
      case 0x4b2:
        goto LAB_0071cf89;
      case 0x4b3:
        goto LAB_0071cf93;
      case 0x4b4:
        goto LAB_0071cf9d;
      case 0x4b5:
        goto LAB_0071cfa7;
      case 0x4b6:
        goto LAB_0071cfb1;
      case 0x4b7:
        goto LAB_0071cfbb;
      case 0x4b8:
        goto LAB_0071cfc5;
      case 0x4b9:
        goto LAB_0071cfcf;
      case 0x4ba:
        goto LAB_0071cfd9;
      case 0x4bb:
        goto LAB_0071cfe3;
      case 0x4bc:
        goto LAB_0071cfed;
      case 0x4bd:
        goto LAB_0071cff7;
      case 0x4be:
        goto LAB_0071d001;
      case 0x4bf:
        goto LAB_0071d00b;
      case 0x4c0:
        goto LAB_0071d015;
      case 0x4c1:
        goto LAB_0071d01f;
      case 0x4c2:
        goto LAB_0071d029;
      case 0x4c3:
        goto LAB_0071d033;
      case 0x4c4:
        goto LAB_0071d03d;
      case 0x4c5:
        goto LAB_0071d047;
      case 0x4c6:
        goto LAB_0071d051;
      case 0x4c7:
        goto LAB_0071d05b;
      case 0x4c8:
        goto LAB_0071d065;
      case 0x4c9:
        goto LAB_0071d06f;
      case 0x4ca:
        goto LAB_0071d079;
      case 0x4cb:
        goto LAB_0071d083;
      case 0x4cc:
        goto LAB_0071d08d;
      case 0x4cd:
        goto LAB_0071d097;
      case 0x4ce:
        goto LAB_0071d0a1;
      case 0x4cf:
        goto LAB_0071d0ab;
      case 0x4d0:
        goto LAB_0071d0b5;
      case 0x4d1:
        goto LAB_0071d0bf;
      case 0x4d2:
        goto LAB_0071d0c9;
      case 0x4d3:
        goto LAB_0071d0d3;
      case 0x4d4:
        goto LAB_0071d0dd;
      case 0x4d5:
        goto LAB_0071d0e7;
      case 0x4d6:
        goto LAB_0071d0f1;
      case 0x4d7:
        goto LAB_0071d0fb;
      case 0x4d8:
        goto LAB_0071d105;
      case 0x4d9:
        goto LAB_0071d10f;
      case 0x4da:
        goto LAB_0071d119;
      case 0x4db:
        goto LAB_0071d123;
      case 0x4dc:
        goto LAB_0071d12d;
      case 0x4dd:
        goto LAB_0071d137;
      case 0x4de:
        goto LAB_0071d141;
      case 0x4df:
        goto LAB_0071d14b;
      case 0x4e0:
        goto LAB_0071d155;
      case 0x4e1:
        goto LAB_0071d15f;
      case 0x4e2:
        goto LAB_0071d169;
      case 0x4e3:
        goto LAB_0071d7d1;
      case 0x4e4:
        goto LAB_0071d7db;
      case 0x4e5:
        goto LAB_0071d7e5;
      case 0x4e6:
        goto LAB_0071d7ef;
      case 0x4e7:
        goto LAB_0071d7f9;
      case 0x4e8:
        goto LAB_0071d803;
      case 0x4e9:
        goto LAB_0071d80d;
      case 0x4ea:
        goto LAB_0071d817;
      case 0x4eb:
        goto LAB_0071d821;
      case 0x4ec:
        goto LAB_0071d82b;
      case 0x4ed:
        goto LAB_0071d835;
      case 0x4ee:
        goto LAB_0071d83f;
      case 0x4ef:
        goto LAB_0071d849;
      case 0x4f0:
        goto LAB_0071d853;
      case 0x4f1:
        goto LAB_0071d85d;
      case 0x4f7:
        goto code_r0x0071d867;
      case 0x4f9:
        goto code_r0x0071d871;
      case 0x4fa:
        goto code_r0x0071d87b;
      case 0x4fb:
        goto code_r0x0071d885;
      case 0x4fc:
        goto code_r0x0071d88f;
      case 0x514:
        goto LAB_0071d173;
      case 0x515:
        goto LAB_0071d17d;
      case 0x516:
        goto LAB_0071d187;
      case 0x517:
        goto LAB_0071d191;
      case 0x518:
        goto LAB_0071d19b;
      case 0x519:
        goto LAB_0071d1a5;
      case 0x51a:
        goto LAB_0071d1af;
      case 0x51b:
        goto LAB_0071d1b9;
      case 0x51c:
        goto LAB_0071d1c3;
      case 0x51d:
        goto LAB_0071d1cd;
      case 0x51e:
        goto LAB_0071d1d7;
      case 0x51f:
        goto LAB_0071d1e1;
      case 0x520:
        goto LAB_0071d1eb;
      case 0x521:
        goto LAB_0071d1f5;
      case 0x522:
        goto LAB_0071d1ff;
      case 0x523:
        goto LAB_0071d209;
      case 0x524:
        goto LAB_0071d213;
      case 0x525:
        goto LAB_0071d21d;
      case 0x526:
        goto LAB_0071d227;
      case 0x527:
        goto LAB_0071d231;
      case 0x528:
        goto LAB_0071d23b;
      case 0x529:
        goto LAB_0071d245;
      case 0x52a:
        goto LAB_0071d24f;
      case 0x52b:
        goto LAB_0071d259;
      case 0x52c:
        goto LAB_0071d263;
      case 0x52d:
        goto LAB_0071d26d;
      case 0x52e:
        goto LAB_0071d277;
      case 0x52f:
        goto LAB_0071d281;
      case 0x530:
        goto LAB_0071d28b;
      case 0x531:
        goto LAB_0071d295;
      case 0x532:
        goto LAB_0071d29f;
      case 0x533:
        goto LAB_0071d2a9;
      case 0x534:
        goto LAB_0071d2b3;
      case 0x535:
        goto LAB_0071d2bd;
      case 0x536:
        goto LAB_0071d2c7;
      case 0x537:
        goto LAB_0071d2d1;
      case 0x538:
        goto LAB_0071d2db;
      case 0x539:
        goto LAB_0071d2e5;
      case 0x53a:
        goto LAB_0071d2ef;
      case 0x53c:
        goto LAB_0071d2f9;
      case 0x53d:
        goto LAB_0071d303;
      case 0x53e:
        goto LAB_0071d30d;
      case 0x53f:
        goto LAB_0071d317;
      case 0x540:
        goto LAB_0071d321;
      case 0x541:
        goto LAB_0071d32b;
      case 0x542:
        goto LAB_0071d335;
      case 0x543:
        goto LAB_0071d33f;
      case 0x544:
        goto LAB_0071d349;
      case 0x545:
        goto LAB_0071d353;
      case 0x546:
        goto LAB_0071d35d;
      case 0x547:
        goto LAB_0071d367;
      case 0x548:
        goto LAB_0071d371;
      case 0x549:
        goto LAB_0071d37b;
      case 0x54a:
        goto LAB_0071d385;
      case 0x54b:
        goto LAB_0071d38f;
      case 0x54c:
        goto LAB_0071d399;
      case 0x54d:
        goto LAB_0071d3a3;
      case 0x54e:
        goto LAB_0071d3ad;
      case 0x54f:
        goto LAB_0071d3b7;
      case 0x550:
        goto LAB_0071d3c1;
      case 0x551:
        goto LAB_0071d3cb;
      case 0x552:
        goto LAB_0071d3d5;
      case 0x553:
        goto LAB_0071d3df;
      case 0x554:
        goto LAB_0071d3e9;
      case 0x555:
        goto LAB_0071d3f3;
      case 0x556:
        goto LAB_0071d3fd;
      case 0x557:
        goto LAB_0071d407;
      case 0x558:
        goto LAB_0071d411;
      case 0x559:
        goto LAB_0071d41b;
      case 0x55a:
        goto LAB_0071d425;
      case 0x55b:
        goto LAB_0071d42f;
      case 0x55c:
        goto LAB_0071d439;
      case 0x55d:
        goto LAB_0071d443;
      case 0x55e:
        goto LAB_0071d44d;
      case 0x55f:
        goto LAB_0071d457;
      case 0x560:
        goto LAB_0071d461;
      case 0x561:
        goto LAB_0071d46b;
      case 0x562:
        goto LAB_0071d475;
      case 0x563:
        goto LAB_0071d47f;
      case 0x564:
        goto LAB_0071d489;
      case 0x565:
        goto LAB_0071d493;
      case 0x566:
        goto LAB_0071d49d;
      case 0x567:
        goto LAB_0071d4a7;
      case 0x568:
        goto LAB_0071d4b1;
      case 0x569:
        goto LAB_0071d4bb;
      case 0x56a:
        goto LAB_0071d4c5;
      case 0x56b:
        goto LAB_0071d4cf;
      case 0x56c:
        goto LAB_0071d4d9;
      case 0x56d:
        goto LAB_0071d4e3;
      case 0x56e:
        goto LAB_0071d4ed;
      case 0x56f:
        goto LAB_0071d4f7;
      case 0x570:
        goto LAB_0071d501;
      case 0x571:
        goto LAB_0071d50b;
      case 0x572:
        goto LAB_0071d515;
      case 0x573:
        goto LAB_0071d51f;
      case 0x574:
        goto LAB_0071d529;
      case 0x575:
        goto LAB_0071d533;
      case 0x576:
        goto LAB_0071d53d;
      case 0x577:
        goto LAB_0071d899;
      case 0x578:
        goto LAB_0071d547;
      case 0x579:
        goto LAB_0071d551;
      case 0x57a:
        goto LAB_0071d55b;
      case 0x57b:
        goto LAB_0071d565;
      case 0x57c:
        goto LAB_0071d56f;
      case 0x57d:
        goto LAB_0071d579;
      case 0x57e:
        goto LAB_0071d583;
      case 0x57f:
        goto LAB_0071d58d;
      case 0x580:
        goto LAB_0071d597;
      case 0x581:
        goto LAB_0071d5a1;
      case 0x582:
        goto LAB_0071d5ab;
      case 0x583:
        goto LAB_0071d5b5;
      case 0x584:
        goto LAB_0071d5bf;
      case 0x585:
        goto LAB_0071d5c9;
      case 0x586:
        goto LAB_0071d5d3;
      case 0x587:
        goto LAB_0071d5dd;
      case 0x588:
        goto LAB_0071d5e7;
      case 0x589:
        goto LAB_0071d5f1;
      case 0x58a:
        goto LAB_0071d5fb;
      case 0x58b:
        goto LAB_0071d605;
      case 0x58c:
        goto LAB_0071d60f;
      case 0x58d:
        goto LAB_0071d619;
      case 0x58e:
        goto LAB_0071d623;
      case 0x58f:
        goto LAB_0071d62d;
      case 0x590:
        goto LAB_0071d637;
      case 0x591:
        goto LAB_0071d641;
      case 0x592:
        goto LAB_0071d64b;
      case 0x593:
        goto LAB_0071d655;
      case 0x594:
        goto LAB_0071d65f;
      case 0x595:
        goto LAB_0071d669;
      case 0x596:
        goto LAB_0071d673;
      case 0x597:
        goto LAB_0071d67d;
      case 0x598:
        goto LAB_0071d687;
      case 0x599:
        goto LAB_0071d691;
      case 0x59a:
        goto LAB_0071d69b;
      case 0x59b:
        goto LAB_0071d6a5;
      case 0x59c:
        goto LAB_0071d6af;
      case 0x59d:
        goto LAB_0071d6b9;
      case 0x59e:
        goto LAB_0071d6c3;
      case 0x59f:
        goto LAB_0071d6cd;
      case 0x5a0:
        goto LAB_0071d6d7;
      case 0x5a1:
        goto LAB_0071d6e1;
      case 0x5a2:
        goto LAB_0071d6eb;
      case 0x5a3:
        goto LAB_0071d6f5;
      case 0x5a4:
        goto LAB_0071d6ff;
      case 0x5a5:
        goto LAB_0071d709;
      case 0x5a6:
        goto LAB_0071d713;
      case 0x5a7:
        goto LAB_0071d71d;
      case 0x5a8:
        goto LAB_0071d727;
      case 0x5a9:
        goto LAB_0071d731;
      case 0x5aa:
        goto LAB_0071d73b;
      case 0x5ab:
        goto LAB_0071d745;
      case 0x5ac:
        goto LAB_0071d74f;
      case 0x5ad:
        goto LAB_0071d759;
      case 0x5ae:
        goto LAB_0071d763;
      case 0x5af:
        goto LAB_0071d76d;
      case 0x5b0:
        goto LAB_0071d777;
      case 0x5b1:
        goto LAB_0071d781;
      case 0x5b2:
        goto LAB_0071d78b;
      case 0x5b3:
        goto LAB_0071d795;
      case 0x5b4:
        goto LAB_0071d79f;
      case 0x5b5:
        goto LAB_0071d7a9;
      case 0x5dc:
        goto code_r0x0071d7b3;
      }
    }
  }
  else if (param_1 < 0x20e7) {
    if (param_1 == 0x20e6) {
LAB_0071f75d:
      return "ERROR_DS_CANT_RETRIEVE_CHILD";
    }
    if (param_1 < 0x139a) {
      if (param_1 == 0x1399) {
LAB_0071e88c:
        return "ERROR_RESMON_CREATE_FAILED";
      }
      if (param_1 < 0x724) {
        if (param_1 == 0x723) goto LAB_0071df9e;
        if (param_1 - 0x5deU < 0x145) {
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
          switch((&DAT_00725ca5)[param_1]) {
          case 0:
            goto code_r0x0071d904;
          case 1:
            goto code_r0x0071d90e;
          case 2:
            goto LAB_0071de7c;
          case 3:
            goto LAB_0071d918;
          case 4:
            goto LAB_0071d922;
          case 5:
            goto LAB_0071d92c;
          case 6:
            goto LAB_0071d936;
          case 7:
            goto LAB_0071d940;
          case 8:
            goto LAB_0071d94a;
          case 9:
            goto LAB_0071d954;
          case 10:
            goto LAB_0071d95e;
          case 0xb:
            goto LAB_0071d968;
          case 0xc:
            goto LAB_0071d972;
          case 0xd:
            goto LAB_0071d97c;
          case 0xe:
            goto LAB_0071de86;
          case 0xf:
            goto LAB_0071d986;
          case 0x10:
            goto LAB_0071d990;
          case 0x11:
            goto LAB_0071d99a;
          case 0x12:
            goto LAB_0071d9a4;
          case 0x13:
            goto LAB_0071de90;
          case 0x14:
            goto LAB_0071de9a;
          case 0x15:
            goto LAB_0071dea4;
          case 0x16:
            goto LAB_0071deae;
          case 0x17:
            goto LAB_0071deb8;
          case 0x18:
            goto LAB_0071dec2;
          case 0x19:
            goto LAB_0071decc;
          case 0x1a:
            goto LAB_0071ded6;
          case 0x1b:
            goto LAB_0071dee0;
          case 0x1c:
            goto LAB_0071deea;
          case 0x1d:
            goto LAB_0071def4;
          case 0x1e:
            goto LAB_0071defe;
          case 0x1f:
            goto LAB_0071df08;
          case 0x20:
            goto LAB_0071df12;
          case 0x21:
            goto LAB_0071df1c;
          case 0x22:
            goto LAB_0071df26;
          case 0x23:
            goto LAB_0071df30;
          case 0x24:
            goto LAB_0071df3a;
          case 0x25:
            goto LAB_0071df44;
          case 0x26:
            goto LAB_0071df4e;
          case 0x27:
            goto LAB_0071df58;
          case 0x28:
            goto LAB_0071df62;
          case 0x29:
            goto LAB_0071df6c;
          case 0x2a:
            goto LAB_0071df76;
          case 0x2b:
            goto LAB_0071df80;
          case 0x2c:
            goto LAB_0071df8a;
          case 0x2d:
            goto LAB_0071df94;
          case 0x2e:
            goto LAB_0071d9ae;
          case 0x2f:
            goto LAB_0071d9b8;
          case 0x30:
            goto LAB_0071d9c2;
          case 0x31:
            goto LAB_0071d9cc;
          case 0x32:
            goto LAB_0071d9d6;
          case 0x33:
            goto LAB_0071d9e0;
          case 0x34:
            goto LAB_0071d9ea;
          case 0x35:
            goto LAB_0071d9f4;
          case 0x36:
            goto LAB_0071d9fe;
          case 0x37:
            goto LAB_0071da08;
          case 0x38:
            goto LAB_0071da12;
          case 0x39:
            goto LAB_0071da1c;
          case 0x3a:
            goto LAB_0071da26;
          case 0x3b:
            goto LAB_0071da30;
          case 0x3c:
            goto LAB_0071da3a;
          case 0x3d:
            goto LAB_0071da44;
          case 0x3e:
            goto LAB_0071da4e;
          case 0x3f:
            goto LAB_0071da58;
          case 0x40:
            goto LAB_0071da62;
          case 0x41:
            goto LAB_0071da6c;
          case 0x42:
            goto LAB_0071da76;
          case 0x43:
            goto LAB_0071da80;
          case 0x44:
            goto LAB_0071da8a;
          case 0x45:
            goto LAB_0071da94;
          case 0x46:
            goto LAB_0071da9e;
          case 0x47:
            goto LAB_0071daa8;
          case 0x48:
            goto LAB_0071dab2;
          case 0x49:
            goto LAB_0071dabc;
          case 0x4a:
            goto LAB_0071dac6;
          case 0x4b:
            goto LAB_0071dad0;
          case 0x4c:
            goto LAB_0071dada;
          case 0x4d:
            goto LAB_0071dae4;
          case 0x4e:
            goto LAB_0071daee;
          case 0x4f:
            goto LAB_0071daf8;
          case 0x50:
            goto LAB_0071db02;
          case 0x51:
            goto LAB_0071db0c;
          case 0x52:
            goto LAB_0071db16;
          case 0x53:
            goto LAB_0071db20;
          case 0x54:
            goto LAB_0071db2a;
          case 0x55:
            goto LAB_0071db34;
          case 0x56:
            goto LAB_0071db3e;
          case 0x57:
            goto LAB_0071db48;
          case 0x58:
            goto LAB_0071db52;
          case 0x59:
            goto LAB_0071db5c;
          case 0x5a:
            goto LAB_0071db66;
          case 0x5b:
            goto LAB_0071db70;
          case 0x5c:
            goto LAB_0071db7a;
          case 0x5d:
            goto LAB_0071db84;
          case 0x5e:
            goto LAB_0071db8e;
          case 0x5f:
            goto LAB_0071db98;
          case 0x60:
            goto LAB_0071dba2;
          case 0x61:
            goto LAB_0071dbac;
          case 0x62:
            goto LAB_0071dbb6;
          case 99:
            goto LAB_0071dbc0;
          case 100:
            goto LAB_0071dbca;
          case 0x65:
            goto LAB_0071dbd4;
          case 0x66:
            goto LAB_0071dbde;
          case 0x67:
            goto LAB_0071dbe8;
          case 0x68:
            goto LAB_0071dbf2;
          case 0x69:
            goto LAB_0071dbfc;
          case 0x6a:
            goto LAB_0071dc06;
          case 0x6b:
            goto LAB_0071dc10;
          case 0x6c:
            goto LAB_0071dc1a;
          case 0x6d:
            goto LAB_0071dc24;
          case 0x6e:
            goto LAB_0071dc2e;
          case 0x6f:
            goto LAB_0071dc38;
          case 0x70:
            goto LAB_0071dc42;
          case 0x71:
            goto LAB_0071dc4c;
          case 0x72:
            goto LAB_0071dc56;
          case 0x73:
            goto LAB_0071dc60;
          case 0x74:
            goto LAB_0071dc6a;
          case 0x75:
            goto LAB_0071dc74;
          case 0x76:
            goto LAB_0071dc7e;
          case 0x77:
            goto LAB_0071dc88;
          case 0x78:
            goto LAB_0071dc92;
          case 0x79:
            goto LAB_0071dc9c;
          case 0x7a:
            goto LAB_0071dca6;
          case 0x7b:
            goto LAB_0071dcb0;
          case 0x7c:
            goto LAB_0071dcba;
          case 0x7d:
            goto LAB_0071dcc4;
          case 0x7e:
            goto LAB_0071dcce;
          case 0x7f:
            goto LAB_0071dcd8;
          case 0x80:
            goto LAB_0071dce2;
          case 0x81:
            goto LAB_0071dcec;
          case 0x82:
            goto LAB_0071dcf6;
          case 0x83:
            goto LAB_0071dd00;
          case 0x84:
            goto LAB_0071dd0a;
          case 0x85:
            goto LAB_0071dd14;
          case 0x86:
            goto LAB_0071dd1e;
          case 0x87:
            goto LAB_0071dd28;
          case 0x88:
            goto LAB_0071dd32;
          case 0x89:
            goto LAB_0071dd3c;
          case 0x8a:
            goto LAB_0071dd46;
          case 0x8b:
            goto LAB_0071dd50;
          case 0x8c:
            goto LAB_0071dd5a;
          case 0x8d:
            goto LAB_0071dd64;
          case 0x8e:
            goto LAB_0071dd6e;
          case 0x8f:
            goto LAB_0071dd78;
          case 0x90:
            goto LAB_0071dd82;
          case 0x91:
            goto LAB_0071dd8c;
          case 0x92:
            goto LAB_0071dd96;
          case 0x93:
            goto LAB_0071dda0;
          case 0x94:
            goto LAB_0071ddaa;
          case 0x95:
            goto LAB_0071ddb4;
          case 0x96:
            goto LAB_0071ddbe;
          case 0x97:
            goto LAB_0071ddc8;
          case 0x98:
            goto LAB_0071ddd2;
          case 0x99:
            goto LAB_0071dddc;
          case 0x9a:
            goto LAB_0071dde6;
          case 0x9b:
            goto LAB_0071ddf0;
          case 0x9c:
            goto LAB_0071ddfa;
          case 0x9d:
            goto LAB_0071de04;
          case 0x9e:
            goto LAB_0071de0e;
          case 0x9f:
            goto LAB_0071de18;
          case 0xa0:
            goto LAB_0071de22;
          case 0xa1:
            goto LAB_0071de2c;
          case 0xa2:
            goto LAB_0071de36;
          case 0xa3:
            goto LAB_0071de40;
          case 0xa4:
            goto LAB_0071de4a;
          case 0xa5:
            goto LAB_0071de54;
          case 0xa6:
            goto LAB_0071de5e;
          case 0xa7:
            goto LAB_0071de68;
          case 0xa8:
            goto LAB_0071de72;
          }
        }
      }
      else if (param_1 < 0xfa5) {
        if (param_1 == 0xfa4) {
LAB_0071825d:
          return "ERROR_FULL_BACKUP";
        }
        if (param_1 < 0x7d4) {
          if (param_1 == 0x7d3) goto LAB_0071e190;
          switch(param_1) {
          case 0x724:
            goto LAB_0071dfec;
          case 0x725:
            goto LAB_0071dff6;
          case 0x726:
            goto LAB_0071e000;
          case 0x727:
            goto LAB_0071e00a;
          case 0x728:
            goto LAB_0071e014;
          case 0x76a:
            goto LAB_0071e01e;
          case 0x76b:
            goto LAB_0071e028;
          case 0x76c:
            goto LAB_0071e032;
          case 0x76d:
            goto LAB_0071e03c;
          case 0x76e:
            goto LAB_0071e046;
          case 0x76f:
            goto LAB_0071e050;
          case 0x770:
            goto LAB_0071e05a;
          case 0x771:
            goto LAB_0071e064;
          case 0x772:
            goto LAB_0071e06e;
          case 0x773:
            goto LAB_0071e078;
          case 0x774:
            goto LAB_0071e082;
          case 0x775:
            goto LAB_0071e08c;
          case 0x776:
            goto LAB_0071e096;
          case 0x777:
            goto LAB_0071e0a0;
          case 0x778:
            goto LAB_0071e0aa;
          case 0x779:
            goto LAB_0071e0b4;
          case 0x77a:
            goto LAB_0071e0be;
          case 0x77b:
            goto LAB_0071e0c8;
          case 0x77c:
            goto LAB_0071e0d2;
          case 0x77d:
            goto LAB_0071e0dc;
          case 0x77e:
            goto LAB_0071e0e6;
          case 0x77f:
            goto LAB_0071e0f0;
          case 0x780:
            goto LAB_0071e0fa;
          case 0x781:
            goto LAB_0071e104;
          case 0x782:
            goto LAB_0071e12c;
          case 0x783:
            goto LAB_0071e136;
          case 0x784:
            goto LAB_0071e140;
          case 0x785:
            goto LAB_0071e14a;
          case 0x786:
            goto LAB_0071e154;
          case 0x787:
            goto LAB_0071e15e;
          case 0x788:
            goto LAB_0071e168;
          case 0x789:
            goto LAB_0071e172;
          case 0x78a:
            goto LAB_0071e17c;
          case 0x78b:
            goto LAB_0071e186;
          case 2000:
            goto LAB_0071e10e;
          case 0x7d1:
            goto LAB_0071e118;
          case 0x7d2:
            goto LAB_0071e122;
          }
        }
        else if (param_1 < 0x963) {
          if (param_1 == 0x962) {
LAB_0071e2d4:
            return "ERROR_ACTIVE_CONNECTIONS";
          }
          if (param_1 < 0x7e3) {
            if (param_1 == 0x7e2) goto LAB_0071e235;
            switch(param_1) {
            case 0x7d4:
              goto LAB_0071e1d1;
            case 0x7d5:
              goto LAB_0071e1db;
            case 0x7da:
              goto LAB_0071e1e5;
            case 0x7db:
              goto LAB_0071e1ef;
            case 0x7dc:
              goto LAB_0071e1f9;
            case 0x7dd:
              goto LAB_0071e203;
            case 0x7de:
              goto LAB_0071e20d;
            case 0x7df:
              goto LAB_0071e217;
            case 0x7e0:
              goto LAB_0071e221;
            case 0x7e1:
              goto LAB_0071e22b;
            }
          }
          else if (param_1 < 0x83d) {
            if (param_1 == 0x83c) goto LAB_0071e286;
            if (param_1 == 0x7e3) goto LAB_0071e27c;
            if (param_1 == 0x7e4) goto LAB_0071e272;
            if (param_1 == 0x7e5) goto LAB_0071e268;
            if (param_1 == 0x7e6) goto code_r0x0071e25e;
          }
          else {
            if (param_1 == 0x83d) goto LAB_0071e2ca;
            if (param_1 == 0x89a) goto LAB_0071e2c0;
            if (param_1 == 0x8ca) goto LAB_0071e2b6;
            if (param_1 == 0x961) {
LAB_0071e2ac:
              return "ERROR_OPEN_FILES";
            }
          }
        }
        else if (param_1 < 0xbc2) {
          if (param_1 == 0xbc1) {
LAB_0071e381:
            return "ERROR_PRINTER_HAS_JOBS_QUEUED";
          }
          if (param_1 < 0xbbd) {
            if (param_1 == 0xbbc) {
LAB_0071e341:
              return "ERROR_SPL_NO_ADDJOB";
            }
            if (param_1 == 0x964) {
LAB_0071e337:
              return "ERROR_DEVICE_IN_USE";
            }
            if (param_1 == 3000) {
LAB_007181be:
              return "ERROR_UNKNOWN_PRINT_MONITOR";
            }
            if (param_1 == 0xbb9) goto LAB_0071e32d;
            if (param_1 == 0xbba) goto LAB_0071e323;
            if (param_1 == 0xbbb) goto LAB_0071e319;
          }
          else {
            if (param_1 == 0xbbd) {
LAB_007181f4:
              return "ERROR_PRINT_PROCESSOR_ALREADY_INSTALLED";
            }
            if (param_1 == 0xbbe) goto LAB_0071e377;
            if (param_1 == 0xbbf) goto LAB_0071e36d;
            if (param_1 == 0xbc0) goto code_r0x0071e363;
          }
        }
        else if (param_1 < 0xbc7) {
          if (param_1 == 0xbc6) {
LAB_0071e3d2:
            return "ERROR_PRINTER_DRIVER_BLOCKED";
          }
          if (param_1 == 0xbc2) {
LAB_0071e3c8:
            return "ERROR_SUCCESS_REBOOT_REQUIRED";
          }
          if (param_1 == 0xbc3) goto LAB_0071e3be;
          if (param_1 == 0xbc4) goto LAB_0071e3b4;
          if (param_1 == 0xbc5) goto code_r0x0071e3aa;
        }
        else {
          if (param_1 == 4000) goto LAB_0071e40e;
          if (param_1 == 0xfa1) {
LAB_0071e404:
            return "ERROR_CAN_NOT_DEL_LOCAL_WINS";
          }
          if (param_1 == 0xfa2) {
LAB_0071e3fa:
            return "ERROR_STATIC_INIT";
          }
          if (param_1 == 0xfa3) {
LAB_0071e3f0:
            return "ERROR_INC_BACKUP";
          }
        }
      }
      else if (param_1 < 0x10e5) {
        if (param_1 == 0x10e4) {
LAB_0071e678:
          return "ERROR_UNABLE_TO_LOAD_MEDIUM";
        }
        if (param_1 < 0x10d0) {
          if (param_1 == 0x10cf) goto LAB_0071e591;
          if (param_1 < 0x1070) {
            if (param_1 == 0x106f) {
LAB_0071e4eb:
              return "ERROR_WMI_GUID_DISCONNECTED";
            }
            if (param_1 < 0x106b) {
              if (param_1 == 0x106a) goto LAB_0071e4a5;
              if (param_1 == 0xfa5) goto LAB_0071e49b;
              if (param_1 == 0xfa6) goto LAB_0071e491;
              if (param_1 == 0x1004) goto LAB_0071e487;
              if (param_1 == 0x1068) goto LAB_0071e47d;
              if (param_1 == 0x1069) goto LAB_0071e473;
            }
            else {
              if (param_1 == 0x106b) goto LAB_0071e4e1;
              if (param_1 == 0x106c) goto LAB_0071e4d7;
              if (param_1 == 0x106d) goto LAB_0071e4cd;
              if (param_1 == 0x106e) goto code_r0x0071e4c3;
            }
          }
          else if (param_1 < 0x1076) {
            if (param_1 == 0x1075) goto LAB_0071e549;
            if (param_1 == 0x1070) goto LAB_0071e53f;
            if (param_1 == 0x1071) goto LAB_0071e535;
            if (param_1 == 0x1072) goto LAB_0071e52b;
            if (param_1 == 0x1073) goto LAB_0071e521;
            if (param_1 == 0x1074) goto code_r0x0071e517;
          }
          else {
            if (param_1 == 0x1076) goto LAB_0071e587;
            if (param_1 == 0x10cc) goto LAB_0071e57d;
            if (param_1 == 0x10cd) goto LAB_0071e573;
            if (param_1 == 0x10ce) goto code_r0x0071e569;
          }
        }
        else {
          switch(param_1) {
          case 0x10d0:
            goto code_r0x0071e5b0;
          case 0x10d1:
            goto code_r0x0071e5ba;
          case 0x10d2:
            goto code_r0x0071e5c4;
          case 0x10d3:
            goto code_r0x0071e5ce;
          case 0x10d4:
            goto code_r0x0071e5d8;
          case 0x10d5:
            goto code_r0x0071e5e2;
          case 0x10d6:
            goto code_r0x0071e5ec;
          case 0x10d7:
            goto code_r0x0071e5f6;
          case 0x10d8:
            goto code_r0x0071e600;
          case 0x10d9:
            goto code_r0x0071e60a;
          case 0x10da:
            goto code_r0x0071e614;
          case 0x10db:
            goto code_r0x0071e61e;
          case 0x10dc:
            goto code_r0x0071e628;
          case 0x10dd:
            goto code_r0x0071e632;
          case 0x10de:
            goto code_r0x0071e63c;
          case 0x10df:
            goto code_r0x0071e646;
          case 0x10e0:
            goto code_r0x0071e650;
          case 0x10e1:
            goto code_r0x0071e65a;
          case 0x10e2:
            goto code_r0x0071e664;
          case 0x10e3:
            goto code_r0x0071e66e;
          }
        }
      }
      else if (param_1 < 0x1127) {
        if (param_1 == 0x1126) goto LAB_0071e768;
        switch(param_1) {
        case 0x10e5:
          goto code_r0x0071e6aa;
        case 0x10e6:
          goto code_r0x0071e6b4;
        case 0x10e7:
          goto code_r0x0071e6be;
        case 0x10e8:
          goto code_r0x0071e6c8;
        case 0x10e9:
          goto code_r0x0071e6d2;
        case 0x10ea:
          goto code_r0x0071e6dc;
        case 0x10eb:
          goto code_r0x0071e6e6;
        case 0x10ec:
          goto code_r0x0071e6f0;
        case 0x10ed:
          goto code_r0x0071e6fa;
        case 0x10ee:
          goto LAB_0071e704;
        case 0x10ef:
          goto code_r0x0071e70e;
        case 0x10f0:
          goto code_r0x0071e718;
        case 0x10f1:
          goto code_r0x0071e740;
        case 0x10f2:
          goto code_r0x0071e74a;
        case 0x10f3:
          goto code_r0x0071e754;
        case 0x10f4:
          goto code_r0x0071e75e;
        case 0x10fe:
          goto code_r0x0071e722;
        case 0x10ff:
          goto code_r0x0071e72c;
        case 0x1100:
          goto code_r0x0071e736;
        }
      }
      else if (param_1 < 0x138f) {
        if (param_1 == 0x138e) {
LAB_0071e813:
          return "ERROR_RESOURCE_NOT_AVAILABLE";
        }
        if (param_1 < 0x138a) {
          if (param_1 == 0x1389) {
LAB_0071e7d3:
            return "ERROR_DEPENDENT_RESOURCE_EXISTS";
          }
          if (param_1 == 0x1127) {
LAB_0071e7c9:
            return "ERROR_REPARSE_ATTRIBUTE_CONFLICT";
          }
          if (param_1 == 0x1128) {
LAB_0071e7bf:
            return "ERROR_INVALID_REPARSE_DATA";
          }
          if (param_1 == 0x1129) {
LAB_0071e7b5:
            return "ERROR_REPARSE_TAG_INVALID";
          }
          if (param_1 == 0x112a) {
LAB_00718362:
            return "ERROR_REPARSE_TAG_MISMATCH";
          }
          if (param_1 == 0x1194) goto LAB_0071e7ab;
        }
        else {
          if (param_1 == 0x138a) {
LAB_0071e809:
            return "ERROR_DEPENDENCY_NOT_FOUND";
          }
          if (param_1 == 0x138b) {
LAB_0071838d:
            return "ERROR_DEPENDENCY_ALREADY_EXISTS";
          }
          if (param_1 == 0x138c) goto LAB_0071e7ff;
          if (param_1 == 0x138d) goto LAB_0071e7f5;
        }
      }
      else {
        switch(param_1) {
        case 0x138f:
LAB_0071e832:
          return "ERROR_RESOURCE_NOT_FOUND";
        case 0x1390:
LAB_0071e83c:
          return "ERROR_SHUTDOWN_CLUSTER";
        case 0x1391:
LAB_0071e846:
          return "ERROR_CANT_EVICT_ACTIVE_NODE";
        case 0x1392:
LAB_0071e850:
          return "ERROR_OBJECT_ALREADY_EXISTS";
        case 0x1393:
code_r0x007183e4:
          return "ERROR_OBJECT_IN_LIST";
        case 0x1394:
LAB_0071e85a:
          return "ERROR_GROUP_NOT_AVAILABLE";
        case 0x1395:
code_r0x0071e864:
          return "ERROR_GROUP_NOT_FOUND";
        case 0x1396:
code_r0x0071e86e:
          return "ERROR_GROUP_NOT_ONLINE";
        case 0x1397:
code_r0x0071e878:
          return "ERROR_HOST_NODE_NOT_RESOURCE_OWNER";
        case 0x1398:
code_r0x0071e882:
          return "ERROR_HOST_NODE_NOT_GROUP_OWNER";
        }
      }
    }
    else if (param_1 < 0x1703) {
      if (param_1 == 0x1702) {
LAB_0071eb84:
        return "ERROR_CLUSTER_MEMBERSHIP_INVALID_STATE";
      }
      switch(param_1) {
      case 0x139a:
code_r0x0071e8be:
        return "ERROR_RESMON_ONLINE_FAILED";
      case 0x139b:
code_r0x0071e8c8:
        return "ERROR_RESOURCE_ONLINE";
      case 0x139c:
code_r0x0071e8d2:
        return "ERROR_QUORUM_RESOURCE";
      case 0x139d:
code_r0x0071e8dc:
        return "ERROR_NOT_QUORUM_CAPABLE";
      case 0x139e:
code_r0x0071e8e6:
        return "ERROR_CLUSTER_SHUTTING_DOWN";
      case 0x139f:
code_r0x0071e8f0:
        return "ERROR_INVALID_STATE";
      case 0x13a0:
code_r0x0071e8fa:
        return "ERROR_RESOURCE_PROPERTIES_STORED";
      case 0x13a1:
code_r0x0071e904:
        return "ERROR_NOT_QUORUM_CLASS";
      case 0x13a2:
code_r0x0071e90e:
        return "ERROR_CORE_RESOURCE";
      case 0x13a3:
code_r0x0071e918:
        return "ERROR_QUORUM_RESOURCE_ONLINE_FAILED";
      case 0x13a4:
LAB_0071e922:
        return "ERROR_QUORUMLOG_OPEN_FAILED";
      case 0x13a5:
code_r0x0071e92c:
        return "ERROR_CLUSTERLOG_CORRUPT";
      case 0x13a6:
code_r0x0071e936:
        return "ERROR_CLUSTERLOG_RECORD_EXCEEDS_MAXSIZE";
      case 0x13a7:
code_r0x0071e940:
        return "ERROR_CLUSTERLOG_EXCEEDS_MAXSIZE";
      case 0x13a8:
code_r0x0071e94a:
        return "ERROR_CLUSTERLOG_CHKPOINT_NOT_FOUND";
      case 0x13a9:
code_r0x0071e954:
        return "ERROR_CLUSTERLOG_NOT_ENOUGH_SPACE";
      case 0x13aa:
code_r0x0071e95e:
        return "ERROR_QUORUM_OWNER_ALIVE";
      case 0x13ab:
code_r0x0071e968:
        return "ERROR_NETWORK_NOT_AVAILABLE";
      case 0x13ac:
code_r0x0071e972:
        return "ERROR_NODE_NOT_AVAILABLE";
      case 0x13ad:
code_r0x0071e97c:
        return "ERROR_ALL_NODES_NOT_AVAILABLE";
      case 0x13ae:
code_r0x0071e986:
        return "ERROR_RESOURCE_FAILED";
      case 0x13af:
code_r0x0071e990:
        return "ERROR_CLUSTER_INVALID_NODE";
      case 0x13b0:
code_r0x0071e99a:
        return "ERROR_CLUSTER_NODE_EXISTS";
      case 0x13b1:
code_r0x0071e9a4:
        return "ERROR_CLUSTER_JOIN_IN_PROGRESS";
      case 0x13b2:
code_r0x0071e9ae:
        return "ERROR_CLUSTER_NODE_NOT_FOUND";
      case 0x13b3:
code_r0x0071e9b8:
        return "ERROR_CLUSTER_LOCAL_NODE_NOT_FOUND";
      case 0x13b4:
code_r0x0071e9c2:
        return "ERROR_CLUSTER_NETWORK_EXISTS";
      case 0x13b5:
code_r0x0071e9cc:
        return "ERROR_CLUSTER_NETWORK_NOT_FOUND";
      case 0x13b6:
code_r0x0071e9d6:
        return "ERROR_CLUSTER_NETINTERFACE_EXISTS";
      case 0x13b7:
code_r0x0071e9e0:
        return "ERROR_CLUSTER_NETINTERFACE_NOT_FOUND";
      case 0x13b8:
code_r0x0071e9ea:
        return "ERROR_CLUSTER_INVALID_REQUEST";
      case 0x13b9:
code_r0x0071e9f4:
        return "ERROR_CLUSTER_INVALID_NETWORK_PROVIDER";
      case 0x13ba:
code_r0x0071e9fe:
        return "ERROR_CLUSTER_NODE_DOWN";
      case 0x13bb:
code_r0x0071ea08:
        return "ERROR_CLUSTER_NODE_UNREACHABLE";
      case 0x13bc:
code_r0x0071ea12:
        return "ERROR_CLUSTER_NODE_NOT_MEMBER";
      case 0x13bd:
code_r0x0071ea1c:
        return "ERROR_CLUSTER_JOIN_NOT_IN_PROGRESS";
      case 0x13be:
code_r0x0071ea26:
        return "ERROR_CLUSTER_INVALID_NETWORK";
      case 0x13c0:
code_r0x0071ea30:
        return "ERROR_CLUSTER_NODE_UP";
      case 0x13c1:
code_r0x0071ea3a:
        return "ERROR_CLUSTER_IPADDR_IN_USE";
      case 0x13c2:
code_r0x0071ea44:
        return "ERROR_CLUSTER_NODE_NOT_PAUSED";
      case 0x13c3:
code_r0x0071ea4e:
        return "ERROR_CLUSTER_NO_SECURITY_CONTEXT";
      case 0x13c4:
code_r0x0071ea58:
        return "ERROR_CLUSTER_NETWORK_NOT_INTERNAL";
      case 0x13c5:
        goto LAB_0071ea62;
      case 0x13c6:
code_r0x0071ea6c:
        return "ERROR_CLUSTER_NODE_ALREADY_DOWN";
      case 0x13c7:
code_r0x0071ea76:
        return "ERROR_CLUSTER_NETWORK_ALREADY_ONLINE";
      case 0x13c8:
code_r0x0071ea80:
        return "ERROR_CLUSTER_NETWORK_ALREADY_OFFLINE";
      case 0x13c9:
code_r0x0071ea8a:
        return "ERROR_CLUSTER_NODE_ALREADY_MEMBER";
      case 0x13ca:
code_r0x0071ea94:
        return "ERROR_CLUSTER_LAST_INTERNAL_NETWORK";
      case 0x13cb:
code_r0x0071ea9e:
        return "ERROR_CLUSTER_NETWORK_HAS_DEPENDENTS";
      case 0x13cc:
code_r0x0071eaa8:
        return "ERROR_INVALID_OPERATION_ON_QUORUM";
      case 0x13cd:
code_r0x0071eab2:
        return "ERROR_DEPENDENCY_NOT_ALLOWED";
      case 0x13ce:
code_r0x0071eabc:
        return "ERROR_CLUSTER_NODE_PAUSED";
      case 0x13cf:
code_r0x0071eac6:
        return "ERROR_NODE_CANT_HOST_RESOURCE";
      case 0x13d0:
code_r0x0071ead0:
        return "ERROR_CLUSTER_NODE_NOT_READY";
      case 0x13d1:
code_r0x0071eada:
        return "ERROR_CLUSTER_NODE_SHUTTING_DOWN";
      case 0x13d2:
code_r0x0071eae4:
        return "ERROR_CLUSTER_JOIN_ABORTED";
      case 0x13d3:
code_r0x0071eaee:
        return "ERROR_CLUSTER_INCOMPATIBLE_VERSIONS";
      case 0x13d4:
code_r0x0071eaf8:
        return "ERROR_CLUSTER_MAXNUM_OF_RESOURCES_EXCEEDED";
      case 0x13d5:
code_r0x0071eb02:
        return "ERROR_CLUSTER_SYSTEM_CONFIG_CHANGED";
      case 0x13d6:
code_r0x0071eb0c:
        return "ERROR_CLUSTER_RESOURCE_TYPE_NOT_FOUND";
      case 0x13d7:
code_r0x0071eb16:
        return "ERROR_CLUSTER_RESTYPE_NOT_SUPPORTED";
      case 0x13d8:
code_r0x0071eb20:
        return "ERROR_CLUSTER_RESNAME_NOT_FOUND";
      case 0x13d9:
code_r0x0071eb2a:
        return "ERROR_CLUSTER_NO_RPC_PACKAGES_REGISTERED";
      case 0x13da:
code_r0x0071eb34:
        return "ERROR_CLUSTER_OWNER_NOT_IN_PREFLIST";
      case 0x13db:
code_r0x0071eb3e:
        return "ERROR_CLUSTER_DATABASE_SEQMISMATCH";
      case 0x13dc:
code_r0x0071eb48:
        return "ERROR_RESMON_INVALID_STATE";
      case 0x13dd:
code_r0x0071eb52:
        return "ERROR_CLUSTER_GUM_NOT_LOCKER";
      case 0x13de:
code_r0x0071eb5c:
        return "ERROR_QUORUM_DISK_NOT_FOUND";
      case 0x13df:
code_r0x0071eb66:
        return "ERROR_DATABASE_BACKUP_CORRUPT";
      case 0x13e0:
code_r0x0071eb70:
        return "ERROR_CLUSTER_NODE_ALREADY_HAS_DFS_ROOT";
      case 0x13e1:
code_r0x0071eb7a:
        return "ERROR_RESOURCE_PROPERTY_UNCHANGEABLE";
      }
    }
    else if (param_1 < 0x1771) {
      if (param_1 == 6000) {
LAB_0071ec16:
        return "ERROR_ENCRYPTION_FAILED";
      }
      switch(param_1) {
      case 0x1703:
code_r0x0071ebb2:
        return "ERROR_CLUSTER_QUORUMLOG_NOT_FOUND";
      case 0x1704:
code_r0x0071ebbc:
        return "ERROR_CLUSTER_MEMBERSHIP_HALT";
      case 0x1705:
code_r0x0071ebc6:
        return "ERROR_CLUSTER_INSTANCE_ID_MISMATCH";
      case 0x1706:
code_r0x0071ebd0:
        return "ERROR_CLUSTER_NETWORK_NOT_FOUND_FOR_IP";
      case 0x1707:
code_r0x0071ebda:
        return "ERROR_CLUSTER_PROPERTY_DATA_TYPE_MISMATCH";
      case 0x1708:
code_r0x0071ebe4:
        return "ERROR_CLUSTER_EVICT_WITHOUT_CLEANUP";
      case 0x1709:
code_r0x0071ebee:
        return "ERROR_CLUSTER_PARAMETER_MISMATCH";
      case 0x170a:
code_r0x0071ebf8:
        return "ERROR_NODE_CANNOT_BE_CLUSTERED";
      case 0x170b:
code_r0x0071ec02:
        return "ERROR_CLUSTER_WRONG_OS_VERSION";
      case 0x170c:
code_r0x0071ec0c:
        return "ERROR_CLUSTER_CANT_CREATE_DUP_CLUSTER_NAME";
      }
    }
    else if (param_1 < 0x17e7) {
      if (param_1 == 0x17e6) {
LAB_0071ece8:
        return "ERROR_NO_BROWSER_SERVERS_FOUND";
      }
      switch(param_1) {
      case 0x1771:
code_r0x0071ec48:
        return "ERROR_DECRYPTION_FAILED";
      case 0x1772:
code_r0x0071ec52:
        return "ERROR_FILE_ENCRYPTED";
      case 0x1773:
code_r0x0071ec5c:
        return "ERROR_NO_RECOVERY_POLICY";
      case 0x1774:
code_r0x0071ec66:
        return "ERROR_NO_EFS";
      case 0x1775:
code_r0x0071ec70:
        return "ERROR_WRONG_EFS";
      case 0x1776:
code_r0x0071ec7a:
        return "ERROR_NO_USER_KEYS";
      case 0x1777:
code_r0x0071ec84:
        return "ERROR_FILE_NOT_ENCRYPTED";
      case 0x1778:
code_r0x0071ec8e:
        return "ERROR_NOT_EXPORT_FORMAT";
      case 0x1779:
code_r0x0071ec98:
        return "ERROR_FILE_READ_ONLY";
      case 0x177a:
code_r0x0071eca2:
        return "ERROR_DIR_EFS_DISALLOWED";
      case 0x177b:
code_r0x0071ecac:
        return "ERROR_EFS_SERVER_NOT_TRUSTED";
      case 0x177c:
code_r0x0071ecb6:
        return "ERROR_BAD_RECOVERY_POLICY";
      case 0x177d:
code_r0x0071ecc0:
        return "ERROR_EFS_ALG_BLOB_TOO_BIG";
      case 0x177e:
code_r0x0071ecca:
        return "ERROR_VOLUME_NOT_SUPPORT_EFS";
      case 0x177f:
code_r0x0071ecd4:
        return "ERROR_EFS_DISABLED";
      case 0x1780:
code_r0x0071ecde:
        return "ERROR_EFS_VERSION_NOT_SUPPORT";
      }
    }
    else if (param_1 < 0x206e) {
      if (param_1 == 0x206d) goto LAB_0071f298;
      if (param_1 < 0x200b) {
        if (param_1 == 0x200a) {
LAB_0071f02b:
          return "ERROR_DS_NO_ATTRIBUTE_OR_VALUE";
        }
        if (param_1 < 0x1b86) {
          if (param_1 == 0x1b85) {
LAB_0071eeb2:
            return "ERROR_CTX_WINSTATION_ACCESS_DENIED";
          }
          if (param_1 < 0x1b67) {
            if (param_1 == 0x1b66) goto LAB_0071ee00;
            if (param_1 < 0x1b60) {
              if (param_1 == 0x1b5f) {
LAB_0071eda6:
                return "ERROR_CTX_CLOSE_PENDING";
              }
              if (param_1 == 0x1838) goto LAB_0071ed9c;
              if (param_1 == 0x1b59) goto LAB_0071ed92;
              if (param_1 == 0x1b5a) goto LAB_0071ed88;
              if (param_1 == 0x1b5b) goto LAB_0071ed7e;
              if (param_1 == 0x1b5c) goto LAB_00718501;
              if (param_1 == 0x1b5d) goto LAB_0071ed74;
              if (param_1 == 0x1b5e) goto LAB_0071ed6a;
            }
            else {
              if (param_1 == 0x1b60) {
LAB_0071edf6:
                return "ERROR_CTX_NO_OUTBUF";
              }
              if (param_1 == 0x1b61) {
LAB_0071edec:
                return "ERROR_CTX_MODEM_INF_NOT_FOUND";
              }
              if (param_1 == 0x1b62) {
LAB_00718542:
                return "ERROR_CTX_INVALID_MODEMNAME";
              }
              if (param_1 == 0x1b63) goto LAB_0071ede2;
              if (param_1 == 0x1b64) goto LAB_0071edd8;
              if (param_1 == 0x1b65) goto code_r0x0071edce;
            }
          }
          else {
            switch(param_1) {
            case 0x1b67:
              goto code_r0x0071ee26;
            case 0x1b68:
              goto code_r0x0071ee30;
            case 0x1b69:
              goto code_r0x0071ee3a;
            case 0x1b6e:
              goto code_r0x0071ee44;
            case 0x1b6f:
              goto code_r0x0071ee4e;
            case 0x1b70:
              goto code_r0x0071ee58;
            case 0x1b71:
              goto code_r0x0071ee62;
            case 0x1b7b:
              goto code_r0x0071ee6c;
            case 0x1b7d:
              goto LAB_0071ee76;
            case 0x1b7e:
              goto code_r0x0071ee80;
            case 0x1b80:
              goto code_r0x0071ee8a;
            case 0x1b81:
              goto code_r0x0071ee94;
            case 0x1b82:
              goto code_r0x0071ee9e;
            case 0x1b84:
              goto code_r0x0071eea8;
            }
          }
        }
        else if (param_1 < 0x1f42) {
          if (param_1 == 0x1f41) goto LAB_0071ef44;
          switch(param_1) {
          case 0x1b89:
            goto code_r0x0071eee0;
          case 0x1b8a:
            goto code_r0x0071eeea;
          case 0x1b8b:
            goto code_r0x0071eef4;
          case 0x1b8c:
            goto code_r0x0071eefe;
          case 0x1b8d:
            goto code_r0x0071ef08;
          case 0x1b8e:
            goto code_r0x0071ef12;
          case 0x1b8f:
            goto code_r0x0071ef1c;
          case 0x1b90:
            goto code_r0x0071ef26;
          case 0x1b91:
            goto code_r0x0071ef30;
          case 0x1b92:
            goto code_r0x0071ef3a;
          }
        }
        else if (param_1 < 0x2009) {
          if (param_1 == 0x2008) goto LAB_0071f00c;
          switch(param_1) {
          case 0x1f42:
            goto LAB_0071ef76;
          case 0x1f43:
            goto LAB_0071ef80;
          case 0x1f44:
            goto LAB_0071ef8a;
          case 0x1f45:
LAB_0071ef94:
            return "FRS_ERR_INTERNAL";
          case 0x1f46:
code_r0x007185c3:
            return "FRS_ERR_SERVICE_COMM";
          case 0x1f47:
            goto LAB_0071ef9e;
          case 0x1f48:
            goto code_r0x0071efa8;
          case 0x1f49:
            goto code_r0x0071efb2;
          case 0x1f4a:
            goto code_r0x0071efbc;
          case 0x1f4b:
            goto code_r0x0071efc6;
          case 0x1f4c:
            goto code_r0x0071efd0;
          case 0x1f4d:
            goto code_r0x0071efda;
          case 0x1f4e:
            goto code_r0x0071efe4;
          case 0x1f4f:
            goto code_r0x0071efee;
          case 0x1f50:
            goto code_r0x0071eff8;
          case 0x1f51:
            goto code_r0x0071f002;
          }
        }
        else if (param_1 == 0x2009) goto code_r0x0071f021;
      }
      else {
        switch(param_1) {
        case 0x200b:
code_r0x0071f04a:
          return "ERROR_DS_INVALID_ATTRIBUTE_SYNTAX";
        case 0x200c:
code_r0x0071f054:
          return "ERROR_DS_ATTRIBUTE_TYPE_UNDEFINED";
        case 0x200d:
code_r0x0071f05e:
          return "ERROR_DS_ATTRIBUTE_OR_VALUE_EXISTS";
        case 0x200e:
code_r0x0071f068:
          return "ERROR_DS_BUSY";
        case 0x200f:
code_r0x0071f072:
          return "ERROR_DS_UNAVAILABLE";
        case 0x2010:
code_r0x0071f07c:
          return "ERROR_DS_NO_RIDS_ALLOCATED";
        case 0x2011:
code_r0x0071f086:
          return "ERROR_DS_NO_MORE_RIDS";
        case 0x2012:
code_r0x0071f090:
          return "ERROR_DS_INCORRECT_ROLE_OWNER";
        case 0x2013:
code_r0x0071f09a:
          return "ERROR_DS_RIDMGR_INIT_ERROR";
        case 0x2014:
code_r0x0071f0a4:
          return "ERROR_DS_OBJ_CLASS_VIOLATION";
        case 0x2015:
code_r0x0071f0ae:
          return "ERROR_DS_CANT_ON_NON_LEAF";
        case 0x2016:
code_r0x0071f0b8:
          return "ERROR_DS_CANT_ON_RDN";
        case 0x2017:
code_r0x0071f0c2:
          return "ERROR_DS_CANT_MOD_OBJ_CLASS";
        case 0x2018:
code_r0x0071f0cc:
          return "ERROR_DS_CROSS_DOM_MOVE_ERROR";
        case 0x2019:
code_r0x0071f0d6:
          return "ERROR_DS_GC_NOT_AVAILABLE";
        case 0x201a:
code_r0x0071f0e0:
          return "ERROR_SHARED_POLICY";
        case 0x201b:
code_r0x0071f0ea:
          return "ERROR_POLICY_OBJECT_NOT_FOUND";
        case 0x201c:
code_r0x0071f0f4:
          return "ERROR_POLICY_ONLY_IN_DS";
        case 0x201d:
code_r0x0071f0fe:
          return "ERROR_PROMOTION_ACTIVE";
        case 0x201e:
code_r0x0071f108:
          return "ERROR_NO_PROMOTION_ACTIVE";
        case 0x2020:
code_r0x0071f112:
          return "ERROR_DS_OPERATIONS_ERROR";
        case 0x2021:
code_r0x0071f11c:
          return "ERROR_DS_PROTOCOL_ERROR";
        case 0x2022:
code_r0x0071f126:
          return "ERROR_DS_TIMELIMIT_EXCEEDED";
        case 0x2023:
code_r0x0071f130:
          return "ERROR_DS_SIZELIMIT_EXCEEDED";
        case 0x2024:
code_r0x0071f13a:
          return "ERROR_DS_ADMIN_LIMIT_EXCEEDED";
        case 0x2025:
code_r0x0071f144:
          return "ERROR_DS_COMPARE_FALSE";
        case 0x2026:
code_r0x0071f14e:
          return "ERROR_DS_COMPARE_TRUE";
        case 0x2027:
code_r0x0071f158:
          return "ERROR_DS_AUTH_METHOD_NOT_SUPPORTED";
        case 0x2028:
code_r0x0071f162:
          return "ERROR_DS_STRONG_AUTH_REQUIRED";
        case 0x2029:
code_r0x0071f16c:
          return "ERROR_DS_INAPPROPRIATE_AUTH";
        case 0x202a:
code_r0x0071f176:
          return "ERROR_DS_AUTH_UNKNOWN";
        case 0x202b:
code_r0x0071f180:
          return "ERROR_DS_REFERRAL";
        case 0x202c:
          goto LAB_0071f18a;
        case 0x202d:
          goto code_r0x0071f194;
        case 0x202e:
          goto code_r0x0071f19e;
        case 0x202f:
          goto code_r0x0071f1a8;
        case 0x2030:
          goto code_r0x0071f1b2;
        case 0x2031:
          goto code_r0x0071f1bc;
        case 0x2032:
          goto code_r0x0071f1c6;
        case 0x2033:
          goto code_r0x0071f1d0;
        case 0x2034:
          goto code_r0x0071f1da;
        case 0x2035:
          goto code_r0x0071f1e4;
        case 0x2036:
          goto code_r0x0071f1ee;
        case 0x2037:
          goto code_r0x0071f1f8;
        case 0x2038:
          goto code_r0x0071f202;
        case 0x2039:
          goto code_r0x0071f20c;
        case 0x203a:
          goto code_r0x0071f216;
        case 0x203b:
          goto code_r0x0071f220;
        case 0x203c:
          goto code_r0x0071f22a;
        case 0x203d:
          goto code_r0x0071f234;
        case 0x203e:
          goto code_r0x0071f23e;
        case 0x203f:
          goto code_r0x0071f248;
        case 0x2040:
          goto code_r0x0071f252;
        case 0x2041:
          goto code_r0x0071f25c;
        case 0x2042:
          goto code_r0x0071f266;
        case 0x2043:
          goto code_r0x0071f270;
        case 0x2044:
          goto code_r0x0071f27a;
        case 0x2045:
          goto code_r0x0071f284;
        case 0x2046:
          goto code_r0x0071f28e;
        }
      }
    }
    else {
      switch(param_1) {
      case 0x206e:
        goto code_r0x0071f2b7;
      case 0x206f:
        goto code_r0x0071f2c1;
      case 0x2070:
        goto code_r0x0071f2cb;
      case 0x2071:
        goto code_r0x0071f2d5;
      case 0x2072:
        goto code_r0x0071f2df;
      case 0x2073:
        goto code_r0x0071f2e9;
      case 0x2074:
        goto code_r0x0071f2f3;
      case 0x2075:
        goto code_r0x0071f2fd;
      case 0x2076:
        goto code_r0x0071f307;
      case 0x2077:
        goto code_r0x0071f311;
      case 0x2078:
        goto code_r0x0071f31b;
      case 0x2079:
        goto code_r0x0071f325;
      case 0x207a:
        goto code_r0x0071f32f;
      case 0x207b:
        goto code_r0x0071f339;
      case 0x207c:
        goto code_r0x0071f343;
      case 0x207d:
        goto code_r0x0071f34d;
      case 0x207e:
        goto code_r0x0071f357;
      case 0x2080:
        goto code_r0x0071f361;
      case 0x2081:
        goto code_r0x0071f36b;
      case 0x2082:
        goto code_r0x0071f375;
      case 0x2083:
        goto code_r0x0071f37f;
      case 0x2084:
        goto code_r0x0071f389;
      case 0x2085:
        goto code_r0x0071f393;
      case 0x2086:
        goto code_r0x0071f39d;
      case 0x2087:
        goto code_r0x0071f3a7;
      case 0x2088:
        goto code_r0x0071f3b1;
      case 0x2089:
        goto code_r0x0071f3bb;
      case 0x208a:
        goto code_r0x0071f3c5;
      case 0x208b:
        goto code_r0x0071f3cf;
      case 0x208c:
        goto code_r0x0071f3d9;
      case 0x208d:
        goto code_r0x0071f3e3;
      case 0x208e:
        goto code_r0x0071f3ed;
      case 0x208f:
        goto code_r0x0071f3f7;
      case 0x2090:
        goto code_r0x0071f401;
      case 0x2091:
        goto code_r0x0071f40b;
      case 0x2092:
        goto code_r0x0071f415;
      case 0x2093:
        goto code_r0x0071f753;
      case 0x2094:
        goto code_r0x0071f41f;
      case 0x2095:
        goto code_r0x0071f429;
      case 0x2096:
        goto code_r0x0071f433;
      case 0x2097:
        goto code_r0x0071f43d;
      case 0x2098:
        goto code_r0x0071f447;
      case 0x2099:
        goto code_r0x0071f451;
      case 0x209a:
        goto code_r0x0071f45b;
      case 0x209b:
        goto code_r0x0071f465;
      case 0x209c:
        goto code_r0x0071f46f;
      case 0x209d:
        goto code_r0x0071f479;
      case 0x209e:
        goto code_r0x0071f483;
      case 0x209f:
        goto code_r0x0071f48d;
      case 0x20a0:
        goto code_r0x0071f497;
      case 0x20a1:
        goto code_r0x0071f4a1;
      case 0x20a2:
        goto code_r0x0071f4ab;
      case 0x20a3:
        goto code_r0x0071f4b5;
      case 0x20a4:
        goto code_r0x0071f4bf;
      case 0x20a5:
        goto code_r0x0071f4c9;
      case 0x20a6:
        goto code_r0x0071f4d3;
      case 0x20a7:
        goto code_r0x0071f4dd;
      case 0x20a8:
        goto code_r0x0071f4e7;
      case 0x20a9:
        goto code_r0x0071f4f1;
      case 0x20aa:
        goto code_r0x0071f4fb;
      case 0x20ab:
        goto code_r0x0071f505;
      case 0x20ac:
        goto code_r0x0071f50f;
      case 0x20ad:
        goto code_r0x0071f519;
      case 0x20ae:
        goto code_r0x0071f523;
      case 0x20af:
        goto code_r0x0071f52d;
      case 0x20b0:
        goto code_r0x0071f537;
      case 0x20b1:
        goto code_r0x0071f541;
      case 0x20b2:
        goto code_r0x0071f54b;
      case 0x20b3:
        goto code_r0x0071f555;
      case 0x20b4:
        goto code_r0x0071f55f;
      case 0x20b5:
        goto code_r0x0071f569;
      case 0x20b6:
        goto code_r0x0071f573;
      case 0x20b7:
        goto code_r0x0071f57d;
      case 0x20b8:
        goto code_r0x0071f587;
      case 0x20b9:
        goto code_r0x0071f591;
      case 0x20ba:
        goto code_r0x0071f59b;
      case 0x20bb:
        goto code_r0x0071f5a5;
      case 0x20bc:
        goto code_r0x0071f5af;
      case 0x20bd:
        goto code_r0x0071f5b9;
      case 0x20be:
        goto code_r0x0071f5c3;
      case 0x20bf:
        goto code_r0x0071f5cd;
      case 0x20c0:
        goto code_r0x0071f5d7;
      case 0x20c1:
        goto code_r0x0071f5e1;
      case 0x20c2:
        goto code_r0x0071f5eb;
      case 0x20c3:
        goto code_r0x0071f5f5;
      case 0x20c4:
        goto code_r0x0071f5ff;
      case 0x20c5:
        goto code_r0x0071f609;
      case 0x20c6:
        goto code_r0x0071f613;
      case 0x20c7:
        goto code_r0x0071f61d;
      case 0x20c8:
        goto code_r0x0071f627;
      case 0x20c9:
        goto code_r0x0071f631;
      case 0x20ca:
        goto code_r0x0071f63b;
      case 0x20cb:
        goto code_r0x0071f645;
      case 0x20cc:
        goto code_r0x0071f64f;
      case 0x20cd:
        goto code_r0x0071f659;
      case 0x20ce:
        goto code_r0x0071f663;
      case 0x20cf:
        goto code_r0x0071f66d;
      case 0x20d0:
        goto code_r0x0071f677;
      case 0x20d1:
        goto code_r0x0071f681;
      case 0x20d2:
        goto code_r0x0071f68b;
      case 0x20d3:
        goto code_r0x0071f695;
      case 0x20d4:
        goto code_r0x0071f69f;
      case 0x20d5:
        goto code_r0x0071f6a9;
      case 0x20d6:
        goto code_r0x0071f6b3;
      case 0x20d7:
        goto code_r0x0071f6bd;
      case 0x20d8:
        goto code_r0x0071f6c7;
      case 0x20d9:
        goto code_r0x0071f6d1;
      case 0x20da:
        goto code_r0x0071f6db;
      case 0x20db:
        goto code_r0x0071f6e5;
      case 0x20dc:
        goto code_r0x0071f6ef;
      case 0x20dd:
        goto code_r0x0071f6f9;
      case 0x20de:
        goto code_r0x0071f703;
      case 0x20df:
        goto code_r0x0071f70d;
      case 0x20e0:
        goto code_r0x0071f717;
      case 0x20e1:
        goto code_r0x0071f721;
      case 0x20e2:
        goto code_r0x0071f72b;
      case 0x20e3:
        goto code_r0x0071f735;
      case 0x20e4:
        goto code_r0x0071f73f;
      case 0x20e5:
        goto code_r0x0071f749;
      }
    }
  }
  else if (param_1 < 0x2329) {
    if (param_1 == 9000) goto LAB_0071fe8f;
    switch(param_1) {
    case 0x20e7:
      goto code_r0x0071f791;
    case 0x20e8:
      goto code_r0x0071f79b;
    case 0x20e9:
      goto code_r0x0071f7a5;
    case 0x20ea:
      goto code_r0x0071f7af;
    case 0x20eb:
      goto code_r0x0071f7b9;
    case 0x20ec:
      goto code_r0x0071f7c3;
    case 0x20ed:
      goto code_r0x0071f7cd;
    case 0x20ee:
      goto code_r0x0071f7d7;
    case 0x20ef:
      goto code_r0x0071f7e1;
    case 0x20f0:
      goto code_r0x0071f7eb;
    case 0x20f1:
      goto code_r0x0071f7f5;
    case 0x20f2:
      goto code_r0x0071f7ff;
    case 0x20f3:
      goto code_r0x0071f809;
    case 0x20f4:
      goto code_r0x0071f813;
    case 0x20f5:
      goto code_r0x0071f81d;
    case 0x20f6:
      goto code_r0x0071f827;
    case 0x20f7:
      goto code_r0x0071f831;
    case 0x20f8:
      goto code_r0x0071f83b;
    case 0x20f9:
      goto code_r0x0071f845;
    case 0x20fa:
      goto code_r0x0071f84f;
    case 0x20fb:
      goto code_r0x0071f859;
    case 0x20fc:
      goto code_r0x0071f863;
    case 0x20fd:
      goto code_r0x0071f86d;
    case 0x20fe:
      goto code_r0x0071f877;
    case 0x20ff:
      goto code_r0x0071f881;
    case 0x2100:
      goto code_r0x0071f88b;
    case 0x2101:
      goto code_r0x0071f895;
    case 0x2102:
      goto code_r0x0071f89f;
    case 0x2103:
      goto code_r0x0071f8a9;
    case 0x2104:
      goto code_r0x0071f8b3;
    case 0x2105:
      goto code_r0x0071f8bd;
    case 0x2106:
      goto code_r0x0071f8c7;
    case 0x2107:
      goto code_r0x0071f8d1;
    case 0x2108:
      goto code_r0x0071f8db;
    case 0x2109:
      goto code_r0x0071f8e5;
    case 0x210a:
      goto code_r0x0071f8ef;
    case 0x210b:
      goto code_r0x0071f8f9;
    case 0x210c:
      goto code_r0x0071f903;
    case 0x210d:
      goto code_r0x0071f90d;
    case 0x210e:
      goto code_r0x0071f917;
    case 0x210f:
      goto code_r0x0071f921;
    case 0x2110:
      goto code_r0x0071f92b;
    case 0x2111:
      goto code_r0x0071f935;
    case 0x2112:
      goto code_r0x0071f93f;
    case 0x2113:
      goto code_r0x0071f949;
    case 0x2114:
      goto code_r0x0071f953;
    case 0x2115:
      goto code_r0x0071f95d;
    case 0x2116:
      goto code_r0x0071f967;
    case 0x2117:
      goto code_r0x0071f971;
    case 0x2118:
      goto code_r0x0071f97b;
    case 0x2119:
      goto code_r0x0071f985;
    case 0x211a:
      goto code_r0x0071f98f;
    case 0x211b:
      goto code_r0x0071f999;
    case 0x211c:
      goto code_r0x0071f9a3;
    case 0x211d:
      goto code_r0x0071f9ad;
    case 0x211e:
      goto code_r0x0071f9b7;
    case 0x211f:
      goto code_r0x0071f9c1;
    case 0x2120:
      goto code_r0x0071f9cb;
    case 0x2121:
      goto code_r0x0071f9d5;
    case 0x2122:
      goto code_r0x0071f9df;
    case 0x2123:
      goto code_r0x0071f9e9;
    case 0x2124:
      goto code_r0x0071f9f3;
    case 0x2125:
      goto code_r0x0071f9fd;
    case 0x2126:
      goto code_r0x0071fa07;
    case 0x2127:
      goto code_r0x0071fa11;
    case 0x2128:
      goto code_r0x0071fa1b;
    case 0x2129:
      goto code_r0x0071fa25;
    case 0x212a:
      goto code_r0x0071fa2f;
    case 0x212b:
      goto code_r0x0071fa39;
    case 0x212c:
      goto code_r0x0071fa43;
    case 0x212d:
      goto code_r0x0071fa4d;
    case 0x212e:
      goto code_r0x0071fa57;
    case 0x212f:
      goto code_r0x0071fa61;
    case 0x2130:
      goto code_r0x0071fa6b;
    case 0x2131:
      goto code_r0x0071fa75;
    case 0x2132:
      goto code_r0x0071fa7f;
    case 0x2133:
      goto code_r0x0071fa89;
    case 0x2134:
      goto code_r0x0071fa93;
    case 0x2135:
      goto code_r0x0071fa9d;
    case 0x2136:
      goto code_r0x0071faa7;
    case 0x2137:
      goto code_r0x0071fab1;
    case 0x2138:
      goto code_r0x0071fabb;
    case 0x2139:
      goto code_r0x0071fac5;
    case 0x213a:
      goto code_r0x0071facf;
    case 0x213b:
      goto code_r0x0071fad9;
    case 0x213c:
      goto code_r0x0071fae3;
    case 0x213d:
      goto code_r0x0071faed;
    case 0x213e:
      goto code_r0x0071faf7;
    case 0x213f:
      goto code_r0x0071fb01;
    case 0x2140:
      goto code_r0x0071fb0b;
    case 0x2141:
      goto code_r0x0071fb15;
    case 0x2142:
      goto code_r0x0071fb1f;
    case 0x2143:
      goto code_r0x0071fb29;
    case 0x2144:
      goto code_r0x0071fb33;
    case 0x2145:
      goto code_r0x0071fb3d;
    case 0x2146:
      goto code_r0x0071fb47;
    case 0x2147:
      goto code_r0x0071fb51;
    case 0x2148:
      goto code_r0x0071fb5b;
    case 0x2149:
      goto code_r0x0071fb65;
    case 0x214a:
      goto code_r0x0071fb6f;
    case 0x214b:
      goto code_r0x0071fb79;
    case 0x214c:
      goto code_r0x0071fb83;
    case 0x214d:
      goto code_r0x0071fb8d;
    case 0x214e:
      goto code_r0x0071fb97;
    case 0x214f:
      goto code_r0x0071fba1;
    case 0x2150:
      goto code_r0x0071fbab;
    case 0x2151:
      goto code_r0x0071fbb5;
    case 0x2152:
      goto code_r0x0071fbbf;
    case 0x2153:
      goto code_r0x0071fbc9;
    case 0x2154:
      goto code_r0x0071fbd3;
    case 0x2155:
      goto code_r0x0071fbdd;
    case 0x2156:
      goto code_r0x0071fbe7;
    case 0x2157:
      goto code_r0x0071fbf1;
    case 0x2158:
      goto code_r0x0071fbfb;
    case 0x2159:
      goto code_r0x0071fc05;
    case 0x215a:
      goto code_r0x0071fc0f;
    case 0x215b:
      goto code_r0x0071fc19;
    case 0x215c:
      goto code_r0x0071fc23;
    case 0x215d:
      goto code_r0x0071fc2d;
    case 0x215e:
      goto code_r0x0071fc37;
    case 0x215f:
      goto code_r0x0071fc41;
    case 0x2160:
      goto code_r0x0071fc4b;
    case 0x2161:
      goto code_r0x0071fc55;
    case 0x2162:
      goto code_r0x0071fc5f;
    case 0x2163:
      goto code_r0x0071fc69;
    case 0x2164:
      goto code_r0x0071fc73;
    case 0x2165:
      goto code_r0x0071fc7d;
    case 0x2166:
      goto code_r0x0071fc87;
    case 0x2167:
      goto code_r0x0071fc91;
    case 0x2168:
      goto code_r0x0071fc9b;
    case 0x2169:
      goto code_r0x0071fca5;
    case 0x216a:
      goto code_r0x0071fcaf;
    case 0x216b:
      goto code_r0x0071fcb9;
    case 0x216c:
      goto code_r0x0071fcc3;
    case 0x216d:
      goto code_r0x0071fccd;
    case 0x216e:
      goto code_r0x0071fcd7;
    case 0x216f:
      goto code_r0x0071fce1;
    case 0x2170:
      goto code_r0x0071fceb;
    case 0x2171:
      goto code_r0x0071fcf5;
    case 0x2172:
      goto code_r0x0071fcff;
    case 0x2173:
      goto code_r0x0071fd09;
    case 0x2174:
      goto code_r0x0071fd13;
    case 0x2175:
      goto code_r0x0071fd1d;
    case 0x2176:
      goto code_r0x0071fd27;
    case 0x2177:
      goto code_r0x0071fd31;
    case 0x2178:
      goto code_r0x0071fd3b;
    case 0x2179:
      goto code_r0x0071fd45;
    case 0x217a:
      goto code_r0x0071fd4f;
    case 0x217b:
      goto code_r0x0071fd59;
    case 0x217c:
      goto code_r0x0071fd63;
    case 0x217d:
      goto code_r0x0071fd6d;
    case 0x217e:
      goto code_r0x0071fd77;
    case 0x217f:
      goto code_r0x0071fd81;
    case 0x2180:
      goto LAB_0071fd8b;
    case 0x2181:
      goto code_r0x0071fd95;
    case 0x2182:
      goto code_r0x0071fd9f;
    case 0x2183:
      goto code_r0x0071fda9;
    case 0x2184:
      goto code_r0x0071fdb3;
    case 0x2185:
      goto code_r0x0071fdbd;
    case 0x2186:
      goto code_r0x0071fdc7;
    case 0x2187:
      goto code_r0x0071fdd1;
    case 0x2188:
      goto code_r0x0071fddb;
    case 0x2189:
      goto code_r0x0071fde5;
    case 0x218a:
      goto code_r0x0071fdef;
    case 0x218b:
      goto code_r0x0071fdf9;
    case 0x218c:
      goto code_r0x0071fe03;
    case 0x218d:
      goto code_r0x0071fe0d;
    case 0x218e:
      goto code_r0x0071fe17;
    case 0x218f:
      goto code_r0x0071fe21;
    case 0x2190:
      goto code_r0x0071fe2b;
    case 0x2191:
      goto code_r0x0071fe35;
    case 0x2192:
      goto code_r0x0071fe3f;
    case 0x2193:
      goto code_r0x0071fe49;
    case 0x2194:
      goto code_r0x0071fe53;
    case 0x2195:
      goto code_r0x0071fe5d;
    case 0x2196:
      goto code_r0x0071fe67;
    case 0x2197:
      goto code_r0x0071fe71;
    case 0x2198:
      goto code_r0x0071fe7b;
    case 0x2199:
      goto code_r0x0071fe85;
    }
  }
  else if (param_1 < 0x251d) {
    if (param_1 == 0x251c) goto LAB_0071ff43;
    switch(param_1) {
    case 0x2329:
      goto code_r0x0071fec1;
    case 0x232a:
      goto code_r0x0071fecb;
    case 0x232b:
      goto code_r0x0071fed5;
    case 0x232c:
      goto code_r0x0071fedf;
    case 0x232d:
      goto code_r0x0071fee9;
    case 0x232e:
      goto code_r0x0071fef3;
    case 0x232f:
      goto code_r0x0071fefd;
    case 0x2330:
      goto code_r0x0071ff07;
    case 0x2331:
      goto code_r0x0071ff11;
    case 0x2332:
      goto code_r0x0071ff1b;
    case 0x2338:
      goto code_r0x0071ff25;
    case 0x2339:
      goto code_r0x0071ff2f;
    case 0x233a:
      goto code_r0x0071ff39;
    }
  }
  else if (param_1 < 0x361e) {
    if (param_1 == 0x361d) {
LAB_00720a19:
      return "ERROR_IPSEC_IKE_FAILSSPINIT";
    }
    if (param_1 < 0x276c) {
      if (param_1 == 0x276b) {
LAB_00720405:
        return "WSASYSNOTREADY";
      }
      if (param_1 - 0x251dU < 0x23b) {
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
        switch((&DAT_00724b3c)[param_1]) {
        case 0:
code_r0x0071ff91:
          return "DNS_INFO_NO_RECORDS";
        case 1:
code_r0x0071ff9b:
          return "DNS_ERROR_BAD_PACKET";
        case 2:
code_r0x0071ffa5:
          return "DNS_ERROR_NO_PACKET";
        case 3:
code_r0x0071ffaf:
          return "DNS_ERROR_RCODE";
        case 4:
code_r0x0071ffb9:
          return "DNS_ERROR_UNSECURE_PACKET";
        case 5:
code_r0x0071ffc3:
          return "DNS_ERROR_GENERAL_API_BASE";
        case 6:
code_r0x0071ffcd:
          return "DNS_ERROR_INVALID_TYPE";
        case 7:
code_r0x0071ffd7:
          return "DNS_ERROR_INVALID_IP_ADDRESS";
        case 8:
code_r0x0071ffe1:
          return "DNS_ERROR_INVALID_PROPERTY";
        case 9:
code_r0x0071ffeb:
          return "DNS_ERROR_TRY_AGAIN_LATER";
        case 10:
code_r0x0071fff5:
          return "DNS_ERROR_NOT_UNIQUE";
        case 0xb:
code_r0x0071ffff:
          return "DNS_ERROR_NON_RFC_NAME";
        case 0xc:
code_r0x00720009:
          return "DNS_STATUS_FQDN";
        case 0xd:
code_r0x00720013:
          return "DNS_STATUS_DOTTED_NAME";
        case 0xe:
code_r0x0072001d:
          return "DNS_STATUS_SINGLE_PART_NAME";
        case 0xf:
code_r0x00720027:
          return "DNS_ERROR_ZONE_BASE";
        case 0x10:
code_r0x00720031:
          return "DNS_ERROR_ZONE_DOES_NOT_EXIST";
        case 0x11:
code_r0x0072003b:
          return "DNS_ERROR_NO_ZONE_INFO";
        case 0x12:
code_r0x00720045:
          return "DNS_ERROR_INVALID_ZONE_OPERATION";
        case 0x13:
code_r0x0072004f:
          return "DNS_ERROR_ZONE_CONFIGURATION_ERROR";
        case 0x14:
code_r0x00720059:
          return "DNS_ERROR_ZONE_HAS_NO_SOA_RECORD";
        case 0x15:
code_r0x00720063:
          return "DNS_ERROR_ZONE_HAS_NO_NS_RECORDS";
        case 0x16:
code_r0x0072006d:
          return "DNS_ERROR_ZONE_LOCKED";
        case 0x17:
code_r0x00720077:
          return "DNS_ERROR_ZONE_CREATION_FAILED";
        case 0x18:
code_r0x00720081:
          return "DNS_ERROR_ZONE_ALREADY_EXISTS";
        case 0x19:
code_r0x0072008b:
          return "DNS_ERROR_AUTOZONE_ALREADY_EXISTS";
        case 0x1a:
code_r0x00720095:
          return "DNS_ERROR_INVALID_ZONE_TYPE";
        case 0x1b:
code_r0x0072009f:
          return "DNS_ERROR_SECONDARY_REQUIRES_MASTER_IP";
        case 0x1c:
code_r0x007200a9:
          return "DNS_ERROR_ZONE_NOT_SECONDARY";
        case 0x1d:
code_r0x007200b3:
          return "DNS_ERROR_NEED_SECONDARY_ADDRESSES";
        case 0x1e:
code_r0x007200bd:
          return "DNS_ERROR_WINS_INIT_FAILED";
        case 0x1f:
code_r0x007200c7:
          return "DNS_ERROR_NEED_WINS_SERVERS";
        case 0x20:
code_r0x007200d1:
          return "DNS_ERROR_NBSTAT_INIT_FAILED";
        case 0x21:
code_r0x007200db:
          return "DNS_ERROR_SOA_DELETE_INVALID";
        case 0x22:
code_r0x007203bf:
          return "DNS_ERROR_FORWARDER_ALREADY_EXISTS";
        case 0x23:
LAB_007203c9:
          return "DNS_ERROR_ZONE_REQUIRES_MASTER_IP";
        case 0x24:
LAB_007203d3:
          return "DNS_ERROR_ZONE_IS_SHUTDOWN";
        case 0x25:
LAB_007200e5:
          return "DNS_ERROR_DATAFILE_BASE";
        case 0x26:
LAB_007200ef:
          return "DNS_ERROR_PRIMARY_REQUIRES_DATAFILE";
        case 0x27:
code_r0x00718724:
          return "DNS_ERROR_INVALID_DATAFILE_NAME";
        case 0x28:
LAB_007200f9:
          return "DNS_ERROR_DATAFILE_OPEN_FAILURE";
        case 0x29:
LAB_00720103:
          return "DNS_ERROR_FILE_WRITEBACK_FAILED";
        case 0x2a:
LAB_0072010d:
          return "DNS_ERROR_DATAFILE_PARSING";
        case 0x2b:
code_r0x0071874f:
          return "DNS_ERROR_DATABASE_BASE";
        case 0x2c:
LAB_00720117:
          return "DNS_ERROR_RECORD_DOES_NOT_EXIST";
        case 0x2d:
LAB_00720121:
          return "DNS_ERROR_RECORD_FORMAT";
        case 0x2e:
LAB_0072012b:
          return "DNS_ERROR_NODE_CREATION_FAILED";
        case 0x2f:
LAB_00720135:
          return "DNS_ERROR_UNKNOWN_RECORD_TYPE";
        case 0x30:
LAB_0072013f:
          return "DNS_ERROR_RECORD_TIMED_OUT";
        case 0x31:
LAB_00720149:
          return "DNS_ERROR_NAME_NOT_IN_ZONE";
        case 0x32:
LAB_00720153:
          return "DNS_ERROR_CNAME_LOOP";
        case 0x33:
LAB_0072015d:
          return "DNS_ERROR_NODE_IS_CNAME";
        case 0x34:
LAB_00720167:
          return "DNS_ERROR_CNAME_COLLISION";
        case 0x35:
LAB_00720171:
          return "DNS_ERROR_RECORD_ONLY_AT_ZONE_ROOT";
        case 0x36:
LAB_0072017b:
          return "DNS_ERROR_RECORD_ALREADY_EXISTS";
        case 0x37:
LAB_00720185:
          return "DNS_ERROR_SECONDARY_DATA";
        case 0x38:
LAB_0072018f:
          return "DNS_ERROR_NO_CREATE_CACHE_DATA";
        case 0x39:
LAB_00720199:
          return "DNS_ERROR_NAME_DOES_NOT_EXIST";
        case 0x3a:
LAB_007201a3:
          return "DNS_WARNING_PTR_CREATE_FAILED";
        case 0x3b:
LAB_007201ad:
          return "DNS_WARNING_DOMAIN_UNDELETED";
        case 0x3c:
LAB_007201b7:
          return "DNS_ERROR_DS_UNAVAILABLE";
        case 0x3d:
LAB_007201c1:
          return "DNS_ERROR_DS_ZONE_ALREADY_EXISTS";
        case 0x3e:
LAB_007201cb:
          return "DNS_ERROR_NO_BOOTFILE_IF_DS_ZONE";
        case 0x3f:
LAB_007201d5:
          return "DNS_ERROR_OPERATION_BASE";
        case 0x40:
LAB_007201df:
          return "DNS_INFO_AXFR_COMPLETE";
        case 0x41:
LAB_007201e9:
          return "DNS_ERROR_AXFR";
        case 0x42:
LAB_007201f3:
          return "DNS_INFO_ADDED_LOCAL_WINS";
        case 0x43:
LAB_007201fd:
          return "DNS_ERROR_SECURE_BASE";
        case 0x44:
LAB_00720207:
          return "DNS_STATUS_CONTINUE_NEEDED";
        case 0x45:
code_r0x007187d4:
          return "DNS_ERROR_SETUP_BASE";
        case 0x46:
          goto LAB_00720211;
        case 0x47:
LAB_0072021b:
          return "DNS_ERROR_NO_DNS_SERVERS";
        case 0x48:
LAB_007203dd:
          return "DNS_ERROR_DP_BASE";
        case 0x49:
LAB_007203e7:
          return "DNS_ERROR_DP_DOES_NOT_EXIST";
        case 0x4a:
code_r0x0071884a:
          return "DNS_ERROR_DP_ALREADY_EXISTS";
        case 0x4b:
LAB_007203f1:
          return "DNS_ERROR_DP_NOT_ENLISTED";
        case 0x4c:
LAB_007203fb:
          return "DNS_ERROR_DP_ALREADY_ENLISTED";
        case 0x4d:
LAB_00720225:
          return "WSABASEERR";
        case 0x4e:
code_r0x00718875:
          return "WSAEINTR";
        case 0x4f:
LAB_0072022f:
          return "WSAEBADF";
        case 0x50:
LAB_00720239:
          return "WSAEACCES";
        case 0x51:
LAB_00720243:
          return "WSAEFAULT";
        case 0x52:
LAB_0072024d:
          return "WSAEINVAL";
        case 0x53:
code_r0x007188ba:
          return "WSAEMFILE";
        case 0x54:
LAB_00720257:
          return "WSAEWOULDBLOCK";
        case 0x55:
LAB_00720261:
          return "WSAEINPROGRESS";
        case 0x56:
LAB_0072026b:
          return "WSAEALREADY";
        case 0x57:
code_r0x007188e5:
          return "WSAENOTSOCK";
        case 0x58:
LAB_00720275:
          return "WSAEDESTADDRREQ";
        case 0x59:
LAB_0072027f:
          return "WSAEMSGSIZE";
        case 0x5a:
LAB_00720289:
          return "WSAEPROTOTYPE";
        case 0x5b:
LAB_00720293:
          return "WSAENOPROTOOPT";
        case 0x5c:
LAB_0072029d:
          return "WSAEPROTONOSUPPORT";
        case 0x5d:
LAB_007202a7:
          return "WSAESOCKTNOSUPPORT";
        case 0x5e:
LAB_007202b1:
          return "WSAEOPNOTSUPP";
        case 0x5f:
LAB_007202bb:
          return "WSAEPFNOSUPPORT";
        case 0x60:
LAB_007202c5:
          return "WSAEAFNOSUPPORT";
        case 0x61:
LAB_007202cf:
          return "WSAEADDRINUSE";
        case 0x62:
LAB_007202d9:
          return "WSAEADDRNOTAVAIL";
        case 99:
LAB_007202e3:
          return "WSAENETDOWN";
        case 100:
LAB_007202ed:
          return "WSAENETUNREACH";
        case 0x65:
LAB_007202f7:
          return "WSAENETRESET";
        case 0x66:
LAB_00720301:
          return "WSAECONNABORTED";
        case 0x67:
LAB_0072030b:
          return "WSAECONNRESET";
        case 0x68:
LAB_00720315:
          return "WSAENOBUFS";
        case 0x69:
LAB_0072031f:
          return "WSAEISCONN";
        case 0x6a:
LAB_00720329:
          return "WSAENOTCONN";
        case 0x6b:
LAB_00720333:
          return "WSAESHUTDOWN";
        case 0x6c:
LAB_0072033d:
          return "WSAETOOMANYREFS";
        case 0x6d:
LAB_00720347:
          return "WSAETIMEDOUT";
        case 0x6e:
LAB_00720351:
          return "WSAECONNREFUSED";
        case 0x6f:
LAB_0072035b:
          return "WSAELOOP";
        case 0x70:
LAB_00720365:
          return "WSAENAMETOOLONG";
        case 0x71:
LAB_0072036f:
          return "WSAEHOSTDOWN";
        case 0x72:
LAB_00720379:
          return "WSAEHOSTUNREACH";
        case 0x73:
LAB_00720383:
          return "WSAENOTEMPTY";
        case 0x74:
LAB_0072038d:
          return "WSAEPROCLIM";
        case 0x75:
LAB_00720397:
          return "WSAEUSERS";
        case 0x76:
LAB_007203a1:
          return "WSAEDQUOT";
        case 0x77:
LAB_007203ab:
          return "WSAESTALE";
        case 0x78:
LAB_007203b5:
          return "WSAEREMOTE";
        }
      }
    }
    else if (param_1 < 0x32d8) {
      if (param_1 == 0x32d7) {
LAB_00720731:
        return "ERROR_IPSEC_DEFAULT_QM_POLICY_NOT_FOUND";
      }
      if (param_1 < 0x2b0a) {
        if (param_1 == 0x2b09) goto LAB_007205c8;
        if (param_1 < 0x2afb) {
          if (param_1 == 0x2afa) goto LAB_00720527;
          if (param_1 < 0x277b) {
            if (param_1 == 0x277a) goto LAB_007204b6;
            if (param_1 == 0x276c) goto LAB_007204ac;
            if (param_1 == 0x276d) goto LAB_007204a2;
            if (param_1 == 0x2775) goto LAB_00720498;
            if (param_1 == 0x2776) goto LAB_0072048e;
            if (param_1 == 0x2777) goto LAB_00720484;
            if (param_1 == 0x2778) goto LAB_0072047a;
            if (param_1 == 0x2779) goto code_r0x00720470;
          }
          else {
            if (param_1 == 0x277b) goto LAB_0072051d;
            if (param_1 == 0x277c) goto LAB_00720513;
            if (param_1 == 0x277d) goto LAB_00720509;
            if (param_1 == 0x277e) goto LAB_007204ff;
            if (param_1 == 0x277f) goto LAB_007204f5;
            if (param_1 == 0x2780) goto LAB_007204eb;
            if (param_1 == 0x2af9) goto LAB_007204e1;
          }
        }
        else {
          switch(param_1) {
          case 0x2afb:
            goto LAB_00720546;
          case 0x2afc:
code_r0x00718950:
            return "WSANO_DATA";
          case 0x2afd:
            goto LAB_00720550;
          case 0x2afe:
            goto LAB_0072055a;
          case 0x2aff:
            goto LAB_00720564;
          case 0x2b00:
            goto LAB_0072056e;
          case 0x2b01:
            goto LAB_00720578;
          case 0x2b02:
            goto LAB_00720582;
          case 0x2b03:
            goto LAB_0072058c;
          case 0x2b04:
            goto LAB_00720596;
          case 0x2b05:
            goto LAB_007205a0;
          case 0x2b06:
            goto LAB_007205aa;
          case 0x2b07:
            goto LAB_007205b4;
          case 0x2b08:
            goto LAB_007205be;
          }
        }
      }
      else if (param_1 < 0x32c9) {
        if (param_1 == 13000) goto LAB_00720686;
        switch(param_1) {
        case 0x2b0a:
          goto LAB_007205fa;
        case 0x2b0b:
          goto LAB_00720604;
        case 0x2b0c:
          goto LAB_0072060e;
        case 0x2b0d:
          goto LAB_00720618;
        case 0x2b0e:
          goto LAB_00720622;
        case 0x2b0f:
          goto LAB_0072062c;
        case 0x2b10:
          goto LAB_00720636;
        case 0x2b11:
          goto LAB_00720640;
        case 0x2b12:
          goto LAB_0072064a;
        case 0x2b13:
          goto LAB_00720654;
        case 0x2b14:
          goto LAB_0072065e;
        case 0x2b15:
          goto LAB_00720668;
        case 0x2b16:
          goto LAB_00720672;
        case 0x2b17:
          goto LAB_0072067c;
        }
      }
      else {
        switch(param_1) {
        case 0x32c9:
          goto LAB_007206a5;
        case 0x32ca:
          goto LAB_007206af;
        case 0x32cb:
          goto LAB_007206b9;
        case 0x32cc:
          goto LAB_007206c3;
        case 0x32cd:
          goto LAB_007206cd;
        case 0x32ce:
          goto LAB_007206d7;
        case 0x32cf:
          goto LAB_007206e1;
        case 0x32d0:
          goto LAB_007206eb;
        case 0x32d1:
          goto LAB_007206f5;
        case 0x32d2:
          goto LAB_007206ff;
        case 0x32d3:
          goto LAB_00720709;
        case 0x32d4:
          goto LAB_00720713;
        case 0x32d5:
          goto LAB_0072071d;
        case 0x32d6:
          goto LAB_00720727;
        }
      }
    }
    else if (param_1 < 0x35ff) {
      if (param_1 == 0x35fe) goto LAB_007208d8;
      if (param_1 < 0x35ef) {
        if (param_1 == 0x35ee) goto LAB_0072082d;
        if (param_1 < 0x32e0) {
          if (param_1 == 0x32df) goto LAB_007207cd;
          if (param_1 == 0x32d8) goto LAB_007207c3;
          if (param_1 == 0x32d9) goto LAB_007207b9;
          if (param_1 == 0x32da) goto LAB_007207af;
          if (param_1 == 0x32db) goto LAB_007207a5;
          if (param_1 == 0x32dc) goto LAB_0072079b;
          if (param_1 == 0x32dd) goto LAB_00720791;
          if (param_1 == 0x32de) goto code_r0x00720787;
        }
        else {
          if (param_1 == 0x35e8) goto LAB_00720823;
          if (param_1 == 0x35e9) goto LAB_00720819;
          if (param_1 == 0x35ea) goto LAB_0072080f;
          if (param_1 == 0x35eb) goto LAB_00720805;
          if (param_1 == 0x35ec) goto LAB_007207fb;
          if (param_1 == 0x35ed) goto code_r0x007207f1;
        }
      }
      else {
        switch(param_1) {
        case 0x35ef:
          goto LAB_0072084c;
        case 0x35f0:
          goto LAB_00720856;
        case 0x35f1:
          goto LAB_00720860;
        case 0x35f2:
          goto LAB_0072086a;
        case 0x35f3:
          goto LAB_00720874;
        case 0x35f4:
          goto LAB_0072087e;
        case 0x35f5:
          goto LAB_00720888;
        case 0x35f6:
          goto LAB_00720892;
        case 0x35f7:
          goto LAB_0072089c;
        case 0x35f8:
          goto LAB_007208a6;
        case 0x35f9:
          goto LAB_007208b0;
        case 0x35fa:
          goto LAB_007208ba;
        case 0x35fb:
          goto LAB_007208c4;
        case 0x35fc:
          goto LAB_007208ce;
        }
      }
    }
    else {
      switch(param_1) {
      case 0x3600:
        goto LAB_007208f7;
      case 0x3601:
        goto LAB_00720901;
      case 0x3602:
        goto LAB_0072090b;
      case 0x3603:
        goto LAB_00720915;
      case 0x3604:
        goto LAB_0072091f;
      case 0x3605:
        goto LAB_00720929;
      case 0x3606:
        goto LAB_00720933;
      case 0x3607:
        goto LAB_0072093d;
      case 0x3608:
        goto LAB_00720947;
      case 0x3609:
        goto LAB_00720951;
      case 0x360a:
        goto LAB_0072095b;
      case 0x360b:
        goto LAB_00720965;
      case 0x360c:
        goto LAB_0072096f;
      case 0x360d:
        goto LAB_00720979;
      case 0x360e:
        goto LAB_00720983;
      case 0x360f:
        goto LAB_0072098d;
      case 0x3610:
        goto LAB_00720997;
      case 0x3611:
        goto LAB_007209a1;
      case 0x3612:
        goto LAB_007209ab;
      case 0x3613:
        goto LAB_007209b5;
      case 0x3614:
        goto LAB_007209bf;
      case 0x3615:
        goto LAB_007209c9;
      case 0x3616:
        goto LAB_007209d3;
      case 0x3617:
        goto LAB_007209dd;
      case 0x3618:
        goto LAB_007209e7;
      case 0x3619:
        goto LAB_007209f1;
      case 0x361a:
        goto LAB_007209fb;
      case 0x361b:
        goto LAB_00720a05;
      case 0x361c:
        goto LAB_00720a0f;
      }
    }
  }
  else if (param_1 < 0x36b1) {
    if (param_1 == 14000) {
LAB_00720b77:
      return "ERROR_SXS_SECTION_NOT_FOUND";
    }
    switch(param_1) {
    case 0x361e:
LAB_00720a4b:
      return "ERROR_IPSEC_IKE_FAILQUERYSSP";
    case 0x361f:
LAB_00720a55:
      return "ERROR_IPSEC_IKE_SRVACQFAIL";
    case 0x3620:
LAB_00720a5f:
      return "ERROR_IPSEC_IKE_SRVQUERYCRED";
    case 0x3621:
LAB_00720a69:
      return "ERROR_IPSEC_IKE_GETSPIFAIL";
    case 0x3622:
LAB_00720a73:
      return "ERROR_IPSEC_IKE_INVALID_FILTER";
    case 0x3623:
LAB_00720a7d:
      return "ERROR_IPSEC_IKE_OUT_OF_MEMORY";
    case 0x3624:
LAB_00720a87:
      return "ERROR_IPSEC_IKE_ADD_UPDATE_KEY_FAILED";
    case 0x3625:
LAB_00720a91:
      return "ERROR_IPSEC_IKE_INVALID_POLICY";
    case 0x3626:
LAB_00720a9b:
      return "ERROR_IPSEC_IKE_UNKNOWN_DOI";
    case 0x3627:
LAB_00720aa5:
      return "ERROR_IPSEC_IKE_INVALID_SITUATION";
    case 0x3628:
LAB_00720aaf:
      return "ERROR_IPSEC_IKE_DH_FAILURE";
    case 0x3629:
LAB_00720ab9:
      return "ERROR_IPSEC_IKE_INVALID_GROUP";
    case 0x362a:
LAB_00720ac3:
      return "ERROR_IPSEC_IKE_ENCRYPT";
    case 0x362b:
LAB_00720acd:
      return "ERROR_IPSEC_IKE_DECRYPT";
    case 0x362c:
LAB_00720ad7:
      return "ERROR_IPSEC_IKE_POLICY_MATCH";
    case 0x362d:
LAB_00720ae1:
      return "ERROR_IPSEC_IKE_UNSUPPORTED_ID";
    case 0x362e:
LAB_00720aeb:
      return "ERROR_IPSEC_IKE_INVALID_HASH";
    case 0x362f:
LAB_00720af5:
      return "ERROR_IPSEC_IKE_INVALID_HASH_ALG";
    case 0x3630:
LAB_00720aff:
      return "ERROR_IPSEC_IKE_INVALID_HASH_SIZE";
    case 0x3631:
LAB_00720b09:
      return "ERROR_IPSEC_IKE_INVALID_ENCRYPT_ALG";
    case 0x3632:
LAB_00720b13:
      return "ERROR_IPSEC_IKE_INVALID_AUTH_ALG";
    case 0x3633:
LAB_00720b1d:
      return "ERROR_IPSEC_IKE_INVALID_SIG";
    case 0x3634:
LAB_00720b27:
      return "ERROR_IPSEC_IKE_LOAD_FAILED";
    case 0x3635:
LAB_00720b31:
      return "ERROR_IPSEC_IKE_RPC_DELETE";
    case 0x3636:
LAB_00720b3b:
      return "ERROR_IPSEC_IKE_BENIGN_REINIT";
    case 0x3637:
LAB_00720b45:
      return "ERROR_IPSEC_IKE_INVALID_RESPONDER_LIFETIME_NOTIFY";
    case 0x3639:
LAB_00720b4f:
      return "ERROR_IPSEC_IKE_INVALID_CERT_KEYLEN";
    case 0x363a:
LAB_00720b59:
      return "ERROR_IPSEC_IKE_MM_LIMIT";
    case 0x363b:
LAB_00720b63:
      return "ERROR_IPSEC_IKE_NEGOTIATION_DISABLED";
    case 0x363c:
LAB_00720b6d:
      return "ERROR_IPSEC_IKE_NEG_STATUS_END";
    }
  }
  else if (param_1 < 0x30201) {
    if (param_1 == 0x30200) {
      return "STG_S_CONVERTED";
    }
    switch(param_1) {
    case 0x36b1:
LAB_00720ba9:
      return "ERROR_SXS_CANT_GEN_ACTCTX";
    case 0x36b2:
LAB_00720bb3:
      return "ERROR_SXS_INVALID_ACTCTXDATA_FORMAT";
    case 0x36b3:
LAB_00720bbd:
      return "ERROR_SXS_ASSEMBLY_NOT_FOUND";
    case 0x36b4:
LAB_00720bc7:
      return "ERROR_SXS_MANIFEST_FORMAT_ERROR";
    case 0x36b5:
LAB_00720bd1:
      return "ERROR_SXS_MANIFEST_PARSE_ERROR";
    case 0x36b6:
LAB_00720bdb:
      return "ERROR_SXS_ACTIVATION_CONTEXT_DISABLED";
    case 0x36b7:
      goto LAB_00720be5;
    case 0x36b8:
      goto LAB_00720bef;
    case 0x36b9:
      goto LAB_00720bf9;
    case 0x36ba:
      goto LAB_00720c03;
    case 0x36bb:
      goto LAB_00720c0d;
    case 0x36bc:
      goto LAB_00720c17;
    case 0x36bd:
      goto LAB_00720c21;
    case 0x36be:
      goto LAB_00720c2b;
    case 0x36bf:
      goto LAB_00720c35;
    case 0x36c0:
      goto LAB_00720c3f;
    case 0x36c1:
      goto LAB_00720c49;
    case 0x36c2:
      goto LAB_00720c53;
    case 0x36c3:
      goto LAB_00720c5d;
    case 0x36c4:
      goto LAB_00720c67;
    case 0x36c5:
      goto LAB_00720c71;
    case 0x36c6:
      goto LAB_00720c7b;
    case 0x36c7:
      goto LAB_00720c85;
    case 0x36c8:
      goto LAB_00720c8f;
    case 0x36c9:
      goto LAB_00720c99;
    case 0x36ca:
      goto LAB_00720ca3;
    case 0x36cb:
      goto LAB_00720cad;
    case 0x36cc:
      goto LAB_00720cb7;
    case 0x36cd:
      goto LAB_00720cc1;
    case 0x36ce:
      goto LAB_00720ccb;
    case 0x36cf:
      goto LAB_00720cd5;
    case 0x36d0:
      goto LAB_00720cdf;
    case 0x36d1:
      goto LAB_00720ce9;
    case 0x36d2:
      goto LAB_00720cf3;
    case 0x36d3:
      goto LAB_00720cfd;
    case 0x36d4:
      goto LAB_00720d07;
    case 0x36d5:
      goto LAB_00720d11;
    case 0x36d6:
      goto LAB_00720d1b;
    case 0x36d7:
      goto LAB_00720d25;
    case 0x36d8:
      goto LAB_00720d2f;
    case 0x36d9:
      goto LAB_00720d39;
    case 0x36da:
      goto LAB_00720d43;
    case 0x36db:
      goto LAB_00720d4d;
    case 0x36dc:
      goto LAB_00720d57;
    case 0x36dd:
      goto LAB_00720d61;
    case 0x36de:
      goto LAB_00720d6b;
    case 0x36df:
      goto LAB_00720d75;
    case 0x36e0:
      goto LAB_00720d7f;
    case 0x36e1:
      goto LAB_00720d89;
    case 0x36e2:
      goto LAB_00720d93;
    case 0x36e3:
      goto LAB_00720d9d;
    case 0x36e4:
      goto LAB_00720da7;
    case 0x36e5:
      goto LAB_00720db1;
    case 0x36e6:
      goto LAB_00720dbb;
    case 0x36e7:
      goto LAB_00720dc5;
    case 0x36e8:
      goto LAB_00720dcf;
    case 0x36e9:
      goto LAB_00720dd9;
    case 0x36ea:
      goto LAB_00720de3;
    case 0x36eb:
      goto LAB_00720ded;
    case 0x36ec:
      goto LAB_00720df7;
    case 0x36ed:
      goto LAB_00720e01;
    case 0x36ee:
      goto LAB_00720e0b;
    case 0x36ef:
      goto LAB_00720e15;
    case 0x36f0:
      goto code_r0x00720e1f;
    case 0x36f1:
      goto LAB_00720e29;
    case 0x36f2:
      goto LAB_00720e33;
    case 0x36f3:
      goto LAB_00720e3d;
    case 0x36f4:
      goto LAB_00720e47;
    case 0x36f5:
      goto LAB_00720e51;
    case 0x36f6:
      goto LAB_00720e5b;
    case 0x36f7:
      goto LAB_00720e65;
    case 0x36f8:
      goto LAB_00720e6f;
    case 0x36f9:
      goto LAB_00720e79;
    case 0x36fa:
      goto LAB_00720e83;
    case 0x36fb:
      goto LAB_00720e8d;
    case 0x36fc:
      goto LAB_00720e97;
    case 0x36fd:
      goto LAB_00720ea1;
    case 0x36fe:
      goto LAB_00720eab;
    case 0x36ff:
      goto LAB_00720eb5;
    case 0x3700:
      goto LAB_00720ebf;
    }
  }
  else if (param_1 < 0x40251) {
    if (param_1 == 0x40250) {
      return "VFW_S_RESOURCE_NOT_NEEDED";
    }
    if (param_1 < 0x40151) {
      if (param_1 == 0x40150) {
        return "REGDB_S_FIRST";
      }
      if (param_1 < 0x40011) {
        if (param_1 == 0x40010) {
          return "WBEM_S_PARTIAL_RESULTS";
        }
        if (param_1 < 0x40003) {
          if (param_1 == 0x40002) {
            return "OLE_S_MAC_CLIPFORMAT & MS_S_NOUPDATE & WBEM_S_RESET_TO_DEFAULT";
          }
          if (param_1 < 0x30206) {
            if (param_1 == 0x30205) {
              return "STG_S_CONSOLIDATIONFAILED";
            }
            if (param_1 == 0x30201) {
              return "STG_S_BLOCK";
            }
            if (param_1 == 0x30202) {
              return "STG_S_RETRYNOW";
            }
            if (param_1 == 0x30203) {
              return "STG_S_MONITORING";
            }
            if (param_1 == 0x30204) {
              return "STG_S_MULTIPLEOPENS";
            }
          }
          else {
            if (param_1 == 0x30206) {
              return "STG_S_CANNOTCONSOLIDATE";
            }
            if (param_1 == 0x40000) {
              return "OLE_S_FIRST";
            }
            if (param_1 == 0x40001) {
              return "OLE_S_STATIC & MS_S_PENDING & WBEM_S_ALREADY_EXISTS";
            }
          }
        }
        else {
          if (param_1 == 0x40003) {
            return "MS_S_ENDOFSTREAM & WBEM_S_DIFFERENT";
          }
          if (param_1 == 0x40004) {
            return "WBEM_S_TIMEDOUT";
          }
          if (param_1 == 0x40005) {
            return "WBEM_S_NO_MORE_DATA";
          }
          if (param_1 == 0x40006) {
            return "WBEM_S_OPERATION_CANCELLED";
          }
          if (param_1 == 0x40007) {
            return "WBEM_S_PENDING";
          }
          if (param_1 == 0x40008) {
            return "WBEM_S_DUPLICATE_OBJECTS";
          }
          if (param_1 == 0x40009) {
            return "WBEM_S_ACCESS_DENIED";
          }
        }
      }
      else if (param_1 < 0x40111) {
        if (param_1 == 0x40110) {
          return "CLASSFACTORY_S_FIRST";
        }
        if (param_1 == 0x40017) {
          return "WBEM_S_SOURCE_NOT_AVAILABLE";
        }
        if (param_1 == 0x400ff) {
          return "OLE_S_LAST";
        }
        if (param_1 == 0x40100) {
          return "DRAGDROP_S_FIRST";
        }
        if (param_1 == 0x40101) {
          return "DRAGDROP_S_CANCEL";
        }
        if (param_1 == 0x40102) {
          return "DRAGDROP_S_USEDEFAULTCURSORS";
        }
        if (param_1 == 0x40103) {
          return "VFW_S_NO_MORE_ITEMS";
        }
        if (param_1 == 0x4010f) {
          return "DRAGDROP_S_LAST";
        }
      }
      else {
        if (param_1 == 0x4011f) {
          return "CLASSFACTORY_S_LAST";
        }
        if (param_1 == 0x40120) {
          return "MARSHAL_S_FIRST";
        }
        if (param_1 == 0x4012f) {
          return "MARSHAL_S_LAST";
        }
        if (param_1 == 0x40130) {
          return "DATA_S_FIRST";
        }
        if (param_1 == 0x4013f) {
          return "DATA_S_LAST";
        }
        if (param_1 == 0x40140) {
          return "VIEW_S_FIRST";
        }
        if (param_1 == 0x4014f) {
          return "VIEW_S_LAST";
        }
      }
    }
    else if (param_1 < 0x401d0) {
      if (param_1 == 0x401cf) {
        return "CONVERT10_S_LAST";
      }
      if (param_1 < 0x40190) {
        if (param_1 == 0x4018f) {
          return "OLEOBJ_S_LAST";
        }
        if (param_1 < 0x40180) {
          if (param_1 == 0x4017f) {
            return "CACHE_S_LAST";
          }
          if (param_1 == 0x4015f) {
            return "REGDB_S_LAST";
          }
          if (param_1 == 0x40170) {
            return "CACHE_S_FIRST";
          }
          if (param_1 == 0x40171) {
            return "CACHE_S_SAMECACHE";
          }
          if (param_1 == 0x40172) {
            return "CACHE_S_SOMECACHES_NOTUPDATED";
          }
        }
        else {
          if (param_1 == 0x40180) {
            return "OLEOBJ_S_FIRST";
          }
          if (param_1 == 0x40181) {
            return "OLEOBJ_S_CANNOT_DOVERB_NOW";
          }
          if (param_1 == 0x40182) {
            return "OLEOBJ_S_INVALIDHWND";
          }
        }
      }
      else {
        if (param_1 == 0x40190) {
          return "CLIENTSITE_S_FIRST";
        }
        if (param_1 == 0x4019f) {
          return "CLIENTSITE_S_LAST";
        }
        if (param_1 == 0x401a0) {
          return "INPLACE_S_FIRST";
        }
        if (param_1 == 0x401af) {
          return "INPLACE_S_LAST";
        }
        if (param_1 == 0x401b0) {
          return "ENUM_S_FIRST";
        }
        if (param_1 == 0x401bf) {
          return "ENUM_S_LAST";
        }
        if (param_1 == 0x401c0) {
          return "CONVERT10_S_FIRST";
        }
      }
    }
    else if (param_1 < 0x401e8) {
      if (param_1 == 0x401e7) {
        return "MK_S_MONIKERALREADYREGISTERED";
      }
      if (param_1 == 0x401d0) {
        return "CLIPBRD_S_FIRST";
      }
      if (param_1 == 0x401df) {
        return "CLIPBRD_S_LAST";
      }
      if (param_1 == 0x401e0) {
        return "MK_S_FIRST";
      }
      if (param_1 == 0x401e2) {
        return "MK_S_REDUCED_TO_SELF";
      }
      if (param_1 == 0x401e4) {
        return "MK_S_ME";
      }
      if (param_1 == 0x401e5) {
        return "MK_S_HIM";
      }
      if (param_1 == 0x401e6) {
        return "MK_S_US";
      }
    }
    else {
      if (param_1 == 0x401ef) {
        return "MK_S_LAST";
      }
      if (param_1 == 0x40202) {
        return "EVENT_S_NOSUBSCRIBERS";
      }
      if (param_1 == 0x4022d) {
        return "VFW_S_DUPLICATE_NAME";
      }
      if (param_1 == 0x40237) {
        return "VFW_S_STATE_INTERMEDIATE";
      }
      if (param_1 == 0x40242) {
        return "VFW_S_PARTIAL_RENDER";
      }
      if (param_1 == 0x40245) {
        return "VFW_S_SOME_DATA_IGNORED";
      }
      if (param_1 == 0x40246) {
        return "VFW_S_CONNECTIONS_DEFERRED";
      }
    }
  }
  else if (param_1 < 0x4d00b) {
    if (param_1 == 0x4d00a) {
      return "XACT_S_LOCALLY_OK";
    }
    if (param_1 < 0x41304) {
      if (param_1 == 0x41303) {
        return "SCHED_S_TASK_HAS_NOT_RUN";
      }
      if (param_1 < 0x40271) {
        if (param_1 == 0x40270) {
          return "VFW_S_NO_STOP_TIME";
        }
        if (param_1 < 0x40261) {
          if (param_1 == 0x40260) {
            return "VFW_S_ESTIMATED";
          }
          if (param_1 == 0x40254) {
            return "VFW_S_MEDIA_TYPE_IGNORED";
          }
          if (param_1 == 0x40257) {
            return "VFW_S_VIDEO_NOT_RENDERED";
          }
          if (param_1 == 0x40258) {
            return "VFW_S_AUDIO_NOT_RENDERED";
          }
          if (param_1 == 0x4025a) {
            return "VFW_S_RPZA";
          }
        }
        else {
          if (param_1 == 0x40263) {
            return "VFW_S_RESERVED";
          }
          if (param_1 == 0x40267) {
            return "VFW_S_STREAM_OFF";
          }
          if (param_1 == 0x40268) {
            return "VFW_S_CANT_CUE";
          }
        }
      }
      else {
        if (param_1 == 0x4027e) {
          return "VFW_S_NOPREVIEWPIN";
        }
        if (param_1 == 0x40280) {
          return "VFW_S_DVD_NON_ONE_SEQUENTIAL";
        }
        if (param_1 == 0x4028c) {
          return "VFW_S_DVD_CHANNEL_CONTENTS_NOT_AVAILABLE";
        }
        if (param_1 == 0x4028d) {
          return "VFW_S_DVD_NOT_ACCURATE";
        }
        if (param_1 == 0x41300) {
          return "SCHED_S_TASK_READY";
        }
        if (param_1 == 0x41301) {
          return "SCHED_S_TASK_RUNNING";
        }
        if (param_1 == 0x41302) {
          return "SCHED_S_TASK_DISABLED";
        }
      }
    }
    else if (param_1 < 0x4d003) {
      if (param_1 == 0x4d002) {
        return "XACT_S_READONLY";
      }
      if (param_1 == 0x41304) {
        return "SCHED_S_TASK_NO_MORE_RUNS";
      }
      if (param_1 == 0x41305) {
        return "SCHED_S_TASK_NOT_SCHEDULED";
      }
      if (param_1 == 0x41306) {
        return "SCHED_S_TASK_TERMINATED";
      }
      if (param_1 == 0x41307) {
        return "SCHED_S_TASK_NO_VALID_TRIGGERS";
      }
      if (param_1 == 0x41308) {
        return "SCHED_S_EVENT_TRIGGER";
      }
      if (param_1 == 0x4d000) {
        return "XACT_S_FIRST";
      }
      if (param_1 == 0x4d001) {
        return "XACT_S_DEFECT";
      }
    }
    else {
      if (param_1 == 0x4d003) {
        return "XACT_S_SOMENORETAIN";
      }
      if (param_1 == 0x4d004) {
        return "XACT_S_OKINFORM";
      }
      if (param_1 == 0x4d005) {
        return "XACT_S_MADECHANGESCONTENT";
      }
      if (param_1 == 0x4d006) {
        return "XACT_S_MADECHANGESINFORM";
      }
      if (param_1 == 0x4d007) {
        return "XACT_S_ALLNORETAIN";
      }
      if (param_1 == 0x4d008) {
        return "XACT_S_ABORTING";
      }
      if (param_1 == 0x4d009) {
        return "XACT_S_SINGLEPHASE";
      }
    }
  }
  else if (param_1 < 0x15000b) {
    if (param_1 == 0x15000a) {
      return "DV_HALFDUPLEX";
    }
    if (param_1 < 0x90315) {
      if (param_1 == 0x90314) {
        return "SEC_I_COMPLETE_AND_CONTINUE";
      }
      if (param_1 == 0x4d010) {
        return "XACT_S_LAST";
      }
      if (param_1 == 0x4e000) {
        return "CONTEXT_S_FIRST";
      }
      if (param_1 == 0x4e02f) {
        return "CONTEXT_S_LAST";
      }
      if (param_1 == 0x80012) {
        return "CO_S_NOTALLINTERFACES";
      }
      if (param_1 == 0x80013) {
        return "CO_S_MACHINENAMENOTFOUND";
      }
      if (param_1 == 0x90312) {
        return "SEC_I_CONTINUE_NEEDED";
      }
      if (param_1 == 0x90313) {
        return "SEC_I_COMPLETE_NEEDED";
      }
    }
    else {
      if (param_1 == 0x90315) {
        return "SEC_I_LOCAL_LOGON";
      }
      if (param_1 == 0x90317) {
        return "SEC_I_CONTEXT_EXPIRED";
      }
      if (param_1 == 0x90320) {
        return "SEC_I_INCOMPLETE_CREDENTIALS";
      }
      if (param_1 == 0x90321) {
        return "SEC_I_RENEGOTIATE";
      }
      if (param_1 == 0x90323) {
        return "SEC_I_NO_LSA_CONTEXT";
      }
      if (param_1 == 0x91012) {
        return "CRYPT_I_NEW_PROTECTION_REQUIRED";
      }
      if (param_1 == 0x150005) {
        return "DV_FULLDUPLEX";
      }
    }
  }
  else if (param_1 < 0x8781203) {
    if (param_1 == 0x8781202) {
      return "DMUS_S_END";
    }
    if (param_1 == 0x150010) {
      return "DV_PENDING";
    }
    if (param_1 == 0x876086f) {
      return "D3DOK_NOAUTOGEN";
    }
    if (param_1 == 0x878000a) {
      return "DS_NO_VIRTUALIZATION";
    }
    if (param_1 == 0x8781091) {
      return "DMUS_S_PARTIALLOAD";
    }
    if (param_1 == 0x8781092) {
      return "DMUS_S_PARTIALDOWNLOAD";
    }
    if (param_1 == 0x8781200) {
      return "DMUS_S_REQUEUE";
    }
    if (param_1 == 0x8781201) {
      return "DMUS_S_FREE";
    }
  }
  else {
    if (param_1 == 0x8781210) {
      return "DMUS_S_STRING_TRUNCATED";
    }
    if (param_1 == 0x8781211) {
      return "DMUS_S_LAST_TOOL";
    }
    if (param_1 == 0x8781212) {
      return "DMUS_S_OVER_CHORD";
    }
    if (param_1 == 0x8781213) {
      return "DMUS_S_UP_OCTAVE";
    }
    if (param_1 == 0x8781214) {
      return "DMUS_S_DOWN_OCTAVE";
    }
    if (param_1 == 0x8781215) {
      return "DMUS_S_NOBUFFERCONTROL";
    }
    if (param_1 == 0x8781216) {
      return "DMUS_S_GARBAGE_COLLECTED";
    }
  }
  return "Unknown";
}

